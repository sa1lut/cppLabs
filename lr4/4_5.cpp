#include <iostream>
#include <cstring>  
#include <clocale>  
#include <cstdlib>  

#include "utils.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    const int STRING_COUNT = 3;
    const int MAX_LENGTH = 100;

    char **strings = (char **)calloc(STRING_COUNT, sizeof(char *));

    strings[0] = (char *)calloc(MAX_LENGTH, sizeof(char));
    strcpy(strings[0], "Привет, мир!"); // Инициализируем первую строку
    strings[1] = (char *)calloc(MAX_LENGTH, sizeof(char));
    strcpy(strings[1], "Как дела?"); // Инициализируем вторую строку
    strings[2] = (char *)calloc(MAX_LENGTH, sizeof(char));
    strcpy(strings[2], "123"); // Инициализируем третью строку

    bool memoryError = false;
    for (int i = 0; i < STRING_COUNT; i++) {
        if (strings[i] == nullptr) {
            cerr << "Ошибка выделения памяти для строки " << i << endl;
            memoryError = true;
            break;
        }
    }
    if (memoryError) {
        return 1;
    }

    cout << "Исходные строки:" << endl;
    for (int i = 0; i < STRING_COUNT; i++) {
        cout << i + 1 << ": " << strings[i] << endl;
    }

    cout << endl << "Длины строк:" << endl;
    for (int i = 0; i < STRING_COUNT; i++) {
        cout << "Длина строки перебором " << i + 1 << ": " << dlina1(strings[i]) << endl;
        cout << "Длина строки указателями " << i + 1 << ": " << dlina2(strings[i]) << endl;
        cout << "Длина строки рекурсией " << i + 1 << ": " << dlina3(strings[i]) << endl;
    }

    cout << endl << "Копирование строк:" << endl;
    char *copyStr = (char *)calloc(MAX_LENGTH, sizeof(char));
    strcpy(copyStr, strings[0]);
    cout << "До копирования: " << copyStr << endl;
    kopir(copyStr, strings[1]);
    cout << "После копирования строки 2 в строку 1: " << copyStr << endl;

    free(copyStr);

    cout << endl << "Сравнение строк:" << endl;
    for (int i = 0; i < STRING_COUNT; i++) {
        for (int j = i + 1; j < STRING_COUNT; j++) {
            int cmpResult = strcmp(strings[i], strings[j]);
            cout << "Сравнение строки " << i + 1 << " и строки " << j + 1 << ": ";
            if (cmpResult == 0) {
                cout << "Строки равны." << endl;
            } else if (cmpResult < 0) {
                cout << "Строка " << i + 1 << " < строки " << j + 1 << "." << endl;
            } else {
                cout << "Строка " << i + 1 << " > строки " << j + 1 << "." << endl;
            }
        }
    }

    cout << endl << "Конкатенация строк:" << endl;
    char *concatStr = konkat(strings[0], strings[1]);
    cout << "Результат конкатенации строки 1 и строки 2: " << concatStr << endl;
    free(concatStr);

    // Освобождение памяти для строк
    for (int i = 0; i < STRING_COUNT; i++) {
        free(strings[i]);
    }

    // Освобождение памяти для массива указателей
    free(strings);


    return 0;
}