// BgLabelControl.cpp
#include "pch.h"
#include "BgLabelControl.h"
#include "BgLabelControl.g.cpp"

namespace winrt::RuntimeComponent1::implementation
{
    Windows::UI::Xaml::DependencyProperty BgLabelControl::m_labelProperty =
        Windows::UI::Xaml::DependencyProperty::Register(
            L"Label",
            winrt::xaml_typename<winrt::hstring>(),
            winrt::xaml_typename<RuntimeComponent1::BgLabelControl>(),
            Windows::UI::Xaml::PropertyMetadata{ winrt::box_value(L"default label"), Windows::UI::Xaml::PropertyChangedCallback{ &BgLabelControl::OnLabelChanged } }
    );

    void BgLabelControl::OnLabelChanged(Windows::UI::Xaml::DependencyObject const& d, Windows::UI::Xaml::DependencyPropertyChangedEventArgs const& /* e */)
    {
        if (RuntimeComponent1::BgLabelControl theControl{ d.try_as<RuntimeComponent1::BgLabelControl>() })
        {
            // Call members of the projected type via theControl.

            RuntimeComponent1::implementation::BgLabelControl* ptr{ winrt::get_self<RuntimeComponent1::implementation::BgLabelControl>(theControl) };
            // Call members of the implementation type via ptr.
        }
    }
}