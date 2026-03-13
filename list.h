#ifndef LIST_H
#define LIST_H

template< class T >
struct List {
  T val;
  List<T>* next;

  List(const T& v = T(), List<T>* n = nullptr) : val(v), next(n) {}
};

#endif
