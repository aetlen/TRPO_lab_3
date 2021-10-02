#include "basic_1.h"

/**
 @file basic_1.cpp
 @brief Файл базового класса 1
 @date 02-10-2021
 @version 1.0
 \par Использует классы
    @ref basic_1
 \par Содержит класс
    @ref basic_1
 */

basic_1::basic_1()
{

}

void basic_1::inc_counter(int a)
{
    basic_1::counter += a;
}

int basic_1::get_counter()
{
    return basic_1::counter;
}

void basic_1::null_counter()
{
    basic_1::counter = 0;
}
