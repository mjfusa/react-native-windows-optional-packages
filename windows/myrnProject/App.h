#pragma once

#include "App.xaml.g.h"



namespace winrt::myrnProject::implementation
{
    struct App : AppT<App>
    {
        App() noexcept;
    private:
        bool App::IsPackageInstalled(std::wstring_view moduleName);
    };
} // namespace winrt::myrnProject::implementation


