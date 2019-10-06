#include "pch.h"
#include "list_realisation.h"


template <class T>list_realisation<T>::list_realisation(T FirstEl)
{
	head = new mylist<T>(FirstEl);//первый элемент списка-новый обьект mylist, вызывается конструктор
	tail = head;
}


template <class T>list_realisation<T>::~list_realisation()
{
	while (head)
	{
		tail = head->next;
		delete head;
		head = tail;
	}
}

template<typename T>
void list_realisation<T>::printFuncList()
{
	head->printList();
}

template<typename T>
void list_realisation<T>::addEl(T val)
{
	mylist<T> *temp = new mylist<T>(val);
	if (head == nullptr) {
		head = temp;
		tail = temp;
	}
	else
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
}

template<typename T>
void list_realisation<T>::deletion()
{
	while (head)
	{
		tail = head->next;
		delete head;
		head = tail;
	}
}

template<typename T>
void list_realisation<T>::insertion(mylist<T> *previous, T val)
{
	mylist<T> *p;//p-storring pointer to the next el
	mylist <T> * temp = new mylist;
	p = previous->next;
	previous->next = temp;
	temp->key = val;
	temp->next = p;
	temp->prev = previous;
	if (p != nullptr) {
		p->prev = temp;
	}
}

