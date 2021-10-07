#pragma once

#include <array>
#include <stdint.h>
#include <stdio.h>
#include <corecrt_io.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <winternl.h>
#include <vector>
#include <string>
#include <memory>
#include <direct.h>
#include <map>
#include <chrono>
#include <functional>
#include <algorithm>
#include <cctype>
#include <regex>
#include <mutex>
#include <ctime>
#include <math.h>
#include <unordered_map>
#include <deque>

using namespace std::literals;

#pragma warning(disable: 6011)
#pragma warning(disable: 6054)
#pragma warning(disable: 26451)
#pragma warning(disable: 26812)
#pragma warning(disable: 28182)

#include "utils/hook.hpp"
#include "utils/string.hpp"

#include "game/structs.hpp"
#include "game/functions.hpp"
#include "game/symbols.hpp"

#include "gsc/functions.hpp"
#include "gsc/methods.hpp"
#include "gsc/script.hpp"