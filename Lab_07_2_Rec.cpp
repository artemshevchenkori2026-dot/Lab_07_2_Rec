#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Рекурсивне формування елементів одного рядка
void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo) {
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < n - 1)
        CreateRow(a, rowNo, n, Low, High, colNo + 1);
}

// Рекурсивне формування всіх рядків матриці
void CreateRows(int** a, const int n, const int Low, const int High, int rowNo) {
    CreateRow(a, rowNo, n, Low, High, 0);
    if (rowNo < n - 1)
        CreateRows(a, n, Low, High, rowNo + 1);
}

// Рекурсивне виведення елементів одного рядка
void PrintRow(int** a, const int rowNo, const int n, int colNo) {
    cout << setw(5) << a[rowNo][colNo];
    if (colNo < n - 1)
        PrintRow(a, rowNo, n, colNo + 1);
    else
        cout << endl;
}

// Рекурсивне виведення всіх рядків матриці
void PrintRows(int** a, const int n, int rowNo) {
    PrintRow(a, rowNo, n, 0);
    if (rowNo < n - 1)
        PrintRows(a, n, rowNo + 1);
    else
        cout << endl;
}

// Рекурсивна функція пошуку мінімального елемента побічної діагоналі
int MinSecondaryDiagonal(int** a, const int n, int i) {
    // Базовий випадок: якщо дійшли до останнього елемента діагоналі (i == n - 1)
    if (i == n - 1) {
        return a[i][n - 1 - i];
    }

    // Рекурсивний виклик для решти елементів діагоналі
    int currentMin = MinSecondaryDiagonal(a, n, i + 1);

    // Повертаємо найменше серед поточного елемента та мінімуму з решти
    return min(a[i][n - 1 - i], currentMin);
}

int main() {
    srand((unsigned)time(NULL));

    int n;
    cout << "n = ";
    cin >> n;

    int Low, High;
    cout << "Low = ";
    cin >> Low;
    cout << "High = ";
    cin >> High;

    // Захист від випадкової перестановки меж місцями
    if (Low > High) {
        swap(Low, High);
    }

    // Створення динамічної квадратної матриці (n x n)
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }

    // 1. Формування та виведення початкової матриці
    CreateRows(a, n, Low, High, 0);
    cout << "Initial matrix:" << endl;
    PrintRows(a, n, 0);

    // 2. Пошук мінімального елемента побічної діагоналі (початковий індекс i = 0)
    int minDiag = MinSecondaryDiagonal(a, n, 0);
    cout << "Min element on secondary diagonal = " << minDiag << endl;

    // Звільнення пам'яті
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}