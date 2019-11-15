/**
	*file
	*brief hxx file containing implementations of list_node.h
*/
#include "pch.h"
#include "list_node.h"

/**
	*brief constructor. Set all fields to 0 
*/
list_node::list_node()
{
	next = nullptr;
	prev = nullptr;
	Catalog_info=Catalog();
	File_info = file();
	_type_of_element = not_setted;
}


 list_node::~list_node()
{

}

 /**
	*brief set type of element which will be stored in this list node
	@param this_type Type of element which will be stored in this list node
*/
 void list_node::Set_type_of_el(type this_type)
{
	 _type_of_element = this_type;
}
 /**
	*brief returns type of element which is stored in this list node.
	*If this node hasn't been already setted - returns not_setted
	@return type _type_of_element
*/
 type list_node::Get_type()
{
	return _type_of_element;
}
