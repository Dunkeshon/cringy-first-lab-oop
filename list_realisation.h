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
	~list_realisation();
	void printFuncList();
	void addEl(T val);

};

