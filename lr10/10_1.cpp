#include <iostream>
#include <locale.h>

// Односвязный список
struct Node {
    int d{};
    Node* next{};
};

// Функция для создания первого узла списка
Node* first(int d) {
    Node* p = new Node;
    p->d = d;
    p->next = nullptr;
    return p;
}

// Функция для добавления узла в конец списка
void add(Node*& end, int d) {
    Node* p = new Node{d, nullptr};
    end->next = p;
    end = p;
}

// Функция для поиска узла по ключу
Node* find(Node* beg, int key) {
    while (beg) {
        if (beg->d == key) return beg;
        beg = beg->next;
    }
    return nullptr;
}

// Функция для удаления узла по ключу
bool remove(Node*& beg, int key) {
    if (!beg) return false;
    if (beg->d == key) {
        Node* t = beg;
        beg = beg->next;
        delete t;
        return true;
    }
    Node* prev = beg;
    Node* cur = beg->next;
    while (cur) {
        if (cur->d == key) {
            prev->next = cur->next;
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

// Функция для вывода списка на экран
void print(Node* beg) {
    while (beg) {
        std::cout << beg->d << ' ';
        beg = beg->next;
    }
    std::cout << '\n';
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Node* beg = first(1);
    Node* end = beg;
    for (int i = 2; i <= 5; ++i) add(end, i);

    std::cout << "Исходный список: ";
    print(beg);

    remove(beg, 5);
    std::cout << "Список после удаления 5: ";
    print(beg);

    remove(beg, 1);
    std::cout << "Список после удаления 1: ";
    print(beg);

    // Очистка памяти
    while (beg) {
        Node* t = beg;
        beg = beg->next;
        delete t;
    }

    return 0;
}
