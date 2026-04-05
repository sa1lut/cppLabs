#include <iostream>
#include <clocale>
#include <cstring>
#include <cstdlib>

#include "utils.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8"); 

    char *str1, *str2;
    
    // Используем calloc для выделения памяти и инициализации её нулями
    str1 = (char *)calloc(100, sizeof(char));
    str2 = (char *)calloc(100, sizeof(char));

    if (str1 == NULL || str2 == NULL) {
        cerr << "Ошибка выделения памяти" << endl;
        return 1; // Завершаем программу с кодом ошибки
    }

    strcpy(str1, "qwerty");
    strcpy(str2, "1234567890");

    cout << "str1=" << str1 << ", str2=" << str2 << endl;
    cout << "длина str1=" << dlina1(str1) << ", str2=" << dlina1(str2) << endl;
    cout << "длина str1=" << dlina2(str1) << ", str2=" << dlina2(str2) << endl;
    cout << "длина str1=" << dlina3(str1) << ", str2=" << dlina3(str2) << endl;

    kopir(str1, str2);
    cout << "результат копирования:str1=" << str1 << ", str2=" << str2 << endl;

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
    cout << "результат сцепления:str1=" << str1 << ", str2=" << str2 << endl;
    cout << "результат: " << concatRes << endl;

    free(concatRes);
    free(str1);
    free(str2);

    return 0;
}