#pragma once
#include <iostream>
#include <cstring>

class MyString {
private:
    char* data;
    size_t length;

public:
    MyString(const char* initString = "");
    MyString(const MyString& other);
    ~MyString();

    MyString& operator=(const MyString& other);

    const char* getData() const;
    size_t getLength() const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
};