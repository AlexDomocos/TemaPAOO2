#include "../MyString/MyString.h"
#include "../Book/Book.h"
#include "../DVD/DVD.h"
#include <iostream>

using namespace library;

int main() {
    // Create a Book instance
    Book book1("1984", "George Orwell", "978-0451524935");
    std::cout << "Book Title: " << book1.getTitle() << std::endl;
    std::cout << "Book Author: " << book1.getAuthor() << std::endl;
    std::cout << "Book ISBN: " << book1.getISBN() << std::endl;
    std::cout << "Book Status: " << book1.getStatus() << std::endl;

    // Checkout the book
    std::cout << "\nChecking out the book...\n";
    book1.checkOut();
    std::cout << "Book Status: " << book1.getStatus() << std::endl;

    // Return the book
    std::cout << "\nReturning the book...\n";
    book1.returnItem();
    std::cout << "Book Status: " << book1.getStatus() << std::endl;

    // Demonstrate copy semantics for Book
    std::cout << "\nCopying book1 to book2...\n";
    Book book2 = book1; // Copy constructor
    std::cout << "Book2 Title: " << book2.getTitle() << std::endl;
    std::cout << "Book2 Status: " << book2.getStatus() << std::endl;

    // Demonstrate move semantics for Book
    std::cout << "\nMoving book2 to book3...\n";
    Book book3 = std::move(book2); // Move constructor
    std::cout << "Book3 Title: " << book3.getTitle() << std::endl;
    std::cout << "Book3 Status: " << book3.getStatus() << std::endl;

    // Create a DVD instance
    DVD dvd1("The Matrix", "Lana Wachowski, Lilly Wachowski", "1999");
    std::cout << "\nDVD Title: " << dvd1.getTitle() << std::endl;
    std::cout << "DVD Director: " << dvd1.getDirector() << std::endl;
    std::cout << "DVD Release Year: " << dvd1.getReleaseYear() << std::endl;
    std::cout << "DVD Status: " << dvd1.getStatus() << std::endl;

    // Checkout the DVD
    std::cout << "\nChecking out the DVD...\n";
    dvd1.checkOut();
    std::cout << "DVD Status: " << dvd1.getStatus() << std::endl;

    // Return the DVD
    std::cout << "\nReturning the DVD...\n";
    dvd1.returnItem();
    std::cout << "DVD Status: " << dvd1.getStatus() << std::endl;

    // Demonstrate copy semantics for DVD
    std::cout << "\nCopying dvd1 to dvd2...\n";
    DVD dvd2 = dvd1; // Copy constructor
    std::cout << "DVD2 Title: " << dvd2.getTitle() << std::endl;
    std::cout << "DVD2 Status: " << dvd2.getStatus() << std::endl;

    // Demonstrate move semantics for DVD
    std::cout << "\nMoving dvd2 to dvd3...\n";
    DVD dvd3 = std::move(dvd2); // Move constructor
    std::cout << "DVD3 Title: " << dvd3.getTitle() << std::endl;
    std::cout << "DVD3 Status: " << dvd3.getStatus() << std::endl;

    return 0;
}
