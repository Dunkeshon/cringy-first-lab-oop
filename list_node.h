//this is a node class
// i think i should make it template because i have to make the list of catalogs also
#pragma once
#include "Catalog.h"
#include "File.h"
enum type
{
	not_setted , is_catalog , is_file
};
class list_node
{
private:
	type _type_of_element;
	
public:
	void Set_type_of_el(type this_type);
	type Get_type();
	Catalog Catalog_info;
	file File_info;
	list_node *next;
	list_node *prev;
	
	
	
	list_node();// нужно реализовать функцию заполнения и создания файла
	~list_node();

};

#include "list_node.hxx"