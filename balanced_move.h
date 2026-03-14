#ifndef BALANCED_MOVE_H
#define BALANCED_MOVE_H

#include "list.h"
#include "vec.h"

template< class T >
Vec< List<T>* > balanced_move(Vec< List<T>* > v, size_t k) {
  size_t total = 0;
  for (size_t i = 0; i < v.s; ++i)
  {
    List<T>* cur = v[i];
    while (cur) {
      ++total;
      cur = cur->next;
    }
  }
  if (total == 0)
  {
    return Vec<List<T>*>();
  }
  size_t num_lists = (total + k - 1) / k;
  size_t last = total % k;
  if (last == 0)
  {
    last = k;
  }

  List<T>** res = nullptr;
  try {
    res = new List<T>*[num_lists];
  } catch (...) {
    throw;
  }

  for (size_t i = 0; i < num_lists; ++i)
  {
    res[i] = nullptr;
  }
  size_t id = 0;
  size_t c = 0;
  List<T>** tail = &res[0];
  try {
    for (size_t i = 0; i < v.s; ++i)
    {
      List<T>* cur = v[i];
      while (cur)
      {
        List<T>* next = cur->next;
        if (c == k || (id == num_lists - 1 && c == last))
        {
          ++id;
          c = 0;
          tail = &res[id];
        }
        *tail = cur;
        tail = &cur->next;
        cur->next = nullptr;
        cur = next;
        ++c;
      }
    }
  } catch (...) {
    for (size_t i = 0; i < num_lists; ++i)
    {
      List<T>* cur = res[i];
      while (cur)
      {
        List <T>* next = cur->next;
        delete cur;
        cur = next;
      }
    }
    delete[] res;
    throw;
  }
  for (size_t i = 0; i < v.s; ++i)
  {
    v[i] = nullptr;
  }
  Vec<List<T>*> result;
  result.data = res;
  result.s = num_lists;
  result.cap = num_lists;
  return result;
}

#endif
