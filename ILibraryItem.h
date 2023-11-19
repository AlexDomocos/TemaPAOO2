#pragma once
#include "MyString/MyString.h"

namespace library {

    class ILibraryItem {
    public:
        virtual void checkOut() = 0;
        virtual void returnItem() = 0;
        virtual MyString getTitle() const = 0;
    };

}
