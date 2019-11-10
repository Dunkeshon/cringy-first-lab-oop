#include "pch.h"
#include "mergeSort.h"
#pragma once

list_node * mergeSort::SortedMerge_time(list_node * a, list_node * b)
{
	
	list_node* result = nullptr;
	/* Base cases */
	if (a == nullptr) {
		return (b);
	}
	else if (b == nullptr) {
		return (a);
	}
	/* Pick either a or b, and recur */
	// if in our node is stored file- get file info ; else - catalog info
	if ((a->Get_type() == is_catalog) && (b->Get_type() == is_catalog))
	{
		if (a->Catalog_info.Get_time() <= b->Catalog_info.Get_time()) {
			result = a;
			result->next = SortedMerge_time(a->next, b);
			result->next->prev = result;
		}
		else {
			result = b;
			result->next = SortedMerge_time(a, b->next);
			result->next->prev = result;
		}
		return (result);
	}
	else if ((a->Get_type() == is_catalog) && (b->Get_type() == is_file))
	{
		if (a->Catalog_info.Get_time() <= b->File_info.Get_time()) {
			result = a;
			result->next = SortedMerge_time(a->next, b);
			result->next->prev = result;
		}
		else {
			result = b;
			result->next = SortedMerge_time(a, b->next);
			result->next->prev = result;
		}
		return (result);
	}
	else if ((a->Get_type() == is_file) && (b->Get_type() == is_catalog))
	{
		if (a->File_info.Get_time() <= b->Catalog_info.Get_time()) {
			result = a;
			result->next = SortedMerge_time(a->next, b);
			result->next->prev = result;
		}
		else {
			result = b;
			result->next = SortedMerge_time(a, b->next);
			result->next->prev = result;
		}
		return (result);
	}
	else if ((a->Get_type() == is_file) && (b->Get_type() == is_file))
	{
		if (a->File_info.Get_time() <= b->File_info.Get_time()) {
			result = a;
			result->next = SortedMerge_time(a->next, b);
			result->next->prev = result;
		}
		else {
			result = b;
			result->next = SortedMerge_time(a, b->next);
			result->next->prev = result;
		}
		return (result);
	}
}

list_node * mergeSort::SortedMerge_changed_time(list_node * a, list_node * b)
{
	list_node* result = nullptr;
	/* Base cases */
	if (a == nullptr) {
		return (b);
	}
	else if (b == nullptr) {
		return (a);
	}
	/* Pick either a or b, and recur */
	// if in our node is stored file- get file info ; else - catalog info
	if ((a->Get_type() == is_catalog) && (b->Get_type() == is_catalog))
	{
		if (a->Catalog_info.Get_changed_time() <= b->Catalog_info.Get_changed_time()) {
			result = a;
			result->next = SortedMerge_changed_time(a->next, b);
			result->next->prev = result;
		}
		else {
			result = b;
			result->next = SortedMerge_changed_time(a, b->next);
			result->next->prev = result;
		}
		return (result);
	}
	else if ((a->Get_type() == is_catalog) && (b->Get_type() == is_file))
	{
		if (a->Catalog_info.Get_changed_time() <= b->File_info.Get_changed_time()) {
			result = a;
			result->next = SortedMerge_changed_time(a->next, b);
			result->next->prev = result;
		}
		else {
			result = b;
			result->next = SortedMerge_changed_time(a, b->next);
			result->next->prev = result;
		}
		return (result);
	}
	else if ((a->Get_type() == is_file) && (b->Get_type() == is_catalog))
	{
		if (a->File_info.Get_changed_time() <= b->Catalog_info.Get_changed_time()) {
			result = a;
			result->next = SortedMerge_changed_time(a->next, b);
			result->next->prev = result;
		}
		else {
			result = b;
			result->next = SortedMerge_changed_time(a, b->next);
			result->next->prev = result;
		}
		return (result);
	}
	else if ((a->Get_type() == is_file) && (b->Get_type() == is_file))
	{
		if (a->File_info.Get_changed_time() <= b->File_info.Get_changed_time()) {
			result = a;
			result->next = SortedMerge_changed_time(a->next, b);
			result->next->prev = result;
		}
		else {
			result = b;
			result->next = SortedMerge_changed_time(a, b->next);
			result->next->prev = result;
		}
		return (result);
	}
}
 list_node * mergeSort::SortedMerge_name(list_node * a, list_node * b)
{

	 list_node* result = nullptr;
	 /* Base cases */
	 if (a == nullptr) {
		 return (b);
	 }
	 else if (b == nullptr) {
		 return (a);
	 }
	 /* Pick either a or b, and recur */
	 // if in our node is stored file- get file info ; else - catalog info
	 if ((a->Get_type() == is_catalog) && (b->Get_type() == is_catalog))
	 {
		 if (a->Catalog_info.Get_name() <= b->Catalog_info.Get_name()) {
			 result = a;
			 result->next = SortedMerge_name(a->next, b);
			 result->next->prev = result;
		 }
		 else {
			 result = b;
			 result->next = SortedMerge_name(a, b->next);
			 result->next->prev = result;
		 }
		 return (result);
	 }
	 else if ((a->Get_type() == is_catalog) && (b->Get_type() == is_file))
	 {
		 if (a->Catalog_info.Get_name() <= b->File_info.Get_name()) {
			 result = a;
			 result->next = SortedMerge_name(a->next, b);
			 result->next->prev = result;
		 }
		 else {
			 result = b;
			 result->next = SortedMerge_name(a, b->next);
			 result->next->prev = result;
		 }
		 return (result);
	 }
	 else if ((a->Get_type() == is_file) && (b->Get_type() == is_catalog))
	 {
		 if (a->File_info.Get_name() <= b->Catalog_info.Get_name()) {
			 result = a;
			 result->next = SortedMerge_name(a->next, b);
			 result->next->prev = result;
		 }
		 else {
			 result = b;
			 result->next = SortedMerge_name(a, b->next);
			 result->next->prev = result;
		 }
		 return (result);
	 }
	 else if ((a->Get_type() == is_file) && (b->Get_type() == is_file))
	 {
		 if (a->File_info.Get_name() <= b->File_info.Get_name()) {
			 result = a;
			 result->next = SortedMerge_name(a->next, b);
			 result->next->prev = result;
		 }
		 else {
			 result = b;
			 result->next = SortedMerge_name(a, b->next);
			 result->next->prev = result;
		 }
		 return (result);
	 }
}
 list_node * mergeSort::SortedMerge_size(list_node * a, list_node * b)
 {

	 list_node* result = nullptr;
	 /* Base cases */
	 if (a == nullptr) {
		 return (b);
	 }
	 else if (b == nullptr) {
		 return (a);
	 }
	 /* Pick either a or b, and recur */
	 // if in our node is stored file- get file info ; else - catalog info
	 if ((a->Get_type() == is_catalog) && (b->Get_type() == is_catalog))
	 {
		 if (a->Catalog_info.Get_size() <= b->Catalog_info.Get_size()) {
			 result = a;
			 result->next = SortedMerge_size(a->next, b);
			 result->next->prev = result;
		 }
		 else {
			 result = b;
			 result->next = SortedMerge_size(a, b->next);
			 result->next->prev = result;
		 }
		 return (result);
	 }
	 else if ((a->Get_type() == is_catalog) && (b->Get_type() == is_file))
	 {
		 if (a->Catalog_info.Get_size() <= b->File_info.Get_size()) {
			 result = a;
			 result->next = SortedMerge_size(a->next, b);
			 result->next->prev = result;
		 }
		 else {
			 result = b;
			 result->next = SortedMerge_size(a, b->next);
			 result->next->prev = result;
		 }
		 return (result);
	 }
	 else if ((a->Get_type() == is_file) && (b->Get_type() == is_catalog))
	 {
		 if (a->File_info.Get_size() <= b->Catalog_info.Get_size()) {
			 result = a;
			 result->next = SortedMerge_size(a->next, b);
			 result->next->prev = result;
		 }
		 else {
			 result = b;
			 result->next = SortedMerge_size(a, b->next);
			 result->next->prev = result;
		 }
		 return (result);
	 }
	 else if ((a->Get_type() == is_file) && (b->Get_type() == is_file))
	 {
		 if (a->File_info.Get_size() <= b->File_info.Get_size()) {
			 result = a;
			 result->next = SortedMerge_size(a->next, b);
			 result->next->prev = result;
		 }
		 else {
			 result = b;
			 result->next = SortedMerge_size(a, b->next);
			 result->next->prev = result;
		 }
		 return (result);
	 }
 }
/* Split the nodes of the given list into front and back halves,
	and return the two lists using the reference parameters.
	If the length is odd, the extra node should go in the front list.
	Uses the fast/slow pointer strategy. */
 void mergeSort::FrontBackSplit(list_node * source, list_node ** frontRef, list_node ** backRef)
{
	 list_node* fast;
	 list_node* slow;
	 slow = source;
	 fast = source->next;

	 /* Advance 'fast' two nodes, and advance 'slow' one node */
	 while (fast != nullptr) {
		 fast = fast->next;
		 if (fast != nullptr) {
			 slow = slow->next;
			 fast = fast->next;
		 }
	 }
	 /* 'slow' is before the midpoint in the list, so split it in two
	 at that point. */
	 *frontRef = source;
	 *backRef = slow->next;
	 slow->next = nullptr;
}

void mergeSort::MergeSort_time(list_node ** headRef)
{
	list_node* cur_head = *headRef;
	list_node* a;
	list_node* b;

	/* Base case -- length 0 or 1 */
	if ((cur_head == nullptr) || (cur_head->next == nullptr)) {
		return;
	}
	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(cur_head, &a, &b);

	/* Recursively sort the sublists */
	MergeSort_time(&a);
	MergeSort_time(&b);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge_time(a, b);
}

void mergeSort::MergeSort_changed_time(list_node ** headRef)
{
	list_node* head = *headRef;
	list_node* a;
	list_node* b;

	/* Base case -- length 0 or 1 */
	if ((head == nullptr) || (head->next == nullptr)) {
		return;
	}
	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);

	/* Recursively sort the sublists */
	MergeSort_time(&a);
	MergeSort_time(&b);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge_changed_time(a, b);
}

 void mergeSort::MergeSort_name(list_node ** headRef)
{

	 list_node* cur_head = *headRef;
	 list_node* a;
	 list_node* b;

	 /* Base case -- length 0 or 1 */
	 if ((cur_head == nullptr) || (cur_head->next == nullptr)) {
		 return;
	 }
	 /* Split head into 'a' and 'b' sublists */
	 FrontBackSplit(cur_head, &a, &b);

	 /* Recursively sort the sublists */
	 MergeSort_time(&a);
	 MergeSort_time(&b);

	 /* answer = merge the two sorted lists together */
	 *headRef = SortedMerge_name(a, b);
}

 void mergeSort::MergeSort_size(list_node ** headRef)
 {

	 list_node* cur_head = *headRef;
	 list_node* a;
	 list_node* b;

	 /* Base case -- length 0 or 1 */
	 if ((cur_head == nullptr) || (cur_head->next == nullptr)) {
		 return;
	 }
	 /* Split head into 'a' and 'b' sublists */
	 FrontBackSplit(cur_head, &a, &b);

	 /* Recursively sort the sublists */
	 MergeSort_time(&a);
	 MergeSort_time(&b);

	 /* answer = merge the two sorted lists together */
	 *headRef = SortedMerge_size(a, b);
 }

mergeSort::mergeSort()
{
}


mergeSort::~mergeSort()
{
}
