//этот класс реализует двусвязный линейный список.
//имеет функции для: создания первого элемента,удаления списка,вывода списка на экран, добавления эллемента, вставка элемента после предыдущего
//список не удалять,при функциях удаления удалять элементы, но оставлять head=tail=nullptr;
#pragma once
#include "list_node.h"

 
class list_realisation
{
private:
	list_node * head;
	list_node * tail;
public:
	list_realisation();// initialisation with nullptr
	~list_realisation();// deleting list
	void printFuncList();// print list
	void addEl_Catalog( Catalog Element);// i need to copy and add already existing element to the list
	void addEl_File(file Element);// i need to copy and add already existing element to the list
	void deletion();// deleting the list
	void insertion_of_catalog(list_node *previous, Catalog element); // inserting element that already exist after the one we put in function
	void insertion_of_file(list_node *previous, file element);
																	 // i need to create similar method for list_node<file>
	list_node* search_name(string key);// searching by name, returns adress of an element with such name
	list_node* Get_head();//getter
	list_node* Get_tail();//getter
	void delete_element(list_node *el_to_delete);// deleting an element
};

#include "list_realisation.hxx"