#pragma once

//#include <windows.h>
#include <d3d11.h>

#if !defined _MSC_VER
#define FORCEINLINE	inline
// idk if this is good tbh
#define ARRAYSIZE(a) \
  ((sizeof(a) / sizeof(*(a))) / \
  static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))
#endif

#include <filesystem>
#include <iostream>
#include <unordered_map>
#include <set>
#include <unordered_set>
//#include <sysinfoapi.h>
#include <vector>
#include <array>
#include <cstdint>
#include <string>
#include <fstream>
#include <regex>
#include <charconv>
#include <immintrin.h>

#include <rapidcsv.h>

// Use 64bit size types for RapidJSON
#define RAPIDJSON_NO_SIZETYPEDEFINE
namespace rapidjson { typedef ::std::size_t SizeType; }

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/error/en.h>

#include "common/decls.h"
#include "common/const.h"

#include "math/common.h"

#include "logic/rmem.h"
#include "logic/rtech.h"

#define _Printf_format_string_

#include "utils/binaryio.h"
#include "utils/utils.h"
#include "utils/strutils.h"
#include "utils/jsonutils.h"
#include "utils/logger.h"

#define UNUSED(x)	(void)(x)
