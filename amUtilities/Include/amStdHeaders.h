/******************************************
 * @file amStdHeaders.h
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Encapsulates the std type under the engine types
 *
 * @note
******************************************/
#pragma once

//#define EASTL

//EASTL
#ifdef EASTL

//#define EASTL_USER_CONFIG_HEADER
//#define EASTL_ASSERT
#include <EASTL/vector.h>
#include <EASTL/list.h>
#include <EASTL/map.h>
#include <EASTL/queue.h>
#include <EASTL/set.h>
#include <EASTL/unordered_map.h>
#include <EASTL/unordered_set.h>
#include <EASTL/stack.h>
#include <EASTL/deque.h>

#else

#include <vector>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>

#endif

namespace amEngineSDK {
#ifdef EASTL
  template<typename T, typename A = EASTLAllocatorType>
  using Vector = eastl::vector<T, A>;

  template<typename T, typename A = EASTLAllocatorType>
  using List = eastl::list<T, A>;

  template<typename Key, typename T, typename Compare = eastl::less<Key>, typename Allocator = EASTLAllocatorType>
  using Map = eastl::map<T, A>;

  template<typename T, typename Container = eastl::deque<T, EASTLAllocatorType, DEQUE_DEFAULT_SUBARRAY_SIZE(T)> >
  using Queue = eastl::queue<T, A>;

  template<typename Key, typename Compare = eastl::less<Key>, typename Allocator = EASTLAllocatorType>
  using Set = eastl::set<T, A>;

  template<typename Key,
    typename T,
    typename Hash = eastl::hash<Key>,
    typename Predicate = eastl::equal_to<Key>,
    typename Allocator = EASTLAllocatorType,
    bool bCacheHashCode = false>
  using UMap = eastl::unordered_map<T, A>;

  template<typename Value,
    typename Hash = eastl::hash<Value>,
    typename Predicate = eastl::equal_to<Value>,
    typename Allocator = EASTLAllocatorType,
    bool bCacheHashCode = false>
  using USet = eastl::unordered_set<T, A>;

  template<typename T, typename Container = eastl::vector<T> >
  using Stack = eastl::stack<T, A>;

  template<typename T, typename Allocator = EASTLAllocatorType, unsigned kDequeSubarraySize = DEQUE_DEFAULT_SUBARRAY_SIZE(T)>
  using Deque = eastl::deque<T, A>;

#else

  template<class _Ty, class _Alloc = std::allocator<_Ty>>
  using Vector = std::vector<_Ty, _Alloc>;

  template<class _Ty, class _Alloc = std::allocator<_Ty>>
  using List = std::list<_Ty, _Alloc>;

  template<class _Kty,
           class _Ty,
           class _Pr = less<_Kty>,
           class _Alloc = std::allocator<pair<const _Kty, _Ty>>>
  using Map = std::map<_Kty, _Ty, _Pr, _Alloc>;

  template<class _Ty, class _Container = deque<_Ty> >
  using Queue = std::queue<_Ty, _Container>;

  template<class _Kty,
           class _Pr = less<_Kty>,
           class _Alloc = std::allocator<_Kty>>
  using Set = std::set<_Kty, _Pr, _Alloc>;

  template<class _Kty,
           class _Ty,
           class _Hasher = hash<_Kty>,
           class _Keyeq = equal_to<_Kty>,
           class _Alloc = std::allocator<pair<const _Kty, _Ty>>>
  using UMap = std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq, _Alloc>;

  template<class _Kty,
           class _Hasher = hash<_Kty>,
           class _Keyeq = equal_to<_Kty>,
           class _Alloc = std::allocator<_Kty>>
  using USet = std::unordered_set<_Kty, _Hasher, _Keyeq, _Alloc>;

  template<class _Ty,
           class _Container = deque<_Ty> >
  using Stack = std::stack<_Ty, _Container>;

  template<class _Ty,
           class _Alloc = std::allocator<_Ty>>
  using Deque = std::deque<_Ty, _Alloc>;

#endif
}



