/**
	*file
	*brief hxx file containing implementations of insertionSort.h
*/
#include "insertionSort.h"

#pragma once
/**
	@param [in] head_ref pointer to reference to head of the list
	@param [in] new_node pointer to node, that we will compare to others and than add to sorted list
	* brief compares node with other nodes and find its place in the list due to its time of creation
	*details If we just started sorting, set the head of the new list to the first item.
 	if the head of the new list is greater than or equal to the new element - put the new element in front of the head of the new list, then move the head to this element
 	otherwise, create a temporary variable current, to which we assign the value of the head of the new list and move forward through the list until we find
 	an element that will be more than this. All operations are carried out with verification of what data type is in list_node and, depending on this, take data for
 	comparisons precisely from the data type that we need, because if a file is used in list_node, then zeros are in the catalog class of this list_node
 	Comparison occurs at the time of creation.
 */
void insertionSort::sortedInsert_time(list_node** head_ref, list_node* new_node)
{
	list_node* current;
	if (*head_ref == nullptr )
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog) && ((*head_ref)->Catalog_info.Get_time() >= new_node->Catalog_info.Get_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_file) && ((*head_ref)->Catalog_info.Get_time() >= new_node->File_info.Get_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_catalog) && ((*head_ref)->File_info.Get_time() >= new_node->Catalog_info.Get_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_file) && ((*head_ref)->File_info.Get_time() >= new_node->File_info.Get_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; 
		*head_ref = new_node;
	}
	// other casses
	else
	{
		/* Locate the node before the point of insertion */
		current = *head_ref;
		Taime current_next_data;
		Taime new_node_data;
		if (current->next != nullptr) {
			if ((current->next->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog)) {
				current_next_data = current->next->Catalog_info.Get_time();
				new_node_data = new_node->Catalog_info.Get_time();
			}
			else if ((current->next->Get_type() == is_file) && (new_node->Get_type() == is_catalog)) {
				current_next_data = current->next->File_info.Get_time();
				new_node_data = new_node->Catalog_info.Get_time();
			}
			else if ((current->next->Get_type() == is_catalog) && (new_node->Get_type() == is_file)) {
				current_next_data = current->next->Catalog_info.Get_time();
				new_node_data = new_node->File_info.Get_time();
			}
			else if ((current->next->Get_type() == is_file) && (new_node->Get_type() == is_file)) {
				current_next_data = current->next->File_info.Get_time();
				new_node_data = new_node->File_info.Get_time();
			}
		}
		while (current->next != nullptr &&
			current_next_data < new_node_data)
		{
			// changing pointers 
			list_node * temp = current; 
			current = current->next;
			current->prev = temp;
			// change data that we will compare next
			if (current->next != nullptr) {
				if ((current->next->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog)) {
					current_next_data = current->next->Catalog_info.Get_time();
					new_node_data = new_node->Catalog_info.Get_time();
				}
				else if ((current->next->Get_type() == is_file) && (new_node->Get_type() == is_catalog)) {
					current_next_data = current->next->File_info.Get_time();
					new_node_data = new_node->Catalog_info.Get_time();
				}
				else if ((current->next->Get_type() == is_catalog) && (new_node->Get_type() == is_file)) {
					current_next_data = current->next->Catalog_info.Get_time();
					new_node_data = new_node->File_info.Get_time();
				}
				else if ((current->next->Get_type() == is_file) && (new_node->Get_type() == is_file)) {
					current_next_data = current->next->File_info.Get_time();
					new_node_data = new_node->File_info.Get_time();
				}
			}
			
		}
		new_node->next = current->next;
		if (new_node->next != nullptr) {
			new_node->next->prev = new_node; 
		}
		current->next = new_node;
		new_node->prev = current;
	}
}
/**
	@param [in] head_ref pointer to reference to head of the list
	@param [in] new_node pointer to node, that we will compare to others and than add to sorted list
	* brief compares node with other nodes and find its place in the list due to its changed time
	*details If we just started sorting, set the head of the new list to the first item.
 	if the head of the new list is greater than or equal to the new element - put the new element in front of the head of the new list, then move the head to this element
 	otherwise, create a temporary variable current, to which we assign the value of the head of the new list and move forward through the list until we find
 	an element that will be more than this. All operations are carried out with verification of what data type is in list_node and, depending on this, take data for
 	comparisons precisely from the data type that we need, because if a file is used in list_node, then zeros are in the catalog class of this list_node
 */
void insertionSort::sortedInsert_changed_time(list_node ** head_ref, list_node * new_node)
{
	list_node* current;
	if (*head_ref == nullptr)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog) && ((*head_ref)->Catalog_info.Get_changed_time() >= new_node->Catalog_info.Get_changed_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_file) && ((*head_ref)->Catalog_info.Get_changed_time() >= new_node->File_info.Get_changed_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_catalog) && ((*head_ref)->File_info.Get_changed_time() >= new_node->Catalog_info.Get_changed_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node;
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_file) && ((*head_ref)->File_info.Get_changed_time() >= new_node->File_info.Get_changed_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; 
		*head_ref = new_node;
	}
	// other casses
	else
	{
		/* Locate the node before the point of insertion */
		current = *head_ref;
		Taime current_next_data;
		Taime new_node_data;
		if (current->next != nullptr) {
			if ((current->next->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog)) {
				current_next_data = current->next->Catalog_info.Get_changed_time();
				new_node_data = new_node->Catalog_info.Get_changed_time();
			}
			else if ((current->next->Get_type() == is_file) && (new_node->Get_type() == is_catalog)) {
				current_next_data = current->next->File_info.Get_changed_time();
				new_node_data = new_node->Catalog_info.Get_changed_time();
			}
			else if ((current->next->Get_type() == is_catalog) && (new_node->Get_type() == is_file)) {
				current_next_data = current->next->Catalog_info.Get_changed_time();
				new_node_data = new_node->File_info.Get_changed_time();
			}
			else if ((current->next->Get_type() == is_file) && (new_node->Get_type() == is_file)) {
				current_next_data = current->next->File_info.Get_changed_time();
				new_node_data = new_node->File_info.Get_changed_time();
			}
		}
		while (current->next != nullptr &&
			current_next_data < new_node_data)
		{
			// changing pointers 
			list_node * temp = current;
			current = current->next;
			current->prev = temp;
			// change data that we will compare next
			if (current->next != nullptr) {
				if ((current->next->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog)) {
					current_next_data = current->next->Catalog_info.Get_changed_time();
					new_node_data = new_node->Catalog_info.Get_changed_time();
				}
				else if ((current->next->Get_type() == is_file) && (new_node->Get_type() == is_catalog)) {
					current_next_data = current->next->File_info.Get_changed_time();
					new_node_data = new_node->Catalog_info.Get_changed_time();
				}
				else if ((current->next->Get_type() == is_catalog) && (new_node->Get_type() == is_file)) {
					current_next_data = current->next->Catalog_info.Get_changed_time();
					new_node_data = new_node->File_info.Get_changed_time();
				}
				else if ((current->next->Get_type() == is_file) && (new_node->Get_type() == is_file)) {
					current_next_data = current->next->File_info.Get_changed_time();
					new_node_data = new_node->File_info.Get_changed_time();
				}
			}
		}
		new_node->next = current->next;
		if (new_node->next != nullptr) {
			new_node->next->prev = new_node;
		}
		current->next = new_node;
		new_node->prev = current;
	}
}
/**
	@param [in] head_ref pointer to reference to head of the list
	@param [in] new_node pointer to node, that we will compare to others and than add to sorted list
	* brief compares node with other nodes and find its place in the list due to its name
	*details If we just started sorting, set the head of the new list to the first item.
 	if the head of the new list is greater than or equal to the new element - put the new element in front of the head of the new list, then move the head to this element
 	otherwise, create a temporary variable current, to which we assign the value of the head of the new list and move forward through the list until we find
 	an element that will be more than this. All operations are carried out with verification of what data type is in list_node and, depending on this, take data for
 	comparisons precisely from the data type that we need, because if a file is used in list_node, then zeros are in the catalog class of this list_node
 */
void insertionSort::sortedInsert_name(list_node ** head_ref, list_node * new_node)
{
	list_node* current;
	if (*head_ref == nullptr)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog) && ((*head_ref)->Catalog_info.Get_name() >= new_node->Catalog_info.Get_name()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_file) && ((*head_ref)->Catalog_info.Get_name() >= new_node->File_info.Get_name()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_catalog) && ((*head_ref)->File_info.Get_name() >= new_node->Catalog_info.Get_name()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node;  
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_file) && ((*head_ref)->File_info.Get_name() >= new_node->File_info.Get_name()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; 
		*head_ref = new_node;
	}
	// other casses
	else
	{
		/* Locate the node before the point of insertion */
		current = *head_ref;
		string current_next_data;
		string new_node_data;
		if (current->next != nullptr) {
			if ((current->next->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog)) {
				current_next_data = current->next->Catalog_info.Get_name();
				new_node_data = new_node->Catalog_info.Get_name();
			}
			else if ((current->next->Get_type() == is_file) && (new_node->Get_type() == is_catalog)) {
				current_next_data = current->next->File_info.Get_name();
				new_node_data = new_node->Catalog_info.Get_name();
			}
			else if ((current->next->Get_type() == is_catalog) && (new_node->Get_type() == is_file)) {
				current_next_data = current->next->Catalog_info.Get_name();
				new_node_data = new_node->File_info.Get_name();
			}
			else if ((current->next->Get_type() == is_file) && (new_node->Get_type() == is_file)) {
				current_next_data = current->next->File_info.Get_name();
				new_node_data = new_node->File_info.Get_name();
			}
		}
		while (current->next != nullptr &&
			current_next_data < new_node_data)
		{
			// changing pointers 
			list_node * temp = current;
			current = current->next;
			current->prev = temp;
			if (current->next != nullptr) {
				// change data that we will compare next
				if ((current->next->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog)) {
					current_next_data = current->next->Catalog_info.Get_name();
					new_node_data = new_node->Catalog_info.Get_name();
				}
				else if ((current->next->Get_type() == is_file) && (new_node->Get_type() == is_catalog)) {
					current_next_data = current->next->File_info.Get_name();
					new_node_data = new_node->Catalog_info.Get_name();
				}
				else if ((current->next->Get_type() == is_catalog) && (new_node->Get_type() == is_file)) {
					current_next_data = current->next->Catalog_info.Get_name();
					new_node_data = new_node->File_info.Get_name();
				}
				else if ((current->next->Get_type() == is_file) && (new_node->Get_type() == is_file)) {
					current_next_data = current->next->File_info.Get_name();
					new_node_data = new_node->File_info.Get_name();
				}
			}
		}
		new_node->next = current->next;
		if (new_node->next != nullptr) {
			new_node->next->prev = new_node; 
		}
		current->next = new_node;
		new_node->prev = current;
	}
}
/**
	@param [in] head_ref pointer to reference to head of the list
	@param [in] new_node pointer to node, that we will compare to others and than add to sorted list
	* brief compares node with other nodes and find its place in the list due to its size
	*details If we just started sorting, set the head of the new list to the first item.
 	if the head of the new list is greater than or equal to the new element - put the new element in front of the head of the new list, then move the head to this element
 	otherwise, create a temporary variable current, to which we assign the value of the head of the new list and move forward through the list until we find
 	an element that will be more than this. All operations are carried out with verification of what data type is in list_node and, depending on this, take data for
 	comparisons precisely from the data type that we need, because if a file is used in list_node, then zeros are in the catalog class of this list_node	
 */
void insertionSort::sortedInsert_size(list_node ** head_ref, list_node * new_node)
{
	list_node* current;
	if (*head_ref == nullptr)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog) && ((*head_ref)->Catalog_info.Get_size() >= new_node->Catalog_info.Get_size()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_file) && ((*head_ref)->Catalog_info.Get_size() >= new_node->File_info.Get_size()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node;  
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_catalog) && ((*head_ref)->File_info.Get_size() >= new_node->Catalog_info.Get_size()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_file) && ((*head_ref)->File_info.Get_size() >= new_node->File_info.Get_size()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; 
		*head_ref = new_node;
	}
	// other casses
	else
	{
		/* Locate the node before the point of insertion */
		current = *head_ref;
		int current_next_data;
		int new_node_data;
		if (current->next != nullptr) {
			if ((current->next->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog)) {
				current_next_data = current->next->Catalog_info.Get_size();
				new_node_data = new_node->Catalog_info.Get_size();
			}
			else if ((current->next->Get_type() == is_file) && (new_node->Get_type() == is_catalog)) {
				current_next_data = current->next->File_info.Get_size();
				new_node_data = new_node->Catalog_info.Get_size();
			}
			else if ((current->next->Get_type() == is_catalog) && (new_node->Get_type() == is_file)) {
				current_next_data = current->next->Catalog_info.Get_size();
				new_node_data = new_node->File_info.Get_size();
			}
			else if ((current->next->Get_type() == is_file) && (new_node->Get_type() == is_file)) {
				current_next_data = current->next->File_info.Get_size();
				new_node_data = new_node->File_info.Get_size();
			}
		}
		while (current->next != nullptr &&
			current_next_data < new_node_data)
		{
			// changing pointers 
			list_node * temp = current;
			current = current->next;
			current->prev = temp;
			// change data that we will compare next
			if (current->next != nullptr) {
				
				if ((current->next->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog)) {
					current_next_data = current->next->Catalog_info.Get_size();
					new_node_data = new_node->Catalog_info.Get_size();
				}
				else if ((current->next->Get_type() == is_file) && (new_node->Get_type() == is_catalog)) {
					current_next_data = current->next->File_info.Get_size();
					new_node_data = new_node->Catalog_info.Get_size();
				}
				else if ((current->next->Get_type() == is_catalog) && (new_node->Get_type() == is_file)) {
					current_next_data = current->next->Catalog_info.Get_size();
					new_node_data = new_node->File_info.Get_size();
				}
				else if ((current->next->Get_type() == is_file) && (new_node->Get_type() == is_file)) {
					current_next_data = current->next->File_info.Get_size();
					new_node_data = new_node->File_info.Get_size();
				}
			}
		}
		new_node->next = current->next;
		if (new_node->next != nullptr) {
			new_node->next->prev = new_node; 
		}
		current->next = new_node;
		new_node->prev = current;
	}
}

/**
	@param [in] head_ref pointer to reference to head of the list
	*brief go through the list and insert each node in the new list, 
	comparing nodes by their time of creation. 
	*details Creation of new list, that will be sorted via insertion sort.
	go through the list and insert each node in the new list.
	After finishing with creating new sorted list - set head of sorted list to 
	head of list, with which we work in our program 
 */
void insertionSort::insertionSort_time(list_node **head_ref) {
	// Initialize sorted linked list 
	list_node *sorted = nullptr;

	// Traverse the given linked list and insert every 
	// node to sorted 
	list_node *current = *head_ref;
	while (current != nullptr)
	{
		// Store next for next iteration 
		list_node *next = current->next;

		// insert current in sorted linked list 
		sortedInsert_time(&sorted, current);

		// Update current 
		current = next;
	}

	// Update head_ref to point to sorted linked list 
	*head_ref = sorted;
}
/**
	@param [in] head_ref pointer to reference to head of the list
	*brief go through the list and insert each node in the new list,
	comparing nodes by their changed time .
	*details Creation of new list, that will be sorted via insertion sort.
	go through the list and insert each node in the new list.
	After finishing with creating new sorted list - set head of sorted list to
	head of list, with which we work in our program
 */
void insertionSort::insertionSort_changed_time(list_node ** head_ref)
{
	// Initialize sorted linked list 
	list_node *sorted = nullptr;

	// Traverse the given linked list and insert every 
	// node to sorted 
	list_node *current = *head_ref;
	while (current != nullptr)
	{
		// Store next for next iteration 
		list_node *next = current->next;

		// insert current in sorted linked list 
		sortedInsert_changed_time(&sorted, current);

		// Update current 
		current = next;
	}

	// Update head_ref to point to sorted linked list 
	*head_ref = sorted;
}
/**
	@param [in] head_ref pointer to reference to head of the list
	*brief go through the list and insert each node in the new list,
	comparing nodes by their name.
	*details Creation of new list, that will be sorted via insertion sort.
	go through the list and insert each node in the new list.
	After finishing with creating new sorted list - set head of sorted list to
	head of list, with which we work in our program
 */
void insertionSort::insertionSort_name(list_node ** head_ref)
{
	// Initialize sorted linked list 
	list_node *sorted = nullptr;

	// Traverse the given linked list and insert every 
	// node to sorted 
	list_node *current = *head_ref;
	while (current != nullptr)
	{
		// Store next for next iteration 
		list_node *next = current->next;

		// insert current in sorted linked list 
		sortedInsert_name(&sorted, current);

		// Update current 
		current = next;
	}

	// Update head_ref to point to sorted linked list 
	*head_ref = sorted;
}
/**
	@param [in] head_ref pointer to reference to head of the list
	*brief go through the list and insert each node in the new list,
	comparing nodes by their size .
	*details Creation of new list, that will be sorted via insertion sort.
	go through the list and insert each node in the new list.
	After finishing with creating new sorted list - set head of sorted list to
	head of list, with which we work in our program
 */
void insertionSort::insertionSort_size(list_node ** head_ref)
{
	// Initialize sorted linked list 
	list_node *sorted = nullptr;

	// Traverse the given linked list and insert every 
	// node to sorted 
	list_node *current = *head_ref;
	while (current != nullptr)
	{
		// Store next for next iteration 
		list_node *next = current->next;

		// insert current in sorted linked list 
		sortedInsert_size(&sorted, current);

		// Update current 
		current = next;
	}

	// Update head_ref to point to sorted linked list 
	*head_ref = sorted;
}
insertionSort::insertionSort()
{
}


insertionSort::~insertionSort()
{
}
