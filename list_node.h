//this is a node class
// i think i should make it template because i have to make the list of catalogs also
#pragma once
#include "File.h"

class list_node
{
public:
	list_node *next;
	list_node *prev;
	file info;// class with all info

	
	list_node();// нужно реализовать функцию заполнения и создания файла
	~list_node();

};

#include "list_node.hxx"