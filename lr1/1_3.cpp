#include <iostream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8"); 

    int a = 2, b = 5;

    void obmen1(int, int);
    void obmen2(int*, int*);
    void obmen3(int&, int&);

    cout << "До обмена: a = " << a << ", b = " << b << endl;
    obmen1(a, b);
    cout << "После обмена через обмен1: a = " << a << ", b = " << b << endl;    
    obmen2(&a, &b);
    cout << "После обмена через обмен2: a = " << a << ", b = " << b << endl;
    obmen3(a, b);
    cout << "После обмена через обмен3: a = " << a << ", b = " << b << endl;

    return 0;
}

// Функция обмена значениями через передачу по значению
void obmen1(int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// Функция обмена значениями через указатели
void obmen2(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Функция обмена значениями через ссылки
void obmen3(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}