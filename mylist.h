#pragma once

template <class T>
class mylist
{
private:
	mylist *next;
	mylist *prev;
	T key;
public:
	mylist(T val);
	~mylist();
	/*void print_list();*/
};