#include <iostream>
#include <locale.h>
#include "LinkedList.h"

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    LinkedList<int> list(1);
    for (int i = 2; i <= 5; i++) list.add(i);
    std::cout << "Исходный список: ";
    list.print();

    list.remove(5);
    std::cout << "Список после удаления 5: ";
    list.print();

    list.insert(3, 100);
    std::cout << "Список после вставки 100 на позицию 3: ";
    list.print();

    return 0;
}