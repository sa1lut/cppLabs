#include <iostream>
#include <clocale>
#include "utils.h" // Подключаем заголовочный файл с объявлениями функций

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8"); 
    char str1[] = "qwerty", str2[] = "1234567890";

    cout << "Исходные строки: str1=" << str1 << ", str2=" << str2 << endl;

    cout << "длина str1=" << dlina1(str1) << ", str2=";
    cout << dlina1(str2) << endl;

    cout << "длина str1=" << dlina2(str1) << ", str2=";
    cout << dlina2(str2) << endl;

    cout << "длина str1=" << dlina3(str1) << ", str2=";
    cout << dlina3(str2) << endl;

    kopir(str1, str2);
    cout << "результат копирования:str1=" << str1;
    cout << ", str2=" << str2 << endl;

    int comparer = sravn(str1, str2);
    if (comparer == 0) {
        cout << "Строки " << str1 << " и " << str2 << " равны" << endl;
    }
    else if (comparer > 0) {
        cout << "Строка " << str1 << " больше строки " << str2 << endl;
    }
    else {
        cout << "Строка " << str1 << " меньше строки " << str2 << endl;
    }

    char* concatRes = konkat(str1, str2);
    cout << "результат сцепления:str1=" << str1;
    cout << ", str2=" << str2 << endl;
    cout << "результат: " << concatRes << endl;

    return 0;
}