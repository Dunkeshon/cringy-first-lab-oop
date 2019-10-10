//этот класс реализует двусвязный линейный список.
//имеет функции для: создания первого элемента,удаления списка,вывода списка на экран, добавления эллемента, вставка элемента после предыдущего
#pragma once
#include "mylist.h"


template <class T>
class list_realisation
{
private:
	mylist * head;
	mylist * tail;
public:
	list_realisation();// initialisation with nullptr
	~list_realisation();// удаляет список
	void printFuncList();// вывод списка
	void addEl();// добавление элемента НУЖНО ПЕРЕДАТЬ КЛАСС ПО УКАЗАТЕЛЮ
	void deletion();// удаление списка
	void insertion(mylist *previous); // вставка эллемента после элемента,который мы передаем в функцию
	mylist* search_name(string key);// поиск по имени, возвращает адрес элемента с этим критерием
	mylist* Get_head();
	mylist* Get_tail();
};

#include "list_realisation.hxx"