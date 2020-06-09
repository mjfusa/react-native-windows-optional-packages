#include "pch.h"
#include "CustomUserControlViewManager.h"

#include "JSValueReader.h"
#include "NativeModules.h"

using namespace winrt;
using namespace Microsoft::ReactNative;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Controls;

#include "winrt\RuntimeComponent1.h"

namespace winrt::NativeUICtrl::implementation {

    // IViewManager
    hstring CustomUserControlViewManager::Name() noexcept {
        return L"BgLabelControl";
    }

    FrameworkElement CustomUserControlViewManager::CreateView() noexcept {
        auto const& view = winrt::RuntimeComponent1::BgLabelControl();

        view.RegisterPropertyChangedCallback(
            winrt::RuntimeComponent1::BgLabelControl::LabelProperty(),
            [this](
                winrt::Windows::UI::Xaml::DependencyObject obj, winrt::Windows::UI::Xaml::DependencyProperty prop) noexcept {
            if (auto c = obj.try_as<winrt::RuntimeComponent1::BgLabelControl>()) {
                ReactContext().DispatchEvent(
                    c,
                    L"topLabelChanged",
                    [this, c](winrt::Microsoft::ReactNative::IJSValueWriter const& eventDataWriter) noexcept {
                    eventDataWriter.WriteString(c.Label());
                });
            }
        });

        return view;
    }

    // IViewManagerWithReactContext
    IReactContext CustomUserControlViewManager::ReactContext() noexcept {
        return m_reactContext;
    }

    void CustomUserControlViewManager::ReactContext(IReactContext reactContext) noexcept {
        m_reactContext = reactContext;
    }


    // IViewManagerWithNativeProperties
    IMapView<hstring, ViewManagerPropertyType> CustomUserControlViewManager::NativeProps() noexcept {
        auto nativeProps = winrt::single_threaded_map<hstring, ViewManagerPropertyType>();

        nativeProps.Insert(L"label", ViewManagerPropertyType::String);
        nativeProps.Insert(L"color", ViewManagerPropertyType::Color);
        nativeProps.Insert(L"backgroundColor", ViewManagerPropertyType::Color);

        return nativeProps.GetView();
    }

    void CustomUserControlViewManager::UpdateProperties(
        FrameworkElement const& view,
        IJSValueReader const& propertyMapReader) noexcept {
        if (auto control = view.try_as<winrt::RuntimeComponent1::BgLabelControl>()) {
            JSValueObject propertyMap = JSValueObject::ReadFrom(propertyMapReader);

            for (auto const& pair : propertyMap) {
                auto const& propertyName = pair.first;
                auto const& propertyValue = pair.second;

                if (propertyName == "label") {
                    if (!propertyValue.IsNull()) {
                        auto value = winrt::box_value(winrt::to_hstring(propertyValue.AsString()));
                        control.SetValue(winrt::RuntimeComponent1::BgLabelControl::LabelProperty(), value);
                    }
                    else {
                        control.ClearValue(winrt::RuntimeComponent1::BgLabelControl::LabelProperty());
                    }
                }
                else if (propertyName == "color") {
                    if (auto value = winrt::box_value(winrt::to_hstring(propertyValue.AsString()))) { // todo type fix
                        control.SetValue(Control::ForegroundProperty(), value);
                    }
                    else {
                        control.ClearValue(Control::ForegroundProperty());
                    }
                }
                else if (propertyName == "backgroundColor") {
                    if (auto value = winrt::box_value(winrt::to_hstring(propertyValue.AsString()))) { // todo type fix
                        control.SetValue(Control::BackgroundProperty(), value);
                    }
                    else {
                        control.ClearValue(Control::BackgroundProperty());
                    }
                }
            }
        }
    }

    // IViewManagerWithCommands
    IMapView<hstring, int64_t> CustomUserControlViewManager::Commands() noexcept {
        auto commands = winrt::single_threaded_map<hstring, int64_t>();
        commands.Insert(L"CustomCommand", 0);
        return commands.GetView();
    }

    void CustomUserControlViewManager::DispatchCommand(
        FrameworkElement const& view,
        int64_t commandId,
        winrt::Microsoft::ReactNative::IJSValueReader const& commandArgsReader) noexcept {
        if (auto control = view.try_as<winrt::RuntimeComponent1::BgLabelControl>()) {
            if (commandId == 0) {
                const JSValueArray& commandArgs = JSValue::ReadArrayFrom(commandArgsReader);
                // Execute command
            }
        }
    }
}
