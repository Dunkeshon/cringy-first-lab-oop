#include "pch.h"
#include "list_realisation.h"



template <class T>list_realisation<T>::list_realisation()//создание первого элемента
{
	head = tail=nullptr;//первый элемент списка 
	
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
		while (tmp){
			 tmp->info.print_info() ;
			cout << "######################" << endl;
			tmp = tmp->next;
		} 
		
	}
	else if ((head == tail)&&(head!=nullptr))
	{
		tmp->info.print_info();
	}
	else
	{
		cout << "list is empty" << endl;
	}
}

template<class T>
void list_realisation<T>::addEl()// добавление элемента
{
	mylist *temp = new mylist();
	temp->info.set_info();
	// change set_info to seting info 
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
	auto current = head;
	auto temp = head;
	while (current)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
	head = nullptr;
	tail = nullptr;
}

template<class T>
void list_realisation<T>::insertion(mylist *previous) // вставка эллемента после элемента,который мы передаем в функцию
{
	 if (previous->next == nullptr)
	{
		addEl();
		return;
	}
	else {
		// нужно вызвать конструктор нового элемента и заполнить его данными- done
		mylist *p;//p-storring pointer to the next el
		mylist  * new_node = new mylist;
		new_node->info.set_info();
		p = previous->next;
		previous->next = new_node;
		new_node->next = p;
		new_node->prev = previous;
		if (p != nullptr) {
			p->prev = new_node;
		}
	}
}

template<class T>
mylist* list_realisation<T>::search_name(string key)
{
	mylist *temp = new mylist;
	temp = head;
	while (temp) {
		if (temp->info.Get_name() == key)
		{
			return temp;
		}
		else {
			temp = temp->next;
		}
	}
	cout << "file with this name don't exist" << endl;
	// нужно пройти по списку и вернуть адресс
	return nullptr;
}

template<class T>
 mylist * list_realisation<T>::Get_head()
{

	return head;
}

 template<class T>
 mylist * list_realisation<T>::Get_tail()
 {
	 return tail;
 }

 template<class T>
 void list_realisation<T>::delete_element(mylist * el_to_delete)
 {	 if ((el_to_delete == head) && (el_to_delete == tail))
	 {
		 delete el_to_delete;
		 head = nullptr;
		 tail = nullptr;
		 cout << "element has been deleted" << endl;
		 return;
	 }
	 else if (el_to_delete==head) {
		 el_to_delete->next->prev = nullptr;
		 head = el_to_delete->next;
		 delete el_to_delete;
	 }
	 else if(el_to_delete==tail){
		 el_to_delete->prev->next = nullptr;
		 tail = el_to_delete->prev;
		 delete el_to_delete;
	 }
	 
	 else {
		 el_to_delete->prev->next = el_to_delete->next;
		 el_to_delete->next->prev = el_to_delete->prev;
		 delete el_to_delete;
	 }
	 cout << "element has been deleted" << endl;
 }
