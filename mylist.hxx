#include "pch.h"
#include "mylist.h"
/*Это "node" класс. Имеется конструктор по умолчанию и конструктор, который задает значение в поле списка*/


template <class T> mylist <T>::mylist(T val)
{
	next = nullptr;
	prev = nullptr;
	key = val;
}

template <class T> mylist <T>::mylist()
{
	next = nullptr;
	prev = nullptr;
	key = T();
}


template <class T> mylist <T>::~mylist()
{

}
