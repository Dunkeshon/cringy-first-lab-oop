#pragma once
#include "mylist.h"

template <typename T>
class list_realisation
{
private:
	mylist<T> * begin;
	mylist<T> * end;
public:
	list_realisation(T FirstEl);
	~list_realisation();
	void printFuncList();
};

