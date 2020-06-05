#include "pch.h"
#include "MyUserControl.h"
//#if __has_include("MyUserControl.g.cpp")
//#include "MyUserControl.g.cpp"
//#endif

#include "MyUserControl.g.h"
using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::NativeUIModule::implementation
{
    MyUserControl::MyUserControl()
    {
        InitializeComponent();
    }


    Windows::UI::Xaml::DependencyProperty MyUserControl::m_labelProperty =
        Windows::UI::Xaml::DependencyProperty::Register(
            L"Label",
            winrt::xaml_typename<winrt::hstring>(),
            winrt::xaml_typename<winrt::NativeUIModule::MyUserControl>(),
            Windows::UI::Xaml::PropertyMetadata{ winrt::box_value(winrt::hstring()) });

    Windows::UI::Xaml::DependencyProperty MyUserControl::LabelProperty() {
        return m_labelProperty;
    }

    hstring MyUserControl::Label() {
        return winrt::unbox_value<winrt::hstring>(GetValue(m_labelProperty));
    }

    void MyUserControl::Label(hstring const& value) {
        SetValue(m_labelProperty, winrt::box_value(value));
    }

    void MyUserControl::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
