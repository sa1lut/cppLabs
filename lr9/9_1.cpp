#include <iostream>
#include <ostream>
#include <locale.h>

template<class T>
void Sort(T array[], size_t size) {
    int i, j;
    T tmp;
    for (i = 0; i < size - 1; i++)
        for (j = size - 1; i < j; j--)
            if (array[i] > array[j]) {
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
}

class Money {
public:
    int rub;
    int kop;

    Money() {}
    Money(int r, int k) {
        rub = r;
        kop = k;
    }

    bool operator>(const Money& other) const {
        if (rub > other.rub) return true;
        if (rub == other.rub && kop > other.kop) return true;
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const Money& money) {
        os << money.rub << " руб. " << money.kop << " коп.";
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int i;
    int mas[] = { 10, 20, 30, 11, 25, 32, 0 };

    std::cout << "Исходный массив:" << std::endl;
    for (i = 0; i < sizeof(mas) / sizeof(mas[0]); i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    Sort(mas, sizeof(mas) / sizeof(mas[0]));
    std::cout << "Отсортированный массив:" << std::endl;
    for (i = 0; i < sizeof(mas) / sizeof(mas[0]); i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    Money moneyArray[] = { Money(10, 50), Money(5, 75), Money(20, 0), Money(15, 25) };
    std::cout << "Исходный массив денег:" << std::endl;
    for (i = 0; i < sizeof(moneyArray) / sizeof(moneyArray[0]); i++) {
        std::cout  << moneyArray[i] << "; ";
    }
    
    Sort(moneyArray, sizeof(moneyArray) / sizeof(moneyArray[0]));

    std::cout << std::endl << "Отсортированный массив денег:" << std::endl;  
    for (i = 0; i < sizeof(moneyArray) / sizeof(moneyArray[0]); i++){
        std::cout << moneyArray[i] << "; ";
    }
    
    return 0;
}
