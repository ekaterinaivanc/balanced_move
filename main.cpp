#include <iostream>
#include "balanced_move.h"

template< class T > 
void print(const Vec<List<T>*>& v) {
  for (size_t i = 0; i < v.s; ++i)
  {
    std::cout << " " << i << ": ";
    List<T>* cur = v.data[i];
    while (cur) {
      std::cout << cur->val << " ";
      cur = cur->next;
    }
    std::cout << "\n";
  }
}

int main()
{
  List<int>* first = new List<int>(1);
  first = new List<int>(2, first);
  first = new List<int>(3, first);

  List<int>* second = new List<int>(4);
  second = new List<int>(5, second);

  List<int>* third = new List<int>(6);
  third = new List<int>(7, third);
  third = new List<int>(8, third);
  third = new List<int>(9, third);

  Vec<List<int>*> before(3);
  before.data[0] = first;
  before. data[1] = second;
  before.data[2] = third;

  print(before);
  std::cout << "\n";

  Vec<List<int>*> after = balanced_move(before, 3);
  print(after);

  for (size_t i = 0; i < after.s; ++i)
  {
    List<int>* cur = after[i]; 
    while (cur) {
      List<int>* next = cur->next;
      delete cur;
      cur = next;
    }
  }
  return 0;
}
