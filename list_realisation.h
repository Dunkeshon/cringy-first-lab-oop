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
	~list_realisation();// deleting list
	void printFuncList();// print list
	void addEl(T *file);// i need to add already existing element to the list
	void deletion();// deleting the list
	void insertion(mylist *previous,T *adress_of_el); // inserting element that already exist after the one we put in function
	mylist* search_name(string key);// searching by name, returns adress of an element with such name
	mylist* Get_head();//getter
	mylist* Get_tail();//getter
	void delete_element(mylist *el_to_delete);// deleting an element
};

#include "list_realisation.hxx"