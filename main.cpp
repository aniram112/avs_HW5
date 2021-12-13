#include <iostream>
#include "omp.h"
#include "Library.h"
#include "Book.h"
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

unsigned int const_rows = 20;
unsigned int const_shelf = 20;
unsigned int const_books = 20;

Library lib = Library(const_rows, const_shelf, const_books);


// Компаратор для книг.
bool comparator(const Book lhs, const Book rhs) {
    return lhs.num < rhs.num;
}

// Сортировка каталога.
void sortCatalog(int row, int shelf) {
    sort(lib.rows[row].shelfs[shelf].catalogs.begin(), lib.rows[row].shelfs[shelf].catalogs.end(), comparator);
}

int main(int args, const char *argv[]) {
    clock_t start_time = clock();

    // Тот самый портфель задач.
    vector<std::pair<int, int> > bag_of_tasks;
    vector<int> allbooks;
    int input_rows;
    int input_shelfs;
    int input_books;
    cout << "Enter number of rows, number of bookshelves in a row, number of books in one bookshelf (between 0 and 20)"
         << endl;
    cin >> input_rows >> input_shelfs >> input_books;

    if (input_rows <= 0 || input_rows > 20 || input_shelfs <= 0 || input_shelfs > 20 || input_books <= 0 ||
        input_books > 20) {
        return 1;
    }

    const_rows = input_rows;
    const_shelf = input_shelfs;
    const_books = input_books;

    cout << "Library before restoring" << endl;
    //Library lib = Library(100, 100, 100);
    lib = Library(const_rows, const_shelf, const_books);

    // Библиотека до восстановления.
    for (int row = 0; row < const_rows; ++row) {
        cout << "Row#: " << row << endl;
        lib.rows.push_back(Row());
        for (int shelf = 0; shelf < const_shelf; ++shelf) {
            cout << "Shelf: " << shelf << endl;
            cout << "Books:" << endl;
            lib.rows[row].shelfs.push_back(Shelf(const_books));
            for (int book = 0; book < const_books; ++book) {
                cout << lib.rows[row].shelfs[shelf].catalogs[book].num << " ";
                // Закидываем задачу в портфель.
                bag_of_tasks.push_back(pair<int, int>(row, shelf));
            }
            cout << endl;
        }
    }

    cout << endl << endl << endl;

    //sort(lib.rows[0].shelfs[0].catalogs.begin(), lib.rows[0].shelfs[0].catalogs.end(), comparator);


// Возможно потоков многовато но даже самый большой случай работает.
    try {
#pragma omp parallel shared (bag_of_tasks, const_rows, const_shelf) num_threads(const_rows)
        {
#pragma omp for nowait
            for (int i = 0; i < const_rows; i++) {
                for (int j = 0; j < const_shelf; j++) {
                    pair<int, int> task = bag_of_tasks.back();
                    cout << omp_get_thread_num() << " ";
                    // Поток взял задачу на выполнение.
                    sortCatalog(task.first, task.second);
                    // Задачу удалили.
#pragma omp critical
                    bag_of_tasks.pop_back();

                }
            }
        }

        // Библиотека после восстановления.
        cout << "\nRestored Library" << endl;
        for (int row = 0; row < const_rows; ++row) {
            cout << "Row#: " << row << endl;
            for (int shelf = 0; shelf < const_shelf; ++shelf) {
                cout << "Shelf : " << shelf << endl;
                cout << "Books: " << endl;
                for (int book = 0; book < const_books; ++book) {
                    cout << lib.rows[row].shelfs[shelf].catalogs[book].num << " ";
                }
                cout << endl;
            }
            cout << endl;
        }


// Собираем каталог.
#pragma omp parallel shared (allbooks, const_rows, const_shelf, const_books) num_threads(const_rows)
        {
#pragma omp for nowait
            for (int row = 0; row < const_rows; ++row) {
                for (int shelf = 0; shelf < const_shelf; ++shelf) {
                    for (int book = 0; book < const_books; ++book) {
#pragma omp critical
                        allbooks.push_back(lib.rows[row].shelfs[shelf].catalogs[book].num);
                    }
                }
            }
        }
    } catch (...) {
        cout << "Try again";
    }
    sort(allbooks.begin(), allbooks.end());
    cout << "\nRestored catalog" << endl;
    for (int book = 0; book < allbooks.size(); ++book) {
        cout << allbooks[book] << " ";
    }

    cout << endl<<"Size: " << allbooks.size() << endl;

    clock_t end_time = clock();
    double seconds = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    cout << seconds << "s \n";
    return 0;
}