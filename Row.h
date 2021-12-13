//
// Created by Marina Roshchupkina on 10.12.2021.
//

#ifndef AVS_HW5_ROW_H
#define AVS_HW5_ROW_H

#include "Book.h"
#include "Shelf.h"
#include <algorithm>
#include <vector>
#include <array>

// Класс одного ряда библиотеки со шкафами в нем.
class Row {
    int shelfs_count_ = 20;
public:
    vector<Shelf> shelfs;

    Row() {
        //shelfs = new Shelf[this->shelfs_count_];
        for (int i = 0; i < shelfs_count_; ++i) {
            //shelfs[i] = Shelf(100);
        }
    }

    Row(int shelf_count, int book_count) {
        shelfs_count_ = shelf_count;
        //shelfs = new Shelf[this->shelfs_count_];
        for (int i = 0; i < shelfs_count_; ++i) {
            //shelfs[i] = Shelf(book_count);
        }
    }

};


#endif //AVS_HW5_ROW_H
