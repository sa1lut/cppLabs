#include <iostream>
#include <cstring>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8"); 
    char str1[] = "qwerty", str2[] = "1234567890";
    cout << "строка str1: " << str1 << " строка str2: " << str2 << endl;
    cout << "длина str1=" << strlen(str1) << ", str2=" << strlen(str2) << endl;
    cout << "конкатенация str1 и str2: " << strcat(str1, str2) << endl;
    cout << "сравнение str1 и str2: " << strcmp(str1, str2) << endl;
    cout << "копирование str2 в str1: " << strcpy(str1, str2) << endl;

    return 0;
}