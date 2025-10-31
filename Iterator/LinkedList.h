//@author: Natalya Arsentyeva
#pragma once


#include <iostream>
#include "Iterator.h"

using namespace std;


/// Узел списка
template <class T>
class Node 
{
public:
    T data;
    Node<T>* next;

    // конструктор с параметром
    Node(const T& data1) {
        this->data = data1;
        next = nullptr;
    }
};

/// Класс LinkedList (Связный список)
template <class T>
class LinkedList 
{
private:
    Node<T>* head; // Указатель голову списка

public:
   
    LinkedList() {  head = nullptr; } // Конструктор по умолчанию
   ~LinkedList();                     // Деструктор

   void addNode(T value);              // Добавление элемента в конец списка
   void removeNode(T value);           // Удаление узла
   void print();                       // Вывод элементов списка
   Node<T>* getHead() const;
};


// Возврат указателя на голову списка
template <class T>
Node<T>* LinkedList<T>::getHead() const {
    return head;
}

// Добавление элемента в конец списка
template <class T>
void LinkedList<T>::addNode(T value) 
{
    Node<T>* newNode = new Node<T>(value);    // Создаем новый узел

    if (head == nullptr) {          // Если список пуст, новый элемент становится головой
        head = newNode;
    }
    else { 
        Node<T>* temp = head;
        while (temp->next != nullptr) { // Пока не достигнем конца списка
            temp = temp->next; 
        }
        temp->next = newNode;           // Добавляем узел
    }
}

// Удаление узла
template <class T>
void LinkedList<T>::removeNode(T value) 
{
     if (head == nullptr) return; 

    // Если значение в голове списка
    if (head->data == value) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Ищем элемент внутри списка
    Node<T>* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    // Если нашли нужный элемент
    if (current->next != nullptr) {
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// Деструктор, освобождение памяти 
template <class T>
LinkedList<T>::~LinkedList() 
{
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        delete current;  
        current = nextNode;
    }
}

// Печать всех элементов
template <class T>
void LinkedList<T>::print() 
{
    Node<T>* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next; // переходим к следующему узлу
    }
    cout << endl;
}


/// Итератор для LinkedList
template <class T>
class LinkedListIterator : public Iterator<T> {
private:
    Node<T>* current;  // Текущий элемент
    Node<T>* start;    // Начало списка, чтобы можно было сбросить

public:
    // Конструктор, получающий указатель на голову списка
    // explicit — запрещает неявное преобразование типов
    explicit LinkedListIterator(Node<T>* head1) {
        start = head1;
        current = start;
    }

    // Проверяем, есть ли следующий элемент
    bool hasNext() const override {
        return current != nullptr;
    }

    // Возвращаем ссылку на данные текущего элемента
    T& get_data() const override {
        if (current != nullptr) {
            return current->data;
        }
    }

    // Возвращаем значение текущего элемента и двигаемся дальше
   void next() override {
        if (current != nullptr) {
            current = current->next; // переходим к следующему элементу
        }
        else {
            cout << "Конец списка" << endl;
        }
    }

    // Сброс итератора к началу списка
    void reset() override {
        current = start;
    }
};