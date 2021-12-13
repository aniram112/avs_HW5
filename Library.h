//
// Created by Marina Roshchupkina on 10.12.2021.
//

#ifndef AVS_HW5_LIBRARY_H
#define AVS_HW5_LIBRARY_H

#include "Book.h"
#include "Shelf.h"
#include "Row.h"
#include <algorithm>
#include <vector>
#include <array>

// Класс библиотеки с рядами шкафов.
class Library {
    int rows_count_ = 20;
public:
    vector<Row> rows;

    Library(int row_count, int shelf_count, int book_count) {
        rows_count_ = row_count;
        //rows = new Row[this->rows_count_];
        for (int i = 0; i < rows_count_; ++i) {
            //rows[i] = Row(shelf_count, book_count);
        }
    }

};


#endif //AVS_HW5_LIBRARY_H
