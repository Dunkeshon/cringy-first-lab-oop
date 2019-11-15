/**
	*file
	*brief Header file containing class insertionSort
	*This file contains definition and implementation of insertionSort
*/
#pragma once
#include "list_node.h"
#include "Taime.h"
#include <string>
class insertionSort
{
private:
/**
	@param [in] head_ref pointer to reference to head of the list
	@param [in] new_node pointer to node, that we will compare to others and than add to sorted list
	* brief compares node with other nodes and find its place in the list due to its time of creation
 */
	void sortedInsert_time(list_node** head_ref, list_node* new_node);
/**
	@param [in] head_ref pointer to reference to head of the list
	@param [in] new_node pointer to node, that we will compare to others and than add to sorted list
	* brief compares node with other nodes and find its place in the list due to its changed time
*/
	void sortedInsert_changed_time(list_node** head_ref, list_node* new_node);
/**
	@param [in] head_ref pointer to reference to head of the list
	@param [in] new_node pointer to node, that we will compare to others and than add to sorted list
	* brief compares node with other nodes and find its place in the list due to its name
*/
	void sortedInsert_name(list_node** head_ref, list_node* new_node);
/**
	@param [in] head_ref pointer to reference to head of the list
	@param [in] new_node pointer to node, that we will compare to others and than add to sorted list
	* brief compares node with other nodes and find its place in the list due to its size
 */
	void sortedInsert_size(list_node** head_ref, list_node* new_node);

public:
/**
	@param [in] head_ref pointer to reference to head of the list
	*brief go through the list and insert each node in the new list, 
	comparing nodes by their time of creation. 
 */
	void insertionSort_time(list_node **head_ref);
/**
	@param [in] head_ref pointer to reference to head of the list
	*brief go through the list and insert each node in the new list,
	comparing nodes by their changed time .
 */
	void insertionSort_changed_time(list_node **head_ref);
/**
	@param [in] head_ref pointer to reference to head of the list
	*brief go through the list and insert each node in the new list,
	comparing nodes by their name.
 */
	void insertionSort_name(list_node **head_ref);
/**
	@param [in] head_ref pointer to reference to head of the list
	*brief go through the list and insert each node in the new list,
	comparing nodes by their size .
 */
	void insertionSort_size(list_node **head_ref);

	insertionSort();
	~insertionSort();
};
#include "insertionSort.hxx"
