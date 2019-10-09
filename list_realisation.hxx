#include "pch.h"



template <class T>list_realisation<T>::list_realisation(file *FirstEl)//создание первого элемента
{
	head = FirstEl;//первый элемент списка 
	tail = head;
}


template <class T>list_realisation<T>::~list_realisation()// удаляет список
{
	mylist *current = head;
	mylist *temp;

	while (current)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
}

template<class T>
void list_realisation<T>::printFuncList()// вывод списка
{
	auto tmp = head;
	if (head != tail) {
		while (tmp) {
			cout << tmp->info.print_info() << endl;
			cout << "######################" << endl;
			tmp = tmp->next;
		}
		cout << tail->info.print_info();
	}
		else
		{
		cout << tmp->info.print_info();
		}
	
}

template<class T>
void list_realisation<T>::addEl()// добавление элемента
{
	mylist *temp = new mylist();
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

template<class T>
void list_realisation<T>::deletion()// удаление списка
{
	auto current = head, temp;
	while (current)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
}

template<class T>
void list_realisation<T>::insertion(mylist *previous) // вставка эллемента после элемента,который мы передаем в функцию
{
	// нужно вызвать конструктор нового элемента и заполнить его данными
	mylist *p;//p-storring pointer to the next el
	mylist  * new_node = new mylist;
	p = previous->next;
	previous->next = new_node;
	new_node->next = p;
	new_node->prev = previous;
	if (p != nullptr) {
		p->prev = new_node;
	}
}
