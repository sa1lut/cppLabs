#include <iostream>

using namespace std;


// Функция для разбиения массива на две части
int partition(int arr[], int low, int high, bool ascending = true) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (ascending ? arr[j] < pivot : arr[j] > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Функция для сортировки четных чисел по возрастанию и нечетных по убыванию
int partitionEvenOdd(int arr[], int low, int high, bool even) {
    if (even) {
        // Для четных - по возрастанию
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    } else {
        // Для нечетных - по убыванию
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] >= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
}

// Функция для сортировки четных чисел по возрастанию и нечетных по убыванию в заданном интервале
void quickSortEvenOdd(int arr[], int low, int high, bool even) {
    if (low < high) {
        int pi = partitionEvenOdd(arr, low, high, even);
        quickSortEvenOdd(arr, low, pi - 1, even);
        quickSortEvenOdd(arr, pi + 1, high, even);
    }
}

// Функция для сортировки массива с помощью алгоритма быстрой сортировки
void quickSort(int arr[], int low, int high, bool ascending = true) {
    if (low < high) {
        int pi = partition(arr, low, high, ascending);
        quickSort(arr, low, pi - 1, ascending);
        quickSort(arr, pi + 1, high, ascending);
    }
}

// Функция для сортировки четных чисел по возрастанию и нечетных по убыванию
void sortEvenOdd(int arr[], int n) {
    // Разделяем массив на четные и нечетные числа
    int* temp = new int[n];
    int evenIndex = 0;
    int oddIndex = n - 1;
    
    // Копируем исходный массив
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    
    // Четные в начало, нечетные в конец
    int left = 0;
    int right = n - 1;
    for (int i = 0; i < n; i++) {
        if (temp[i] % 2 == 0) {
            arr[left++] = temp[i];
        } else {
            arr[right--] = temp[i];
        }
    }
    
    // Сортируем четные по возрастанию
    int evenCount = left;
    if (evenCount > 1) {
        quickSortEvenOdd(arr, 0, evenCount - 1, true);
    }
    
    // Сортируем нечетные по убыванию
    int oddCount = n - evenCount;
    if (oddCount > 1) {
        quickSortEvenOdd(arr, evenCount, n - 1, false);
    }
    
    delete[] temp;
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

    quickSort(arr, 0, N - 1);

    cout << "Отсортированный массив: " << endl;
    printArray(arr, N);

    int arr2[N];
    for (int i = 0; i < N; i++) {
        arr2[i] = rand() % 100;
    }

    cout << endl << "Исходный массив для сортировки чет-нечет: " << endl;
    printArray(arr2, N);

    sortEvenOdd(arr2, N);

    cout << "Отсортированный массив чет-нечет: " << endl;
    printArray(arr2, N);

    int arr3[N];
    for (int i = 0; i < N; i++) {
        arr3[i] = rand() % 100;
    }

    int i = 2, j = 7;

    cout << endl << "Исходный массив для сортировки в интервале (индексы) от " << i << " до " << j << " по возрастанию: " << endl;
    printArray(arr3, N);

    quickSort(arr3, i, j);

    cout << "Отсортированный массив в интервале (индексы) от " << i << " до " << j << " по возрастанию: " << endl;
    printArray(arr3, N);

    int arr4[N];
    for (int i = 0; i < N; i++) {   
        arr4[i] = rand() % 100;
    }

    cout << endl << "Исходный массив для сортировки в интервале (индексы) от " << i << " до " << j << " по убыванию: " << endl;
    printArray(arr4, N);

    quickSort(arr4, i, j, false);

    cout << "Отсортированный массив в интервале (индексы) от " << i << " до " << j << " по убыванию: " << endl;
    printArray(arr4, N);

    return 0;
}