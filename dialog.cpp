#include "dialog.hpp"


using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using namespace table;

namespace dialog{
    

    void free_data(int **natr, int n){
        for(int i = 0; i<n;i++) delete [] natr[i];
        delete [] natr;
    }

    /**
     * @brief 
     * 
     * @return string 
     */
    string getstr() {
        string a;
        while(true) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(cin, a, '\n');
            if(std::cin.eof()) // обнаружен конец файла
                throw std::runtime_error("Failed to read number: EOF");
            else if(std::cin.bad()) // обнаружена невосстановимая ошибка входного потока
                throw std::runtime_error(std::string("Failed to read number: ") + strerror(errno));
            // прочие ошибки (неправильный формат ввода) либо число не входит в заданный диапазон
            else if(std::cin.fail()) {
                std::cin.clear(); // очищаем флаги состояния потока
                // игнорируем все символы до конца строки
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "You are wrong; repeat please!" << std::endl;
            }
            else // успешный ввод
                return a;
        }
    }


    void dialog_1(){
        cout << "введите количество строк:" << std::endl;
		int i = -1;
        size_t *m = nullptr;
		int** data = nullptr;
        try{
            size_t n = getNum<size_t>(0);
            m = new size_t[n];
            data = new int*[n];
            int k = (int) n;
            for(i = 0;i<k;i++){
                cout << "введите размер строчки, а потом и саму строку" << std::endl;
                data[i] = nullptr;
                m[i] = getNum<size_t>(0);
				data[i] = new int[m[i]];
                for(size_t j = 0; j<m[i]; j++){
					data[i][j] = getNum<int>();
				}
            }
			const int** data1 = const_cast<const int **>(data);
			Matr matr = create(data1, n, m);
			cout << "ссылка на ваш файл: "<<output(matr)<< endl;
			free_tabl(matr);
            delete[] m;
            free_data(data, n);
        }catch(...){
            if (m) delete[] m;
            if(data){
    			for(int j = i; j>=0; j--) delete[] data[j];
	        	delete[] data;
            }
            throw;
        }
    }

    void dialog_2(){
        cout << "введите количество строк и строчек:" << std::endl;
		int** data = nullptr;
		size_t i = 0;
        try{
            size_t n = getNum<size_t>(0);
            size_t m = getNum<size_t>(0);
            data = new int*[n];
            for(i = 0;i<n;i++){
                cout << "введите строчку" << std::endl;
                data[i] = new int[m];
                for(size_t j = 0;j<m; j++){
					data[i][j] = getNum<int>();
				}
            }
			const int ** data1 = const_cast<const int **>(data);
			Matr matr = create(data1, n, m);
			cout << "ссылка на ваш файл: "<<output(matr)<< endl;
            free_tabl(matr);
            free_data(data, n);
        }catch(...){
            if(data){
    			for(int j = i; j>=0; j--) delete[] data[j];
	        	delete[] data;
            }
            throw;
        }
    }

    void dialog_3(){
        cout << "введите количество строк и строчек:" << std::endl;
		size_t i = 0;
        try{
            size_t n = getNum<size_t>(0);
            size_t m = getNum<size_t>(0);
			vector<vector<int> > data(n, vector<int>(m,0));
            for(i = 0;i<n;i++){
                cout << "введите строчку" << std::endl;
                for(size_t j = 0;j<m; j++){
					data[i][j] = getNum<int>();
				}
            }
			Matr matr = create(data);
			cout << "ссылка на ваш файл: "<<output(matr)<< endl;
            free_tabl(matr);
        }catch(...){
            throw;
        }
    }

	void dialog_4(){
        cout << "введите количество строк:" << std::endl;
		int i = -1;
		int** data = nullptr;
        size_t *m = nullptr;
        try{
            size_t n = getNum<size_t>(0);
            m = new size_t[n];
            data = new int*[n];
			cout << "введите стиль"<< endl;
			string style = getstr();
			int k = (int)n;
            for(i = 0; i<k; i++){
                cout << "введите размер строчк, а потом и саму строку" << std::endl;
                data[i] = nullptr;
                m[i] = getNum<size_t>(0);
				data[i] = new int[m[i]];
                for(size_t j = 0;j<m[i]; j++){
					data[i][j] = getNum<int>();
				}
            }
			const int** data1 = const_cast<const int **>(data);
			Matr matr = create(data1, n, m);
			cout << "ссылка на ваш файл: "<<output(matr, style)<< endl;
			free_tabl(matr);
            if(m) delete[] m;
            free_data(data, n);
        }catch(...){
            if(m) delete[] m;
            if(data){
    			for(int j = i; j>=0; j--) delete[] data[j];
	        	delete[] data;
            }
            throw;
        }
    }

    void dialog_5(){
        cout << "введите количество строк и строчек:" << std::endl;
		int** data = nullptr;
		size_t i = 0;
        try{
            size_t n = getNum<size_t>(0);
            size_t m = getNum<size_t>(0);
            data = new int*[n];
			cout << "введите стиль"<< endl;
            string style1 = getstr();
			const char* style = style1.c_str();
            for(i = 0;i<n;i++){
                cout << "введите строчку" << std::endl;
                data[i] = new int[m];
                for(size_t j = 0;j<m; j++){
					data[i][j] = getNum<int>();
				}
            }
			const int ** data1 = const_cast<const int **>(data);
			Matr matr = create(data1, n, m);

			cout << "ссылка на ваш файл: "<<output(matr, style)<< endl;
            free_data(data, n);
            free_tabl(matr);
        }catch(...){
            if(data){
    			for(int j = i; j>=0; j--) delete[] data[j];
	        	delete[] data;
            }
            throw;
        }
    }

    void dialog_6(){
        cout << "введите количество строк и строчек:" << std::endl;
		int i = 0;
        try{
            int n = getNum<int>(0);
            int m = getNum<int>(0);
			cout << "введите стиль"<< endl;
			string style = getstr();
			vector<vector<int> > data(n, vector<int>(m,0));
            for(i = 0;i<n;i++){
                cout << "введите строчку" << std::endl;
                for(int j = 0;j<m; j++){
					data[i][j] = getNum<int>();
				}
            }	
			Matr matr = create(data);
			cout << "ссылка на ваш файл: "<<output(matr, style)<< endl;
            free_tabl(matr);
        }catch(...){    
            throw;
        }
    }

	
}