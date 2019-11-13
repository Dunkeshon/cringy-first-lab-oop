#pragma once
#include "list_node.h"
#include "Taime.h"
class insertionSort
{
private:
	void sortedInsert_time(list_node** head_ref, list_node* new_node);
	void sortedInsert_changed_time(list_node** head_ref, list_node* new_node);
	void sortedInsert_name(list_node** head_ref, list_node* new_node);
	void sortedInsert_size(list_node** head_ref, list_node* new_node);

public:
	void insertionSort_time(list_node **head_ref);
	void insertionSort_changed_time(list_node **head_ref);
	void insertionSort_name(list_node **head_ref);
	void insertionSort_size(list_node **head_ref);

	insertionSort();
	~insertionSort();
};
#include "insertionSort.hxx"
