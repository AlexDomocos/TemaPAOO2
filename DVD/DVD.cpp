#include "DVD.h"

namespace library {

    DVD::DVD(const char *title, const char *director, const char *releaseYear, const char *status)
            : title(title), director(director), releaseYear(releaseYear), status(status) {}

    DVD::DVD(const DVD &other)
            : title(other.title), director(other.director), releaseYear(other.releaseYear), status(other.status) {}

    DVD &DVD::operator=(const DVD &other) {
        if (this != &other) {
            title = other.title;
            director = other.director;
            releaseYear = other.releaseYear;
            status = other.status;
        }
        return *this;
    }

    DVD &DVD::operator=(DVD &&other) {
        if (this != &other) {
            title = std::move(other.title);
            director = std::move(other.director);
            releaseYear = std::move(other.releaseYear);
            status = std::move(other.status);

            // Optionally, set 'other' to a default state
        }
        return *this;
    }

    DVD::DVD(DVD&& other)
            : title(other.title),
              director(other.director),
              releaseYear(other.releaseYear),
              status(other.status) {}

    MyString DVD::getTitle() const {
        return title;
    }

    MyString DVD::getDirector() const {
        return director;
    }

    MyString DVD::getReleaseYear() const {
        return releaseYear;
    }

    MyString DVD::getStatus() const {
        return status;
    }

    void DVD::checkOut() {
        status = "checked out";
    }

    void DVD::returnItem() {
        status = "available";
    }

}
