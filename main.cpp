#include <iostream>
#include "BiList.h"
#include "BiList.cpp"

template <class T>
void printElement(const T& val)
{
  std::cout << val << " ";
}

template <class T>
struct Counter
{
  size_t count = 0;
  void operator()(const T&)
  {
    ++count;
  }
};

int main() {

  int arr[] = {5, 2, 8, 1, 9};
  BiList<int>* list = convert(arr, 5);

  std::cout << "Список: ";
  traverse(printElement<int>, list, list);
  std::cout << "\n";

  Counter<int> cnt;
  cnt = traverse(cnt, list, list);
  std::cout << "Кол-во элементов: " << cnt.count << "\n";

  std::cout << "\nadd(0) + add(7): ";
  list = add(list, 0);
  list = add(list, 7);
  traverse(printElement<int>, list, list);
  std::cout << "\n";

  std::cout << "insert после второго узла: ";
  insert(list->next, 3);
  traverse(printElement<int>, list, list);
  std::cout << "\n";

  std::cout << "cut: ";
  list = cut(list);
  traverse(printElement<int>, list, list);
  std::cout << "\n";

  std::cout << "erase после третьего узла: ";
  erase(list->next->next);
  traverse(printElement<int>, list, list);
  std::cout << "\n";

  std::cout << "\nПосле clear: ";
  list = clear(list, list);
  traverse(printElement<int>, list, list);
  std::cout << "(пусто)" << "\n";
}
