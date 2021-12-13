//
// Created by Marina Roshchupkina on 10.12.2021.
//

#ifndef AVS_HW5_BOOK_H
#define AVS_HW5_BOOK_H


#include <cstdlib>

// Класс книги, книга определеляется ее артикулом (номером).
class Book {

public:
    int num;

    Book() {
        num = 100000 + (rand() % static_cast<int>(999999 - 100000 + 1));
    }
};


#endif //AVS_HW5_BOOK_H
