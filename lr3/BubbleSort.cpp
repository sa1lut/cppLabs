#include <iostream>

using namespace std;


// Функция для сортировки массива с помощью алгоритма пузырьковой сортировки
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Функция для обмена значениями
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Функция для печати массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int N = 10;
    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }    

    cout << "Исходный массив: " << endl;
    printArray(arr, N);

    bubbleSort(arr, N);

    cout << "Отсортированный массив: " << endl;
    printArray(arr, N);

    return 0;
}