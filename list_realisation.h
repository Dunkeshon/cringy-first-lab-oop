//этот класс реализует двусвязный линейный список.
//имеет функции для: создания первого элемента,удаления списка,вывода списка на экран, добавления эллемента, вставка элемента после предыдущего
#pragma once
#include "mylist.h"


template <typename T>
class list_realisation
{
private:
	mylist<T> * head;
	mylist<T> * tail;
public:
	list_realisation(T FirstEl);//создание первого элемента
	~list_realisation();// удаляет список
	void printFuncList();// вывод списка
	void addEl(T val);// добавление элемента
	void deletion();// удаление списка
	void insertion(mylist<T> *previous,T val); // вставка эллемента после элемента,который мы передаем в функцию
};

#include "list_realisation.hxx"