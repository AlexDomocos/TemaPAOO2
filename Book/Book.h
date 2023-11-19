#pragma once
#include "../MyString/MyString.h"
#include "../ILibraryItem.h"

namespace library {

    class Book : public ILibraryItem {
    private:
        MyString title;
        MyString author;
        MyString ISBN;
        MyString status;

    public:
        Book(const char *title, const char *author, const char *ISBN, const char *status = "available");
        Book(const Book &other);
        Book &operator=(const Book &other);
        Book(Book&& other);

        Book &operator=(Book &&other);

        virtual MyString getTitle() const;
        virtual void checkOut();
        virtual void returnItem();

        MyString getAuthor() const;
        MyString getISBN() const;
        MyString getStatus() const;
    };
}
