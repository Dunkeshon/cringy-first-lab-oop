//this is a node class
// i think i should make it template because i have to make the list of catalogs also
#pragma once
#include "Catalog.h"
#include "File.h"
//<T>
template <class T>
class list_node
{
public:
	list_node<T> *next;
	list_node<T> *prev;
	T info;// class with all info

	
	list_node();// ����� ����������� ������� ���������� � �������� �����
	~list_node();

};

#include "list_node.hxx"