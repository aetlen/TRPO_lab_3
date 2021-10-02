#ifndef BASIC_1_H
#define BASIC_1_H

/**
 @file basic_1.h
 @brief Заголовочный файл базового класса 1
 @date 02-10-2021
 @version 1.0
 \par Использует классы
    @ref basic_1
 \par Содержит класс
    @ref basic_1
 */

/// Базовый класс
/** Содержит счетчик и методы для работы с ним
 */
class basic_1
{
public:
    /// Конструктор по умолчанию
    /** Создает класс без инициации полей
     */
    basic_1();

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


#endif // BASIC_1_H
