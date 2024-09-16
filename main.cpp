#include "dialog.hpp"
#define OPTION "введите опцию:\n1. непрямоугольная таблица без стиля\n2. прямоугольная матрица через массив без стиля\n\
3. прямоугольная матрица через вектор без стиля\n4. непрямоугольная таблица со стилем\n5. прямоугольная матрица через массив со стилем\n\
6. прямоугольная матрица через вектор со стилем\n"

using namespace dialog;
int main()
{
	try{
		void (*operations[6])() = {dialog_1,dialog_2,dialog_3,dialog_4,dialog_5,dialog_6};
		int n;
		printf(OPTION);
		while ((n= getNum<int>(0,6))){
			if (n > 0 && n <= 6) {
				operations[n-1]();	
			}else {
				printf("not cool\n");
			}
			printf(OPTION);
		}
	}
	catch(const std::bad_alloc &ba) { // в случае ошибок выделения памяти
		std::cerr << "Not enough memory" << std::endl;
		return 1;
	}
	catch(const std::exception &e) { // в случае прочих исключений
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
