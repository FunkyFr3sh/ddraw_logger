// Copyright (c) 2014 Jérémy Ansel
// Licensed under the MIT license. See LICENSE.txt

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN
#define STRICT
#include <initguid.h>
#include "ddraw.h"
#include "d3d.h"

#include <string>
#include <sstream>

#include "wrapper.h"
#include "logger.h"
#include "utils.h"

// @TheRedDaemon: get return address with _ReturnAddress
#include <intrin.h>

#if defined(__GNUC__) /* wrap msvc intrinsics onto gcc builtins */
#undef  _ReturnAddress
#undef  _AddressOfReturnAddress
#define _ReturnAddress()		__builtin_return_address(0)
#define _AddressOfReturnAddress()	__builtin_frame_address (0)
#else
#pragma intrinsic(_ReturnAddress)
#endif /* __GNUC__ */