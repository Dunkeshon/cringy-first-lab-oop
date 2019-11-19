/**
	*file
	*brief Header file containing class list_node
	*This file contains definition and implementation of list_node
*/
#pragma once
#include "Catalog.h"
#include "File.h"
/**
	*brief An implementation of list_node.
	*details Realization of list_node, this class used to store nodes of list.
	You can put here catalog or file, because it contains storage for both of them,
	by initialization of them with 0.
	While list_node is created, you need to say what type of info this node will contain,
	so what you need to do is set the _type_of_element.
*/

/**
	*brief enum type of element, that inform us what time of an object
	*contains in this listnode. is setted 0 by default(in constructor). 
	when we add object in the list we set wether it's catalog or file
*/
enum type
{
	not_setted , is_catalog , is_file
};
class list_node
{
private:
/**
	*brief enum type of element, that inform us what time of an object 
	*contains in this listnode
*/
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
	
	
/**
	*brief constructor. Set all fields to 0
*/
	list_node();
	~list_node();

};

#include "list_node.hxx"