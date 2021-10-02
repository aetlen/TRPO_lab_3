#include <QCoreApplication>
#include <basic_1.h>
#include <basic_2.h>
#include <iostream>

/**
 @mainpage Лабораторная #3
 @date 02-10-2021
 @version 1.0
 \par Использует классы
    @ref basic_1
    @ref basic_2
 \par Содержит файлы
    @ref basic_1.h
    @ref basic_2.h
    @ref basic_1.cpp
    @ref basic_2.cpp
 */

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    basic_1 test; // creating class

    /* tests */

    std::cout << "Counter is " << test.get_counter() << std::endl;
    test.inc_counter(5);
    std::cout << "Counter is " << test.get_counter() << std::endl;
    test.null_counter();
    std::cout << "Counter is " << test.get_counter() << std::endl;
    test.inc_counter(-3);
    std::cout << "Counter is " << test.get_counter() << std::endl;
    test.inc_counter(17);
    std::cout << "Counter is " << test.get_counter() << std::endl;
    test.null_counter();
    std::cout << "Counter is " << test.get_counter() << std::endl;
    return a.exec();
}
