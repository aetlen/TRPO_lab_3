#include "basic_2.h"

/**
 @file basic_2.cpp
 @brief Файл базового класса 2
 @date 02-10-2021
 @version 1.0
 \par Использует классы
    @ref basic_2
 \par Содержит класс
    @ref basic_2
 */

basic_2::basic_2()
{

}

void basic_2::inc_counter(int a)
{
    basic_2::counter += a;
}

int basic_2::get_counter()
{
    return basic_2::counter;
}

void basic_2::null_counter()
{
    basic_2::counter = 0;
}
