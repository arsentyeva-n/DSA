//@author: Natalya Arsentyeva
#pragma once


// Класс итератора (интерфейс)
template <class T> 
class Iterator 
{
public:
    virtual T& get_data() const = 0;    // Оператор получения данных из элемента
    virtual bool hasNext() const = 0;     // Проверка, есть ли следующий элемент
    virtual void next() = 0;                // Следующий элемент
    virtual void reset() = 0;            // Сброс к началу
    virtual ~Iterator() = default;       // Деструктор
};