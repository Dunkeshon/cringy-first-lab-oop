#include "pch.h"



template <class T> mylist <T>::mylist(T val)
{
	next = nullptr;//нужно имя переменной класса а не класса
	prev = nullptr;
	key = val;
}

template <class T> mylist <T>::mylist()
{
	next = nullptr;//нужно имя переменной класса а не класса
	prev = nullptr;
	key = T();
}


template <class T> mylist <T>::~mylist()
{

}
