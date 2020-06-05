// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include <hstring.h>

namespace NativeUIModule {

void DebugWriteLine(const std::string &name, const std::string &methodName, const std::string &arg);

void DebugWriteLine(const std::string &name, const std::string &methodName, double arg);

void DebugWriteLine(const std::string &name, const std::string &methodName);

} // namespace NativeUIModule
