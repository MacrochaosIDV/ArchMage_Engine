#pragma once

//#define EASTL

//EASTL
#ifdef EASTL
#define EASTL_USER_CONFIG_HEADER
//#define EASTL_ASSERT
#include <EASTL/vector.h>

template<typename T, typename A = EASTLAllocatorType>;
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

template<typename T, typename A = std::allocator<T>()>
using Vector = std::vector<T, A>;

template<typename T, typename A = std::allocator<T>()>
using List = std::list<T, A>;

template<typename T, typename A = std::allocator<T>()>
using Map = std::map<T, A>;

template<typename T, typename A = std::allocator<T>()>
using Queue = std::queue<T, A>;

template<typename T, typename A = std::allocator<T>()>
using Set = std::set<T, A>;

template<typename T, typename A = std::allocator<T>()>
using UMap = std::unordered_map<T, A>;

template<typename T, typename A = std::allocator<T>()>
using USet = std::unordered_set<T, A>;

template<typename T, typename A = std::allocator<T>()>
using Stack = std::stack<T, A>;

template<typename T, typename A = std::allocator<T>()>
using Deque = std::deque<T, A>;

#endif


