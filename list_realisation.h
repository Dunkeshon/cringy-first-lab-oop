//этот класс реализует двусвязный линейный список.
//имеет функции для: создания первого элемента,удаления списка,вывода списка на экран, добавления эллемента, вставка элемента после предыдущего
//список не удалять,при функциях удаления удалять элементы, но оставлять head=tail=nullptr;
#pragma once
#include "list_node.h"

//T=Catalog
template <class T> 
class list_realisation
{
private:
	list_node<T> * head;
	list_node<T> * tail;
public:
	list_realisation();// initialisation with nullptr
	~list_realisation();// deleting list
	void printFuncList();// print list
	void addEl( T *Element);// i need to copy and add already existing element to the list
	void deletion();// deleting the list
	void insertion(list_node<T> *previous, T *element); // inserting element that already exist after the one we put in function
	list_node<T>* search_name(string key);// searching by name, returns adress of an element with such name
	list_node<T>* Get_head();//getter
	list_node<T>* Get_tail();//getter
	void delete_element(list_node<T> *el_to_delete);// deleting an element
};

#include "list_realisation.hxx"