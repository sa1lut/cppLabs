#include <iostream>
#include <locale.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

// Удаляет начальные и конечные пробелы из строки
static string trimString(const string &s) {
    size_t start = 0;
    while (start < s.size() && isspace(static_cast<unsigned char>(s[start]))) {
        start++;
    }
    size_t end = s.size();
    while (end > start && isspace(static_cast<unsigned char>(s[end - 1]))) {
        end--;
    }
    return s.substr(start, end - start);
}

// Разбивает текст страницы на строки по символу перевода строки
static vector<string> splitLines(const string &text) {
    vector<string> lines;
    string line;
    istringstream stream(text);
    while (getline(stream, line)) {
        lines.push_back(line);
    }
    return lines;
}

// Собирает список строк обратно в один текст страницы
static string joinLines(const vector<string> &lines) {
    string result;
    for (size_t i = 0; i < lines.size(); ++i) {
        result += lines[i];
        if (i + 1 < lines.size()) {
            result += '\n';
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    string inputFileName, outputFileName;

    cout << "Введите имя входного файла: ";
    cin >> inputFileName;

    cout << "Введите имя выходного файла: ";
    cin >> outputFileName;

    ifstream inFile(inputFileName, ios::binary);
    if (!inFile.is_open()) {
        cerr << "Не удалось открыть файл " << inputFileName << " для чтения." << endl;
        return 1;
    }

    ostringstream contentStream;
    contentStream << inFile.rdbuf();
    string text = contentStream.str();
    inFile.close();

    vector<string> pages;
    size_t pos = 0;
    while (pos <= text.size()) {
        size_t next = text.find('\f', pos);
        if (next == string::npos) {
            pages.push_back(text.substr(pos));
            break;
        }
        pages.push_back(text.substr(pos, next - pos));
        pos = next + 1;
    }

    // Обрабатываем каждую страницу отдельно
    for (string &page : pages) {
        vector<string> lines = splitLines(page);
        if (lines.empty()) {
            continue;
        }

        // Считываем номер страницы из первой строки
        string firstLine = trimString(lines[0]);
        string pageNumber;
        if (!firstLine.empty()) {
            size_t start = 0;
            while (start < firstLine.size() && (firstLine[start] == '-' || isspace(static_cast<unsigned char>(firstLine[start])))) {
                start++;
            }
            size_t end = firstLine.size();
            while (end > start && (firstLine[end - 1] == '-' || isspace(static_cast<unsigned char>(firstLine[end - 1])))) {
                end--;
            }
            pageNumber = firstLine.substr(start, end - start);
        }

        // Удаляем первую строку и добавляем номер страницы в конец
        if (!pageNumber.empty()) {
            lines.erase(lines.begin());
            lines.push_back(pageNumber);
        }

        page = joinLines(lines);
    }

    ofstream outFile(outputFileName, ios::binary);
    if (!outFile.is_open()) {
        cerr << "Не удалось открыть файл " << outputFileName << " для записи." << endl;
        return 1;
    }

    for (size_t i = 0; i < pages.size(); ++i) {
        outFile << pages[i];
        if (i + 1 < pages.size()) {
            outFile << '\f';
        }
    }
    outFile.close();

    cout << "Обработка завершена. Результат записан в " << outputFileName << endl;
    return 0;
}
