#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using Byte   = unsigned char;
using Word   = unsigned short;
using Dword  = unsigned long;
using Qword  = unsigned long long;

using String         = std::string;
using StringView     = std::string_view;
template <typename T>
using Vector         = std::vector<T>;
template <typename M, typename N>
using Map            = std::map<M, N>;
template <typename S, int N>
using Array          = std::array<S, N>;
template <typename M, typename N>
using UnorderedMap   = std::unordered_map<M, N>;
