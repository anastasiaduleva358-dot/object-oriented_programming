#include "Matrix.h"

template <typename T>
Matrix<T>::Matrix(int r, int c) {
    rows = r;
    cols = c;

    data = new T*[rows]; // выделение памяти под строки
    for (int i = 0; i < rows; i++) {
        data[i] = new T[cols]; // для каждой строки создаётся массив столбцов
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i]; //удаление каждой строки
    }
    delete[] data; // удаляется массив указателей, иначе будет утечка памяти
}

template <typename T>
void Matrix<T>::input() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> data[i][j];
        }
    }
}

template <typename T>
void Matrix<T>::print() const { // функция не изменяет данные
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other) {
    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j]; // складывает элементы двух матриц
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& other) {
    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& other) {
    Matrix result(rows, other.cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            result.data[i][j] = 0; //обнуление элемента, чтобы не было мусора в памяти
            for (int k = 0; k < cols; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j]; //строка * столбец
            }
        }
    }

    return result;
}