#include "pch.h"
#include "SampleComponent.h"
#include "SampleComponent.g.cpp"
#include <winrt/Windows.Security.ExchangeActiveSyncProvisioning.h>

using namespace winrt::Windows::Security::ExchangeActiveSyncProvisioning;

namespace winrt::DeviceInfoCPP::implementation
{
    winrt::hstring SampleComponent::DeviceInfo()
    {
        auto info = EasClientDeviceInformation();
        return info.SystemProductName();
    }

    void SampleComponent::DeviceInfo(winrt::hstring /* value */)
    {
        throw hresult_not_implemented();
    }
}
