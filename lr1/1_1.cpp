#include <iostream>

using namespace std;

int main() {
    // Объявление переменных и функции
    int i, k, degreeBase;
    int power(int, int);

    // Ввод основания степени
    cout << "Введите основание степени: ";
    cin >> degreeBase;

    // Вычисление и вывод степеней
    for (i = 0; i < 10; i++) {
        k = power(degreeBase, i);
        cout << "i = " << i << ", k = " << k << endl;
    }

    return 0;
}

int power(int x, int n) {
    int p = 1;
    // Вычисление x в степени n
    for (int i = 0; i < n; i++) {
        p *= x;
    }
    return p;
}