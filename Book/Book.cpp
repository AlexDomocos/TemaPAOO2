#include "Book.h"
namespace library {
    Book::Book(const char *t, const char *a, const char *i, const char *s)
            : title(t), author(a), ISBN(i), status(s) {}

    Book::Book(const Book &other)
            : title(other.title), author(other.author), ISBN(other.ISBN), status(other.status) {}

    Book &Book::operator=(const Book &other) {
        if (this != &other) {
            title = other.title;
            author = other.author;
            ISBN = other.ISBN;
            status = other.status;
        }
        return *this;
    }

    Book &Book::operator=(Book &&other) {
        if (this != &other) {
            title = std::move(other.title);
            author = std::move(other.author);
            ISBN = std::move(other.ISBN);
            status = std::move(other.status);
        }
        return *this;
    }

    Book::Book(Book&& other): title(other.title), author(other.author), ISBN(other.ISBN), status(other.status) {}

    MyString Book::getTitle() const { return title; }

    MyString Book::getAuthor() const { return author; }

    MyString Book::getISBN() const { return ISBN; }

    MyString Book::getStatus() const { return status; }

    void Book::checkOut() { status = "checked out"; }

    void Book::returnItem() { status = "available"; }
}