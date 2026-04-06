#include <stdio.h>
#include <iostream>
#include <string.h>
#include <locale.h>

using namespace std;

void countEmptyAndNonempty(FILE *file, int *emptyCount, int *nonEmptyCount) {
    char ch;
    *emptyCount = 0;
    *nonEmptyCount = 0;

    rewind(file); // Сброс указателя в начало файла
    while(!feof(file)) {
        ch = fgetc(file);
        if(feof(file)) {
            break; 
        }
        if(isspace(ch) || iscntrl(ch)) {
            (*emptyCount)++;
        } else {
            (*nonEmptyCount)++;
        }
    }
}

void searchForSubstring(FILE *in_file, const char *substring, const char *out_filename) {
    char line[512];
    int lineNumber = 0, foundCount = 0;
    FILE *out_file;

    rewind(in_file); // Сброс указателя в начало файла

    out_file = fopen(out_filename, "w");
    if (out_file == NULL) {
        printf("Не удалось открыть файл %s для записи\n", out_filename);
        return;
    }

    // Ищем подстроку в каждой строке входного файла
    while (fgets(line, sizeof(line), in_file)) {
        lineNumber++;
        if (strstr(line, substring) != NULL) {
            printf("Найдена подстрока '%s' в строке %d: %s", substring, lineNumber, line);
            fprintf(out_file, "Строка %d: %s", lineNumber, line);
            foundCount++;
            if(line[strlen(line) - 1] != '\n') {
                fprintf(out_file, "\n"); // Добавляем перенос строки, если его нет
            }
        }
    }

    if (foundCount == 0) {
        printf("Подстрока '%s' не найдена в файле.\n", substring);
    } else {
        printf("Всего найдено %d вхождений подстроки '%s'.\n", foundCount, substring);
    }
    fclose(out_file);
    printf("Всего найдено %d вхождений подстроки '%s'.\n", foundCount, substring);
    printf("Результаты поиска сохранены в файле %s\n", out_filename);
    
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8"); 

    char ch, name[50];
    FILE *in;
    char substring[50], out_filename[50];
    int emptyCount = 0, nonEmptyCount = 0;


    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);
    if((in = fopen(name, "r")) == NULL) {
        printf("Файл %s не открыт\n", name);
        return 1;
    } else {
        while(!feof(in)) {
            ch = fgetc(in);
            if(feof(in)) {
                break;
            }
            putchar(ch);
        }
    }
    
    countEmptyAndNonempty(in, &emptyCount, &nonEmptyCount);
    printf("\nКоличество пустых символов: %d\n", emptyCount);
    printf("Количество непустых символов: %d\n", nonEmptyCount);

    printf("Введите подстроку для поиска: ");
    scanf("%s", substring);
    printf("Введите имя файла для сохранения результатов: ");
    scanf("%s", out_filename);
    searchForSubstring(in, substring, out_filename);

    fclose(in);
    return 0;
}