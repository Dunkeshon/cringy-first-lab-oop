//этот класс реализует двусвязный линейный список.
//имеет функции для: создания первого элемента,удаления списка,вывода списка на экран, добавления эллемента, вставка элемента после предыдущего
//список не удалять,при функциях удаления удалять элементы, но оставлять head=tail=nullptr;
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
	void addEl();// добавление элемента 
	void deletion();// удаление списка
	void insertion(mylist *previous); // вставка эллемента после элемента,который мы передаем в функцию
	mylist* search_name(string key);// поиск по имени, возвращает адрес элемента с этим критерием
	mylist* Get_head();//getter
	mylist* Get_tail();//getter
	void delete_element(mylist *el_to_delete);// удаление элемента
};

#include "list_realisation.hxx"