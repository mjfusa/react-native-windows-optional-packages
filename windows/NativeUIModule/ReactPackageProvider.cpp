// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "pch.h"
#include "ReactPackageProvider.h"
#include <ModuleRegistration.h>

#include "MyUserControlViewManagerCpp.h"

using namespace winrt::Microsoft::ReactNative;

namespace winrt::NativeUIModule::implementation {

void ReactPackageProvider::CreatePackage(IReactPackageBuilder const &packageBuilder) noexcept {
  
    AddAttributedModules(packageBuilder);
  
    packageBuilder.AddViewManager(L"MyUserControlViewManagerCpp", []() { return winrt::make<MyUserControlViewManagerCpp>(); });
}

} // namespace winrt::NativeUIModule::implementation
