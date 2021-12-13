//
// Created by Marina Roshchupkina on 10.12.2021.
//

#ifndef AVS_HW5_SHELF_H
#define AVS_HW5_SHELF_H


#include "Book.h"
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

// Класс  шкафа с нкигами.
class Shelf {

    int catalog_count_ = 20;
public:
    vector<Book> catalogs;

    Shelf() {
        for (int i = 0; i < catalog_count_; ++i) {
            Book book;
            catalogs.push_back(book);
        }
    }

    Shelf(int books_count) {
        catalog_count_ = books_count;
        for (int i = 0; i < catalog_count_; ++i) {
            Book book;
            catalogs.push_back(book);
        }
    }

};


#endif //AVS_HW5_SHELF_H
