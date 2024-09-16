#ifndef table_H
#define table_H

#include <iostream>
#include <string>
#include <limits>
#include <cstring>
#include <vector>
#include <fstream>
// #include <algorithm>


using std::string;
namespace table{
    struct Line {
        int n = 0; // количество элементов в строке матрицы
        int *data = nullptr; // массив элементов
    };

    // структура для задания матрицы
    struct Matr {
        int m = 0; // количество строк
        Line *lines = nullptr; // массив строк
    };
    void free_tabl(Matr &natr);


    int sum(int a, int b);
    Matr create(std::vector<std::vector<int>> data);
    
    Matr create(const int** data, size_t n, size_t m);

    Matr create(const int** data, size_t m, size_t* n);

    string output(const Matr& data);

    string output(const Matr& data, string style);

    string output(const Matr& data, const char* style);

}


#endif