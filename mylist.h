#pragma once
#include "FILE.h"

class mylist
{
public:
	mylist *next;
	mylist *prev;
	file info;// class with all info

	mylist(file* val);//нужно избавится от этого и оставить только по умолчанию
	mylist();// нужно реализовать функцию заполнения и создания файла
	~mylist();

};

#include "mylist.hxx"