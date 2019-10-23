#include "pch.h"
#include "list_realisation.h"



list_realisation::list_realisation()//создание первого элемента
{
	head = tail=nullptr;//первый элемент списка 
	
}


list_realisation::~list_realisation()// удаляет список
{
	list_node *current = head;
	list_node *temp;

	while (current)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
}

void list_realisation::printFuncList()// вывод списка
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


void list_realisation::addEl_Catalog( Catalog *Element)// добавление элемента
{
	list_node *temp = new list_node();

	temp->info=Element;// OVERLOAD 

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
void list_realisation::addEl_File(file *Element)// добавление элемента
{
	list_node *temp = new list_node();

	temp->info = Element;// OVERLOAD 

	
	temp->prev = tail;
	tail->next = temp;
	tail = temp;
	
}

void list_realisation::deletion()// удаление списка
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

void list_realisation::insertion(list_node *previous, Catalog *element) // вставка эллемента после элемента,который мы передаем в функцию
{
	 if (previous->next == nullptr)
	{
		addEl(element);
		return;
	}
	else {
		// нужно вызвать конструктор нового элемента и заполнить его данными- done
		list_node *p;//p-storring pointer to the next el
		list_node  * new_node = new list_node;
		//new_node->info = element , need to overload "=" 
		p = previous->next;
		previous->next = new_node;
		new_node->next = p;
		new_node->prev = previous;
		if (p != nullptr) {
			p->prev = new_node;
		}
	}
}

list_node* list_realisation::search_name(string key)
{
	list_node *temp = new list_node;
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
	cout << "file with this name doesn't exist" << endl;
	// нужно пройти по списку и вернуть адресс
	return nullptr;
}

 list_node * list_realisation::Get_head()
{

	return head;
}

 list_node * list_realisation::Get_tail()
 {
	 return tail;
 }

 void list_realisation::delete_element(list_node * el_to_delete)
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
