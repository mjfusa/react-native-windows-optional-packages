// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "pch.h"
#include <winrt/Windows.UI.Xaml.Media.h>

#include "MyUserControlViewManagerCpp.h"
#include "JSValueReader.h"
#include "JSValueXaml.h"
#include "NativeModules.h"

#include "MyUserControl.h"
#include "DebugHelpers.h"

using namespace winrt;
using namespace Microsoft::ReactNative;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Controls;

namespace winrt::NativeUIModule::implementation {

MyUserControlViewManagerCpp::MyUserControlViewManagerCpp() {}

// IViewManager
hstring MyUserControlViewManagerCpp::Name() noexcept {
  return L"MyUserControl";
}

FrameworkElement MyUserControlViewManagerCpp::CreateView() noexcept {
  auto const &view = winrt::NativeUIModule::MyUserControl();

  view.RegisterPropertyChangedCallback(
      winrt::NativeUIModule::MyUserControl::LabelProperty(),
      [this](
          winrt::Windows::UI::Xaml::DependencyObject obj, winrt::Windows::UI::Xaml::DependencyProperty prop) noexcept {
        if (auto c = obj.try_as<winrt::NativeUIModule::MyUserControl>()) {
          ReactContext().DispatchEvent(
              c,
              L"topLabelChanged",
              [ this, c ](winrt::Microsoft::ReactNative::IJSValueWriter const &eventDataWriter) noexcept {
                eventDataWriter.WriteString(c.Label());
              });
        }
      });

  return view;
}

// IViewManagerWithReactContext
IReactContext MyUserControlViewManagerCpp::ReactContext() noexcept {
  return m_reactContext;
}

void MyUserControlViewManagerCpp::ReactContext(IReactContext reactContext) noexcept {
  m_reactContext = reactContext;
}

// IViewManagerWithNativeProperties
IMapView<hstring, ViewManagerPropertyType> MyUserControlViewManagerCpp::NativeProps() noexcept {
  auto nativeProps = winrt::single_threaded_map<hstring, ViewManagerPropertyType>();

  nativeProps.Insert(L"label", ViewManagerPropertyType::String);
  nativeProps.Insert(L"color", ViewManagerPropertyType::Color);
  nativeProps.Insert(L"backgroundColor", ViewManagerPropertyType::Color);

  return nativeProps.GetView();
}

void MyUserControlViewManagerCpp::UpdateProperties(
    FrameworkElement const &view,
    IJSValueReader const &propertyMapReader) noexcept {
  if (auto control = view.try_as<winrt::NativeUIModule::MyUserControl>()) {
    JSValueObject propertyMap = JSValueObject::ReadFrom(propertyMapReader);

    for (auto const &pair : propertyMap) {
      auto const &propertyName = pair.first;
      auto const &propertyValue = pair.second;

      if (propertyName == "label") {
        if (!propertyValue.IsNull()) {
          auto value = winrt::box_value(winrt::to_hstring(propertyValue.AsString()));
          control.SetValue(winrt::NativeUIModule::MyUserControl::LabelProperty(), value);
        } else {
          control.ClearValue(winrt::NativeUIModule::MyUserControl::LabelProperty());
        }
      } else if (propertyName == "color") {
        if (auto value = propertyValue.To<Brush>()) {
          control.SetValue(Control::ForegroundProperty(), value);
        } else {
          control.ClearValue(Control::ForegroundProperty());
        }
      } else if (propertyName == "backgroundColor") {
        if (auto value = propertyValue.To<Brush>()) {
          control.SetValue(Control::BackgroundProperty(), value);
        } else {
          control.ClearValue(Control::BackgroundProperty());
        }
      }
    }
  }
}

// IViewManagerWithCommands
IMapView<hstring, int64_t> MyUserControlViewManagerCpp::Commands() noexcept {
  auto commands = winrt::single_threaded_map<hstring, int64_t>();
  commands.Insert(L"CustomCommand", 0);
  return commands.GetView();
}

void MyUserControlViewManagerCpp::DispatchCommand(
    FrameworkElement const &view,
    int64_t commandId,
    IJSValueReader const &commandArgsReader) noexcept {
  if (auto control = view.try_as<winrt::NativeUIModule::MyUserControl>()) {
    if (commandId == 0) {
      std::string arg = std::to_string(winrt::unbox_value<int64_t>(view.Tag()));
      arg.append(", \"");
      arg.append(winrt::to_string(commandArgsReader.GetString()));
      arg.append("\"");
      ::NativeUIModule::DebugWriteLine(to_string(Name()), "CustomCommand", arg);
    }
  }
}

// IViewManagerWithExportedEventTypeConstants
ConstantProviderDelegate MyUserControlViewManagerCpp::ExportedCustomBubblingEventTypeConstants() noexcept {
  return nullptr;
}

ConstantProviderDelegate MyUserControlViewManagerCpp::ExportedCustomDirectEventTypeConstants() noexcept {
  return [](winrt::Microsoft::ReactNative::IJSValueWriter const &constantWriter) {
    constantWriter.WritePropertyName(L"topLabelChanged");
    constantWriter.WriteObjectBegin();
    WriteProperty(constantWriter, L"registrationName", L"onLabelChanged");
    constantWriter.WriteObjectEnd();
  };
}

} // namespace winrt::NativeUIModule::implementation
