#include "pch.h"



template <class T>list_realisation<T>::list_realisation(T FirstEl)
{
	head = new mylist<T>(FirstEl);//первый элемент списка-новый обьект mylist, вызывается конструктор
	tail = head;
}


template <class T>list_realisation<T>::~list_realisation()
{
	mylist<T> *current = head;
	mylist<T> *temp;

	while (current)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
}

template<typename T>
void list_realisation<T>::printFuncList()
{
	auto tmp = head;
	if (head != tail) {
		while (tmp) {
			cout << tmp->key << "->";
			tmp = tmp->next;
		}
		cout << tail->key;
	}
		else
		{
		cout << tmp->key;
		}
	
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
	auto current = head, temp;
	while (current)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
}

template<typename T>
void list_realisation<T>::insertion(mylist<T> *previous, T val)
{
	mylist<T> *p;//p-storring pointer to the next el
	mylist <T> * new_node = new mylist<T>;
	p = previous->next;
	previous->next = new_node;
	new_node->key = val;
	new_node->next = p;
	new_node->prev = previous;
	if (p != nullptr) {
		p->prev = new_node;
	}
}
