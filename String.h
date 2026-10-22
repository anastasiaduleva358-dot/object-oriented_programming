
#include <iostream>
using namespace std;

class String {
private:
    int length; // хранит длину строки
    char* str; // динамический массив символов

    // функция для вычисления длины строки
    int my_strlen(const char* s);
    // функция для копирования строки
    void my_strcpy(char* dest, const char* src);

public:
    String(int len);
    String(const char* s); // создает объект из обычной строки
    String(const String& other); // создает копию другого объекта String
    ~String();

    void print() const;
    void clear();

    // перезагрузка
    String operator+(const String& other);
    String operator-(const String& other);

    bool operator<(const String& other);
    bool operator>(const String& other);
};

