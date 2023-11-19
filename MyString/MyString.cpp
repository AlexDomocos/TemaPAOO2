#include "MyString.h"

MyString::MyString(const char* initString) {
    length = strlen(initString);
    data = new char[length + 1];
    strcpy(data, initString);
}

MyString::MyString(const MyString& other) {
    length = other.length;
    data = new char[length + 1];
    strcpy(data, other.data);
}

MyString::~MyString() {
    delete[] data;
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }
    return *this;
}

const char* MyString::getData() const {
    return data;
}

size_t MyString::getLength() const {
    return length;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.getData();
    return os;
}