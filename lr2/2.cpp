#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <float.h>
#include <locale.h>
#define N 5

using namespace std;

float getMinMatrix(float m[N][N]);                      // Функция для получения минимального элемента матрицы
float getMaxMatrix(float m[N][N]);                      // Функция для получения максимального элемента матрицы
float getMaxLowTriangleMatrix(float m[N][N]);           // Функция для получения максимального элемента нижнего треугольника матрицы
float getMaxUpTriangleMatrix(float m[N][N]);            // Функция для получения максимального элемента верхнего треугольника матрицы
float getMinLowTriangleMatrix(float m[N][N]);           // Функция для получения минимального элемента нижнего треугольника матрицы
float getMinUpTriangleMatrix(float m[N][N]);            // Функция для получения минимального элемента верхнего треугольника матрицы
float getMinMainDiagonalMatrix(float m[N][N]);          // Функция для получения минимального элемента главной диагонали матрицы
float getMaxMainDiagonalMatrix(float m[N][N]);          // Функция для получения максимального элемента главной диагонали матрицы
float getMinSideDiagonalMatrix(float m[N][N]);          // Функция для получения минимального элемента побочной диагонали матрицы
float getMaxSideDiagonalMatrix(float m[N][N]);          // Функция для получения максимального элемента побочной диагонали матрицы
float getAverageMatrix(float m[N][N]);                  // Функция для получения среднего арифметического элементов матрицы
float getAverageLowTriangleMatrix(float m[N][N]);       // Функция для получения среднего арифметического элементов нижнего треугольника матрицы
float getAverageUpTriangleMatrix(float m[N][N]);        // Функция для получения среднего арифметического элементов верхнего треугольника матрицы
float getSumRowMatrix(float m[N][N], int row);          // Функция для получения суммы элементов строки матрицы
float getSumColumnMatrix(float m[N][N], int col);       // Функция для получения суммы элементов столбца матрицы
float getMinRowMatrix(float m[N][N], int row);          // Функция для получения минимального элемента строки матрицы
float getMinColumnMatrix(float m[N][N], int col);       // Функция для получения минимального элемента столбца матрицы
float getMaxRowMatrix(float m[N][N], int row);          // Функция для получения максимального элемента строки матрицы
float getMaxColumnMatrix(float m[N][N], int col);       // Функция для получения максимального элемента столбца матрицы
float getAverageRowMatrix(float m[N][N], int row);      // Функция для получения среднего арифметического элементов строки матрицы
float getAverageColumnMatrix(float m[N][N], int col);   // Функция для получения среднего арифметического элементов столбца матрицы
float getSumLowUpTriangleMatrix(float m[N][N]);         // Функция для получения суммы элементов нижнего и верхнего треугольника матрицы
float getClosestToAverageMatrix(float m[N][N]);         // Функция для получения элемента матрицы, наиболее близкого к среднему арифметическому элементов матрицы

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8"); 

    float m[N][N];
    int i, j;
    
    // Заполнение матрицы случайными числами
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = rand() / 10.;
        }
    }

    // Вывод исходной матрицы
    cout << "Исходная матрица:" << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << setw(8) << setprecision(5) << m[i][j];
        }
        cout << endl;
    }

    cout << endl << "Минимальный элемент матрицы: " << getMinMatrix(m) << endl;
    cout << "Максимальный элемент матрицы: " << getMaxMatrix(m) << endl;
    cout << "Максимальный элемент нижнего треугольника матрицы: " << getMaxLowTriangleMatrix(m) << endl;
    cout << "Максимальный элемент верхнего треугольника матрицы: " << getMaxUpTriangleMatrix(m) << endl;
    cout << "Минимальный элемент нижнего треугольника матрицы: " << getMinLowTriangleMatrix(m) << endl;
    cout << "Минимальный элемент верхнего треугольника матрицы: " << getMinUpTriangleMatrix(m) << endl;
    cout << "Минимальный элемент главной диагонали матрицы: " << getMinMainDiagonalMatrix(m) << endl;
    cout << "Максимальный элемент главной диагонали матрицы: " << getMaxMainDiagonalMatrix(m) << endl;
    cout << "Минимальный элемент побочной диагонали матрицы: " << getMinSideDiagonalMatrix(m) << endl;
    cout << "Максимальный элемент побочной диагонали матрицы: " << getMaxSideDiagonalMatrix(m) << endl;
    cout << "Среднее арифметическое элементов матрицы: " << getAverageMatrix(m) << endl;
    cout << "Среднее арифметическое элементов нижнего треугольника матрицы: " << getAverageLowTriangleMatrix(m) << endl;
    cout << "Среднее арифметическое элементов верхнего треугольника матрицы: " << getAverageUpTriangleMatrix(m) << endl;

    cout << endl << "Сумма элементов строк и столбцов матрицы" << endl;
    for (i = 0; i < N; i++) {
        cout << "Сумма элементов строки " << i << ": " << getSumRowMatrix(m, i) << endl;
    }

    
    cout << endl;
    for (j = 0; j < N; j++) {
        cout << "Сумма элементов столбца " << j << ": " << getSumColumnMatrix(m, j) << endl;
    }

    cout << endl << "Минимальные и максимальные элементы строк и столбцов матрицы" << endl;
    for (i = 0; i < N; i++) {
        cout << "Минимальный элемент строки " << i << ": " << getMinRowMatrix(m, i) << endl;
    }

    cout << endl;
    for (j = 0; j < N; j++) {
        cout << "Минимальный элемент столбца " << j << ": " << getMinColumnMatrix(m, j) << endl;
    }

    cout << endl;
    for (i = 0; i < N; i++) {
        cout << "Максимальный элемент строки " << i << ": " << getMaxRowMatrix(m, i) << endl;
    }

    cout << endl;
    for (j = 0; j < N; j++) {
        cout << "Максимальный элемент столбца " << j << ": " << getMaxColumnMatrix(m, j) << endl;
    }

    cout << endl << "Среднее арифметическое элементов строк и столбцов матрицы" << endl;
    for (i = 0; i < N; i++) {
        cout << "Среднее арифметическое элементов строки " << i << ": " << getAverageRowMatrix(m, i) << endl;
    }

    cout << endl;
    for (j = 0; j < N; j++) {
        cout << "Среднее арифметическое элементов столбца " << j << ": " << getAverageColumnMatrix(m, j) << endl;
    }

    cout << endl << "Сумма элементов нижнего и верхнего треугольника матрицы: " << getSumLowUpTriangleMatrix(m) << endl;
    cout << "Элемент матрицы, наиболее близкий к среднему арифметическому элементов матрицы: " << getClosestToAverageMatrix(m) << endl;

    return 0;
}

// Функция для получения минимального элемента матрицы
float getMinMatrix(float m[N][N]) {
    float min = FLT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] < min) {
                min = m[i][j];
            }
        }
    }
    return min;
}

// Функция для получения максимального элемента матрицы
float getMaxMatrix(float m[N][N]) {
    float max = FLT_MIN;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] > max) {
                max = m[i][j];
            }
        }
    }
    return max;
}

// Функция для получения максимального элемента нижнего треугольника матрицы
float getMaxLowTriangleMatrix(float m[N][N]) {
    float max = FLT_MIN;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (m[i][j] > max) {
                max = m[i][j];
            }
        }
    }
    return max;
}

// Функция для получения максимального элемента верхнего треугольника матрицы
float getMaxUpTriangleMatrix(float m[N][N]) {
    float max = FLT_MIN;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] > max) {
                max = m[i][j];
            }
        }
    }
    return max;
}

// Функция для получения минимального элемента нижнего треугольника матрицы
float getMinLowTriangleMatrix(float m[N][N]) {
    float min = FLT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (m[i][j] < min) {
                min = m[i][j];
            }
        }
    }
    return min;
}

// Функция для получения минимального элемента верхнего треугольника матрицы
float getMinUpTriangleMatrix(float m[N][N]) {
    float min = FLT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] < min) {
                min = m[i][j];
            }
        }
    }
    return min;
}

// Функция для получения минимального элемента главной диагонали матрицы
float getMinMainDiagonalMatrix(float m[N][N]) {
    float min = FLT_MAX;
    for (int i = 0; i < N; i++) {
        if (m[i][i] < min) {
            min = m[i][i];
        }
    }
    return min;
}

// Функция для получения максимального элемента главной диагонали матрицы
float getMaxMainDiagonalMatrix(float m[N][N]) {
    float max = FLT_MIN;
    for (int i = 0; i < N; i++) {
        if (m[i][i] > max) {
            max = m[i][i];
        }
    }
    return max;
}

// Функция для получения минимального элемента побочной диагонали матрицы
float getMinSideDiagonalMatrix(float m[N][N]) {
    float min = FLT_MAX;
    for (int i = 0; i < N; i++) {
        if (m[i][N - 1 - i] < min) {
            min = m[i][N - 1 - i];
        }
    }
    return min;
}

// Функция для получения максимального элемента побочной диагонали матрицы
float getMaxSideDiagonalMatrix(float m[N][N]) {
    float max = FLT_MIN;
    for (int i = 0; i < N; i++) {
        if (m[i][N - 1 - i] > max) {
            max = m[i][N - 1 - i];
        }
    }
    return max;
}

// Функция для получения среднего арифметического элементов матрицы
float getAverageMatrix(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
    }
    return sum / (N * N);
}

// Функция для получения среднего арифметического элементов нижнего треугольника матрицы
float getAverageLowTriangleMatrix(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum / count;
}

// Функция для получения среднего арифметического элементов верхнего треугольника матрицы
float getAverageUpTriangleMatrix(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum / count;
}

// Функция для получения суммы элементов строки матрицы
float getSumRowMatrix(float m[N][N], int row) {
    float sum = 0;
    for (int j = 0; j < N; j++) {
        sum += m[row][j];
    }
    return sum;
}

// Функция для получения суммы элементов столбца матрицы
float getSumColumnMatrix(float m[N][N], int col) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        sum += m[i][col];
    }
    return sum;
}

// Функция для получения минимального элемента строки матрицы
float getMinRowMatrix(float m[N][N], int row) {
    float min = FLT_MAX;
    for (int j = 0; j < N; j++) {
        if (m[row][j] < min) {
            min = m[row][j];
        }
    }
    return min;
}

// Функция для получения минимального элемента столбца матрицы
float getMinColumnMatrix(float m[N][N], int col) {
    float min = FLT_MAX;
    for (int i = 0; i < N; i++) {
        if (m[i][col] < min) {
            min = m[i][col];
        }
    }
    return min;
}

// Функция для получения максимального элемента строки матрицы
float getMaxRowMatrix(float m[N][N], int row) {
    float max = FLT_MIN;
    for (int j = 0; j < N; j++) {
        if (m[row][j] > max) {
            max = m[row][j];
        }
    }
    return max;
}

// Функция для получения максимального элемента столбца матрицы
float getMaxColumnMatrix(float m[N][N], int col) {
    float max = FLT_MIN;
    for (int i = 0; i < N; i++) {
        if (m[i][col] > max) {
            max = m[i][col];
        }
    }
    return max;
}

// Функция для получения среднего арифметического элементов строки матрицы
float getAverageRowMatrix(float m[N][N], int row) {
    float sum = 0;
    for (int j = 0; j < N; j++) {
        sum += m[row][j];
    }
    return sum / N;
}

// Функция для получения среднего арифметического элементов столбца матрицы
float getAverageColumnMatrix(float m[N][N], int col) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        sum += m[i][col];
    }
    return sum / N;
}

// Функция для получения суммы элементов нижнего и верхнего треугольника матрицы
float getSumLowUpTriangleMatrix(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += m[i][j];
        }
        for (int j = i; j < N; j++) {
            sum += m[i][j];
        }
    }
    return sum;
}

// Функция для получения элемента матрицы, наиболее близкого к среднему арифметическому элементов матрицы
float getClosestToAverageMatrix(float m[N][N]) {
    float average = getAverageMatrix(m);
    float closest = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (abs(m[i][j] - average) < abs(closest - average)) {
                closest = m[i][j];
            }
        }
    }
    return closest;
}
