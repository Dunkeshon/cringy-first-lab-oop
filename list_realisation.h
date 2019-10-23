//���� ����� ��������� ���������� �������� ������.
//����� ������� ���: �������� ������� ��������,�������� ������,������ ������ �� �����, ���������� ���������, ������� �������� ����� �����������
//������ �� �������,��� �������� �������� ������� ��������, �� ��������� head=tail=nullptr;
#pragma once
#include "list_node.h"

//T=Catalog
 
class list_realisation
{
private:
	list_node<Catalog> * head;
	list_node<Catalog> * tail;
public:
	list_realisation();// initialisation with nullptr
	~list_realisation();// deleting list
	void printFuncList();// print list
	void addEl_Catalog( Catalog *Element);// i need to copy and add already existing element to the list
	void addEl_File(file *Element);
	void deletion();// deleting the list
	void insertion(list_node<Catalog> *previous, Catalog *element); // inserting element that already exist after the one we put in function
	// i need to create similar method for list_node<file>
	list_node<Catalog>* search_name(string key);// searching by name, returns adress of an element with such name
	list_node<Catalog>* Get_head();//getter
	list_node<Catalog>* Get_tail();//getter
	void delete_element(list_node<Catalog> *el_to_delete);// deleting an element
};

#include "list_realisation.hxx"