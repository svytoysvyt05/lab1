#include "table.hpp"

using std::vector;
using std::ofstream;
using std::endl;

namespace table{

/**
 * @brief очистка матрицы
 * 
 * @param natr Матрицу которую надо удалить
 */
    void free_tabl(Matr &natr){
        for(int i = 0; i<natr.m;i++) delete [] natr.lines[i].data;
        delete [] natr.lines;
    }


/**
 * @brief создание из контейнера матрицу с описанной таблицей
 * 
 * @param data1 массив с числами которые будут вулючены в таблицу
 * @param n кольчество строк в массиве
 * @param m количестыо числев в каждой строке
 * @return Matr Матрица которая описывает таблицу
 */
    Matr create(const int** data1, size_t n, size_t m){
        try{
            if(!data1) throw std::runtime_error("null data");
            vector<vector<int> > data(n, vector<int>(m,0));
            for(size_t i = 0; i <n;i++){
                for (size_t g = 0; g<m; g++) data[i][g] = data1[i][g];
            }
            return create(data);
        }
        catch(...){
            throw;
        }
    }
  
/**
 * @brief создание из контейнера матрицу с описанной таблицей
 * 
 * @param data1 массив с числами которые будут вулючены в таблицу
 * @param m кольчество строк в массиве
 * @param n массив количеств числев в каждой строке
 * @return Matr Матрица которая описывает таблицу
 */
    Matr create(const int** data1, size_t m, size_t* n){
        try{
            if(!data1) throw std::runtime_error("null data");
            vector<vector<int> > data;
            for(size_t i = 0; i <m;i++){
                data.push_back(vector<int>(n[i], 0));
                for (size_t g = 0; g<n[i]; g++) data[i][g] = data1[i][g];
            }
            return create(data);
        }
        catch(...){
            throw;
        }
    }
/**
 * @brief создание из контейнера матрицу с описанной таблицей
 * 
 * @param data вектор с числами которые будут вулючены в таблицу
 * @return Matr Матрица которая описывает таблицу
 */

    Matr create(vector<vector<int>> data){
        Matr res;
        try{
            size_t size = data.size();
            res.lines = new Line[size];
            for(size_t i = 0;i<size; i++){
                Line &line = res.lines[i];
                line.n = data[i].size();
                line.data = new int[line.n];
                res.m++;
                for(int j = 0; j < line.n; j++) {
                    line.data[j] = data[i][j];
                }               

            }
        }
        catch(...){
            if(res.m) free_tabl(res);
            throw;
        }
        return res;
    }
/**
 * @brief функция которая создает файл html с описанной таблицей без стиля
 * 
 * @param data Матрица которая описывает таблицу
 * @return string ссылка на файл html описывающий таблицу
 */
    string output(const Matr& data){
        return output(data, nullptr);

    }
    /**
     * @brief функция которая создает файл html с описанной таблицей со стилем
     * 
     * @param data Матрица которая описывает таблицу
     * @param style1 стиль который записывается в файл
     * @return string ссылка на файл html описывающий таблицу
     */

    string output(const Matr& data, string style1){
        const char* style = style1.c_str();
        return output(data, style);

       }
    /**
     * @brief функция которая создает файл html с описанной таблицей со стилем

    * 
    * @param data Матрица которая описывает таблицу
    * @param style стиль который записывается в файл
    * @return string ссылка на файл html описывающий таблицу
    */
    string output(const Matr& data, const char* style){
        string msg = "test";
		string name = msg + ".html";
        std::ofstream file;
        file.open(name);
        file <<"<!DOCTYPE html>"<<endl;
        file <<"<html>"<<endl;
        file <<"<head>"<<endl;
        if (style) {
            file <<"<style>"<<endl;
            file << "table, th, td {" << endl;
            file << style << ";" << endl;
            file << "}" << endl;
            file << "</style>" << endl;
        }
        file <<"</head>"<<endl<<endl;
        file <<"<body>"<<endl;
        file <<"<table>"<<endl;
        file <<""<<endl;
        if(data.m){
            file << "\t<tr>"<<endl;
            for (int j = 0; j < data.lines[0].n; j++)
            {
                file <<"\t\t<th>"<< data.lines[0].data[j]<<"</th>"<<endl;
            
            }
            
            file << "\t</tr>"<<endl;
        }
        for(int i = 1; i < data.m;i++){
            file << "\t<tr>"<<endl;
            for (int j = 0; j < data.lines[i].n; j++)
            {
                file <<"\t\t<td>"<< data.lines[i].data[j]<<"</td>"<<endl;
            
            }
            
            file << "\t</tr>"<<endl;
        }
        file <<"</table>"<<endl<<endl;
        file <<"</body>"<<endl;
        file <<"</html>"<<endl;
        file.close(); 
        string res = "file:./"+ name;
        return res;
    }

}


