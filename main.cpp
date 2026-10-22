/*Лабораторная работа №4. Шаблоны (Templates)

1. Разработать шаблонный класс Матрица.
Предусмотреть вариант хранения в матрице строк символов.
Перегрузить операции +, -. *.
В классе должен быть конструктор.
Предусмотреть член-функцию для печати элементов класса.
*/
#include "Matrix.h"

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    Matrix<int> A(rows, cols);
    Matrix<int> B(rows, cols);

    cout << "Enter matrix A:\n";
    A.input();

    cout << "Enter matrix B:\n";
    B.input();

    Matrix<int> C = A + B;
    Matrix<int> D = A - B;
    Matrix<int> E = A * B;

    cout << "\nA + B:\n";
    C.print();

    cout << "\nA - B:\n";
    D.print();

    cout << "\nA * B:\n";
    E.print();

    return 0;
}