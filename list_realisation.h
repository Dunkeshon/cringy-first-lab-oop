/**
*file
*brief Header file containing class list_realisation
*This file contains definition and implementation of list_realisation, all methods that could be called for list 
*/
#pragma once
#include "list_node.h"
#include "mergeSort.h"
#include "Quicksort.h"

/**
*brief An implementation of list_realisation. 
*details Realization of list, where are stored pointers to head, tail, and all methods of list
*/
class list_realisation : public mergeSort , Quicksort
{
private:
	list_node * head;
	list_node * tail;
public:
	/**
	*brief Constructor, initialisation of private fields with nullptr
	*/
	list_realisation();
	/**
	*brief Destructor, delete all list
	*/
	~list_realisation();
	/**
	*brief Print list in console 
	*details output all fields of list nodes in console.If list is empty : message "list is empty".
	*/
	void printFuncList();// print list
	/**
	*brief Adds catalog in the list
	@param Element [in] A copy of already existing catalog that we add in the list
	*details We set that this list node will store Catalog, by setting type_of_el to is_catalog
	*/
	void addEl_Catalog( Catalog Element);
	/**
	*brief Adds file in the list
	@param [in] Element A copy of already existing file that we add in the list
	*details We set that this list node will store File, by setting type_of_el to is_file
	*/
	void addEl_File(file Element);
	/**
	*brief Deletion of list
	*details Delete all information and then set head=tail=nullptr , so that we can use this list again 
	*/
	void deletion();		
	/**
	*brief Searching by name, returns adress of an element with such name
	@param [in] key A name that we search in our list 
	@return Adress of an element whose field _name = key
	*details If list hasn't got any element with name we searched for : print message "file with this name doesn't exist".   
	*/
	list_node* search_name(string key);
	/**
	*brief Returns pointer to the tail of the list
	@return Pointer to tail
	*/
	list_node* Get_head();//getter
	/**
	*brief Returns pointer to the head of the list
	@return Pointer to head 
	*/
	list_node* Get_tail();//getter
	/**
	*brief Delete element from the list
	@param [in] el_to_delete A pointer to an element that we want to delete from list
	*details Prints message "element has been deleted" after deletion of the element
	*/
	void delete_element(list_node *el_to_delete);
	/**
	*brief Swaps two elements in the list
	@param [in] elToSwap1 Element to swap
	@param [in] elToSwap2 Element to swap with elToSwap1
	*/
	void swapEl(list_node * elToSwap1, list_node * elToSwap2);
	/**
	*brief Realization of merge sort
	*details User choose based on which parameter he want to sort our list. 
	*Contains all kind off parameters that can be taken
	*/
	void merge_sort();
	void quick_sort();
};

#include "list_realisation.hxx"