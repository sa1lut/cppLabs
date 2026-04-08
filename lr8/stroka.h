#include <iostream>

class Stroka {
    char* str;
public:
    Stroka(const char*);
    Stroka() : str(nullptr) {}
    Stroka(const Stroka&);
    ~Stroka();
    Stroka& operator=(const Stroka&);
    Stroka& operator=(const char*);
    Stroka operator+(const Stroka&);
    int operator==(const Stroka&);
    int dlina();
    void vvod();
    void vyvod();

    // Дружественные функции для ввода и вывода
    friend std::istream& operator>>(std::istream&, Stroka&);
    friend std::ostream& operator<<(std::ostream&, const Stroka&);
};