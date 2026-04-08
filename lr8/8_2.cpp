#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>

using namespace std;

// Функция для шифрования
void encodeFile(const string &inFile, const string &outFile, const string &key) {
    std::ifstream inputFile(inFile);
    if (!inputFile) {
        cout << "Ошибка при открытии входного файла!";
        return;
    }

   std::ofstream outputFile(outFile);
    if (!outputFile) {
        cout << "Ошибка при создании выходного файла!";
        inputFile.close();
        return;
    }

    if (key.empty()) {
        cout << "Ключ не может быть пустым!";
        inputFile.close();
        outputFile.close();
        return;
    }

    char ch;
    int keyLength = key.length();
    int keyIndex = 0;
    
    // Чтение и запись через класс потока
    while (!inputFile.eof()) {
        inputFile >> ch;
        char encodedChar = ch ^ key[keyIndex];
        outputFile << encodedChar;
        keyIndex = (keyIndex + 1) % keyLength;
    }
    
    inputFile.close();
    outputFile.close();

    cout << "Файл успешно сформирован.";
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    setlocale(LC_ALL, "ru_RU.UTF-8");
    string inFileName, outFileName, key;

    cout << "Введите: входной файл выходной файл ключ" << endl;
    cin >> inFileName >> outFileName >> key;

    cout << endl << "Имя входного файла: " << inFileName << endl;
    cout << "Имя выходного файла: " << outFileName << endl;
    cout << "Ключ: " << key << endl;

    encodeFile(inFileName, outFileName, key);

    return 0;
}