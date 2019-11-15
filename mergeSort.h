/**
	*file
	*brief Header file containing class mergeSort
	*This file contains definition and implementation of mergeSort
*/
#pragma once
#include "list_node.h"
class mergeSort
{
private:/* sorts the linked list by changing next pointers (not data) */
/**
	@param[in] a first node to compare
	@param[in] b second node to compare
	* brief Pick either a or b, and recur 
	* returns node , that have less time of creation
*/
	list_node* SortedMerge_time(list_node* a, list_node* b);
/**
	@param[in] a first node to compare
	@param[in] b second node to compare
	* brief Pick either a or b, and recur
	* returns node , that have less changed time
*/
	list_node* SortedMerge_changed_time(list_node* a, list_node* b);
/**
	@param[in] a first node to compare
	@param[in] b second node to compare
	* brief Pick either a or b, and recur
	* returns node , that have less name
*/
	list_node* SortedMerge_name(list_node* a, list_node* b);
/**
	@param[in] a first node to compare
	@param[in] b second node to compare
	* brief Pick either a or b, and recur
	* returns node , that have less size
*/
	list_node* SortedMerge_size(list_node* a, list_node* b);
/**
	@param[in] source pointer to node, from which we start 
	@param[in] frontRef pointer to head
	@param[in] backRef pointer to tail
	* brief Split the nodes of the given list into front and back halves
*/
	void FrontBackSplit(list_node* source,
		list_node** frontRef, list_node** backRef);
public:
/**
	@param[in] headRef pointer to refernce of head of the list
	* brief sorts list by their time of creation , using merge sort
*/
	void MergeSort_time(list_node** headRef);
/**
	@param[in] headRef pointer to refernce of head of the list
	* brief sorts list by their changed time , using merge sort
*/
	void MergeSort_changed_time(list_node** headRef);
/**
	@param[in] headRef pointer to refernce of head of the list
	* brief sorts list by their name, using merge sort
*/
	void MergeSort_name(list_node** headRef);
/**
	@param[in] headRef pointer to refernce of head of the list
	* brief sorts list by their size , using merge sort
*/
	void MergeSort_size(list_node** headRef);
	mergeSort();
	~mergeSort();
};
#include "mergeSort.hxx"
