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
	/**
	*brief set type of element which will be stored in this list node
	@param this_type Type of element which will be stored in this list node
	*/
	void Set_type_of_el(type this_type);
	/**
	*brief returns type of element which is stored in this list node. 
	*If this node hasn't been already setted - returns not_setted
	@return type _type_of_element
	*/
	type Get_type();
	/**
	* catalog, that is stored in this list_node 
	*/
	Catalog Catalog_info;
	/**
	* file, that is stored in this list_node
	*/
	file File_info;
	list_node *next;
	list_node *prev;
	
	
	
	list_node();// нужно реализовать функцию заполнения и создания файла
	~list_node();

};

#include "list_node.hxx"