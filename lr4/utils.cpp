#include "utils.h"

// Функция для определения длины строки через индексирование
int dlina1(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Функция для определения длины строки через указатели
int dlina2(char *str) {
    char *ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

// Функция для определения длины строки через рекурсию
int dlina3(char *str) {
    if (*str == '\0') {
        return 0;
    }
    return 1 + dlina3(str + 1);
}

// Функция для копирования строки
void kopir(char *dest, char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Добавляем завершающий нулевой символ
}

// Функция для сравнения строк
int sravn(char *str1, char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

// Функция для конкатенации строк
char* konkat(char *str1, char *str2) {
    char *result = new char[dlina1(str1) + dlina1(str2) + 1]; // Выделяем память для новой строки
    char *ptr = result;

    while (*str1 != '\0') {
        *ptr = *str1;
        ptr++;
        str1++;
    }
    while (*str2 != '\0') {
        *ptr = *str2;
        ptr++;
        str2++;
    }
    *ptr = '\0'; // Добавляем завершающий нулевой символ

    return result;
}