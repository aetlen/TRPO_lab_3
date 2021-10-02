#ifndef BASIC_2_H
#define BASIC_2_H


/**
 @file basic_2.h
 @brief Заголовочный файл базового класса 2
 @date 02-10-2021
 @version 1.0
 \par Использует классы
    @ref basic_2
 \par Содержит класс
    @ref basic_2
 */

/// Базовый класс
/** Содержит счетчик и методы для работы с ним
 */
class basic_2
{
public:
    /// Конструктор по умолчанию
    /** Создает класс без инициации полей
     */
    basic_2();

    /** \brief Увеличивает счетчик
      @param a значение, на которое изменяется счетчик */
    void inc_counter(int a);

    /** \brief Показывает текущее значение счетчика
      @return текущее значение счетчика */
    int get_counter();

    /** \brief Обнуляет счетчик*/
    void null_counter();

private:
int counter = 0; ///сам счетчик
};

#endif // BASIC_2_H
