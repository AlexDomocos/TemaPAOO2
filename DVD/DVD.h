#pragma once
#include "../MyString/MyString.h"
#include "../ILibraryItem.h"

namespace library {

    class DVD : public ILibraryItem {
    private:
        MyString title;
        MyString director;
        MyString releaseYear;
        MyString status;

    public:
        DVD(const char *title, const char *director, const char *releaseYear, const char *status = "available");
        DVD(const DVD &other);
        DVD &operator=(const DVD &other);
        DVD(DVD&& other);

        DVD &operator=(DVD &&other);

        virtual MyString getTitle() const override;
        virtual void checkOut() override;
        virtual void returnItem() override;

        MyString getDirector() const;
        MyString getReleaseYear() const;
        MyString getStatus() const;
    };
}
