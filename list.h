#ifndef LIST_H
#define LIST_H

template< class T >
struct List {
  T val;
  List<T>* next;
};

#endif
