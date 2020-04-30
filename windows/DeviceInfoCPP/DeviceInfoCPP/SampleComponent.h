#pragma once

#include "SampleComponent.g.h"

#include "NativeModules.h"

namespace winrt::DeviceInfoCPP::implementation
{
    REACT_MODULE(SampleComponent);
    struct SampleComponent : SampleComponentT<SampleComponent>
    {
        SampleComponent() = default;

        winrt::hstring DeviceInfo();
        void DeviceInfo(winrt::hstring value);
    };
}

namespace winrt::DeviceInfoCPP::factory_implementation
{
    struct SampleComponent : SampleComponentT<SampleComponent, implementation::SampleComponent>
    {
    };
}
