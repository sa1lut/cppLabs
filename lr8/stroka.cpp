#include <iostream>
#include "stroka.h"
#include "../lr4/utils.h"

using namespace std;

// Конструкторы
Stroka::Stroka(const char* string) {
    int length = dlina1(string);
    str = new char[length + 1];
    kopir(str, string);
}

Stroka::Stroka(const Stroka& s) {
    int length = dlina1(s.str);
    str = new char[length + 1];
    kopir(str, s.str);
}

// Деструктор
Stroka::~Stroka() {
    delete[] str;
}

// Переопределение оператора присваивания
Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) {  // Защита от присваивания самому себе
        delete[] str;  // Освобождаем старую память
        
        int length = dlina1(s.str);
        str = new char[length + 1];  // Выделяем новую
        kopir(str, s.str);
    }
    return *this;
}

// Оператор присваивания для const char*
Stroka& Stroka::operator=(const char* string) {
    delete[] str;
    int length = dlina1(string);
    str = new char[length + 1];
    kopir(str, string);
    return *this;
}

// Переопределение конкатенации строк
Stroka Stroka::operator+(const Stroka& s) {
    return Stroka(konkat(str, s.str));
}

//Переопределение сравнения
int Stroka::operator==(const Stroka& s) {
    if ((sravn(str, s.str)) == 0)
        return 1;
    else
        return 0;
}

// Длина строки
int Stroka::dlina() {
    return dlina1(str);
}

// Ввод строки
void Stroka::vvod() {
    char buffer[256];
    cout << "Введите строку: ";
    cin >> buffer;
    
    int length = dlina1(buffer);
    str = new char[length + 1];
    kopir(str, buffer);
}

// Вывод строки
void Stroka::vyvod() {
    cout << str;
}

// Дружественная функция для ввода
istream& operator>>(istream& in, Stroka& s) {
    in >> *s.str;   
    return in;
}

// Дружественная функция для вывода
ostream& operator<<(ostream& out, const Stroka& s) {
    out << s.str;
    return out;
}