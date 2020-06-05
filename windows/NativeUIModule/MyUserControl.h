#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "MyUserControl.g.h"

namespace winrt::NativeUIModule::implementation
{
    struct MyUserControl : MyUserControlT<MyUserControl>
    {
        MyUserControl();

        static Windows::UI::Xaml::DependencyProperty LabelProperty();

        hstring Label();
        void Label(hstring const& value);

        static void OnLabelChanged(
            Windows::UI::Xaml::DependencyObject const& d,
            Windows::UI::Xaml::DependencyPropertyChangedEventArgs const& e);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);

    private:
        static Windows::UI::Xaml::DependencyProperty m_labelProperty;
    };
}

namespace winrt::NativeUIModule::factory_implementation
{
    struct MyUserControl : MyUserControlT<MyUserControl, implementation::MyUserControl>
    {
    };
}
