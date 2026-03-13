#ifndef VEC_H
#define VEC_H

#include <cstddef>

template< class T >
struct Vec {
  T* data;
  size_t s;
  size_t cap;
};

#endif
