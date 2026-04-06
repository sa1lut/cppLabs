#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>
#include <cstdlib>


using namespace std;

// Функция для шифрования
void encodeFile(const string &inFile, const string &outFile, const string &key) {
    ifstream inputFile(inFile, ios::binary);
    if (!inputFile.is_open()) {
        cout << "Ошибка при открытии входного файла!";
        return;
    }

    ofstream outputFile(outFile, ios::binary);
    if (!outputFile.is_open()) {
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
    
    while (inputFile.get(ch)) {
        char encodedChar = ch ^ key[keyIndex];
        outputFile.put(encodedChar);
        keyIndex = (keyIndex + 1) % keyLength;
    }
    
    inputFile.close();
    outputFile.close();

    cout << "Файл успешно сформирован.";

}

int main() {
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