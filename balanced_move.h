#ifndef BALANCED_MOVE_H
#define BALANCED_MOVE_H

#include "list.h"
#include "vec.h"

template< class T >
Vec< List<T>* > balanced_move(Vec< List<T>* > v, size_t k) {
  size_t total = 0;
  for (size_t i = 0; i < v.s; ++i)
  {
    for (List<T>* cur = v[i]; cur; cur = cur->next)
    {
      ++total;
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

  Vec<List<T>*> res(num_list);
  for (size_t i = 0; i < num_lists; ++i)
  {
    res.data[i] = nullptr;
  }
  size_t id = 0;
  size_t c = 0;
  List<T>** tail = &res.data[0];
  for (size_t i = 0; i < v.s; ++i)
  {
    List<T>* cur = v[i];
    v[i] = nullptr;
    while (cur)
    {
      List<T>* next = cur->next;
      if (c == k || (id == num_lists-1 && c == last))
      {
        ++id;
        c = 0;
        tail = &res.data[id];
      }
      *tail = cur;
      tail = &cur->next;
      cur->next = nullptr;
      cur = next;
      ++c;
    }
  }
  return res;
}

#endif
