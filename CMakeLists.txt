# установка версии CMake
cmake_minimum_required(VERSION 3.16)
find_package(Catch2 3 REQUIRED)

# название проекта (обязательно)
project(lab12)

# установка стандарта языка - C++20
set(CMAKE_CXX_STANDARD 23)

add_compile_options(-fprofile-arcs -ftest-coverage)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# создание библиотеки prog1

link_libraries(gcov)

add_library(table table.hpp table.cpp)
link_libraries(table)
add_library(dialog dialog.hpp dialog.cpp)
link_libraries(dialog)






add_executable(main main.cpp)

# add_executable(tests test.cpp)

# target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)





# установка флагов компилятора: CMAKE_CXX_FLAGS += -Wall -Wextra

# include(CTest)
# enable_testing()

# # подключение библиотеки prog1 ко всем таргетам, создаваемым далее
# # альтернатива: target_link_libraries(main prog1)
# target_link_libraries(main prog2 prog1 [PRIVATE Catch2::Catch2])
# #  target_link_libraries(main prog1)

# # создание исполняемого файла

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})






# include(CPack)
# для сборки из консоли:
#
# mkdir build   # создание директории для файлов сборки
# cd build      # переход в директорию сборки
# cmake ..      # генерация файлов сборки на основе CMakeLists.txt
# make          # сборка проекта