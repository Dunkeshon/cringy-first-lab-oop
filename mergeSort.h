#pragma once
#include "list_node.h"
class mergeSort
{
private:
	list_node* SortedMerge_time(list_node* a, list_node* b);
	list_node* SortedMerge_changed_time(list_node* a, list_node* b);
	list_node* SortedMerge_name(list_node* a, list_node* b);
	list_node* SortedMerge_size(list_node* a, list_node* b);

	void FrontBackSplit(list_node* source,
		list_node** frontRef, list_node** backRef);
public:
	/* sorts the linked list by changing next pointers (not data) */
	void MergeSort_time(list_node** headRef);
	void MergeSort_changed_time(list_node** headRef);
	void MergeSort_name(list_node** headRef);
	void MergeSort_size(list_node** headRef);
	mergeSort();
	~mergeSort();
};
#include "mergeSort.hxx"
