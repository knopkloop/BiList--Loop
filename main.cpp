#include <iostream>
#include "BiList.h"
#include "BiList.cpp"

template <class T>
void printElement(const T& val) {
  std::cout << val << " ";
}

template <class T>
struct Counter {
  int count = 0;
  void operator()(const T&) {
    count++;
  }
};

template <class T>
struct MaxFinder {
  T max_value;
  bool first = true;

  void operator()(const T& val) {
    if (first) {
      max_value = val;
      first = false;
    } else if (val > max_value) {
      max_value = val;
    }
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
  std::cout << "Количество элементов: " << cnt.count << "\n";

  MaxFinder<int> mx;
  mx = traverse(mx, list, list);
  std::cout << "Максимальный элемент: " << mx.max_value << "\n";

  list = add(list, 0);
  list = add(list, 7);
  std::cout << "\nПосле add(0) и add(7): ";
  traverse(printElement<int>, list, list);
  std::cout << "\n";

  if (list->next != list) {
    insert(list->next, 3);
    std::cout << "После insert(вставил после второго элемента): ";
    traverse(printElement<int>, list, list);
    std::cout << "\n";
  }

  list = cut(list);
  std::cout << "После cut (удалили голову): ";
  traverse(printElement<int>, list, list);
  std::cout << "\n";

  if (list->next != list) {
    erase(list);
    std::cout << "После erase (удалили после головы): ";
    traverse(printElement<int>, list, list);
    std::cout << "\n";
  }

  list = clear(list, list);
  std::cout << "\nПосле clear: ";
  traverse(printElement<int>, list, list);
  std::cout << "(пусто)" << "\n";
}
