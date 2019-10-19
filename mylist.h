//this is a node class
// i think i should make it template because i have to make the list of catalogs also
#pragma once
#include "File.h"

class mylist
{
public:
	mylist *next;
	mylist *prev;
	file info;// class with all info

	
	mylist();// нужно реализовать функцию заполнения и создания файла
	~mylist();

};

#include "mylist.hxx"