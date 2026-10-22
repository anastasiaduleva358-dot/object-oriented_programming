#include "String.h"

int String::my_strlen(const char* s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

void String::my_strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

//Конструктор по длине
String::String(int len) {
    length = len;
    str = new char[length + 1];
    str[0] = '\0';
}

//Конструктор по строке
String::String(const char* s) {
    length = my_strlen(s);
    str = new char[length + 1];
    my_strcpy(str, s);
}

//Конструктор копирования
String::String(const String& other) {
    length = other.length; //копирует длину
    str = new char[length + 1];
    my_strcpy(str, other.str);
}

String::~String() {
    delete[] str;
}

//вывод строки
void String::print() const {
    cout << str << endl;
}

//очистка строки
void String::clear() {
    delete[] str; // удаление старой памяти
    length = 0;
    str = new char[1];
    str[0] = '\0';
}

//Оператор +
String String::operator+(const String& other) {
    int newLen = length + other.length;
    char* temp = new char[newLen + 1];

    int i = 0;

    for (; i < length; i++) { //копирование первой строки
        temp[i] = str[i];
    }

    for (int j = 0; j < other.length; j++) {
        temp[i++] = other.str[j];
    }

    temp[i] = '\0';

    String result(temp);
    delete[] temp;
    return result;
}

//Оператор -
String String::operator-(const String& other) {
    char* temp = new char[length + 1];
    int k = 0;

    for (int i = 0; i < length; i++) {
        bool found = false; //найден ли символ

        for (int j = 0; j < other.length; j++) {
            if (str[i] == other.str[j]) {
                found = true;
                break;
            }
        }

        if (!found) { //если не нашли добавляем в новую строку
            temp[k++] = str[i];
        }
    }

    temp[k] = '\0';

    String result(temp);
    delete[] temp;
    return result;
}

//Операторы < и >
bool String::operator<(const String& other) {
    return length < other.length; // сравнение по длине
}

bool String::operator>(const String& other) {
    return length > other.length;
}