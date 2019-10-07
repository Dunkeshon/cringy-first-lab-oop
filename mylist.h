#pragma once

template <class T>
class mylist
{
public:
	mylist *next;
	mylist *prev;
	T key;

	mylist(T val);
	mylist();
	~mylist();

};

#include "mylist.hxx"