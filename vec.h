#ifndef VEC_H
#define VEC_H

#include <cstddef>

template< class T >
struct Vec {
  T* data;
  size_t s;
  size_t cap;

  Vec() : data(nullptr), s(0), cap(0) {}
  explicit Vec(size_t size) : s(size), cap(size) {
    data = new T[size];
  }

  ~Vec() {
    delete[] data;
  }

  T& operator[](size_t index) {
    return data[index];
  }

  const T& operator[](size_t index) const {
    return data[index];
  }
};

#endif
