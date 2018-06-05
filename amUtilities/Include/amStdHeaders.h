#pragma once

#define EASTL

//EASTL
#ifdef EASTL
#include <EASTL/vector.h>

template<typename T, typename A = eastl::allocator>;
using Vector = eastl::vector<T, A>;

#else
# include <vector>
# include <list>
# include <map>
# include <queue>
# include <set>
# include <unordered_map>
# include <unordered_set>
# include <stack>
# include <deque>

template<typename T, typename A = std::allocator<T>()>;
using Vector = std::vector<T, A>;

#endif




template <typename T>
using Vector = std::vector<T, A>;
template <typename T>
using List = std::list;
