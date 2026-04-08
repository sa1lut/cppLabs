#include <iostream>
#include <fstream>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    // Открытие файла для чтения
    std::ifstream in("input.txt");

    if (!in) {
        std::cout << "Файл не открыт" << std::endl;
        return 1;
    }

    std::cout << "Файл открыт" << std::endl;

    // Чтение и вывод содержимого файла
    char buffer[100];
    std::cout << "Содержимое файла:" << std::endl;
    while (in >> buffer) {
        std::cout << buffer << " ";
    }

    // Сброс флагов состояния потока и возврат в начало файла
    in.clear();

    // Получение длины файла и вычисление позиции середины
    int len = in.seekg(0, std::ios::end).tellg();
    int mid = len / 2;
    // Возврат в середину файла
    in.seekg(mid);

    // Проверка успешности возврата в середину файла
    if (in.fail()) {
        std::cout << "Ошибка при возврате в середину файла" << std::endl;
        return 1;
    }

    std::cout << std::endl << "Чтение из середины:" << std::endl;
    while (in >> buffer) {
        std::cout << buffer << " ";
    }

    in.close();
    std::cout << std::endl << "Файл закрыт" << std::endl;
    return 0;
}
