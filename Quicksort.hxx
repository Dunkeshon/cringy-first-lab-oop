#include "Quicksort.h"
#pragma once


list_node * Quicksort::Q_Sort_partition_time(list_node * head, list_node *end, list_node ** newHead, list_node ** newTail)
{
	list_node *pivot = end;
	list_node *prev = nullptr, *cur = head, *tail = pivot;
	if ((cur->Get_type() == is_catalog) && (pivot->Get_type() == is_catalog)) {
		// During partition, both the head and end of the list might change 
		// which is updated in the newHead and newEnd variables 
		while (cur != pivot)
		{
			if (cur->Catalog_info.Get_time() < pivot->Catalog_info.Get_time())
			{
				// First node that has a value less than the pivot - becomes 
				// the new head 
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
				cur->next->prev = cur; // CARREFUL
			}
			else // If cur node is greater than pivot 
			{
				// Move cur node to next of tail, and change tail 
				if (prev)
					prev->next = cur->next;
				prev->next->prev = prev;	// ADDED
				list_node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail->next->prev = tail;	// ADDED
				tail = cur;
				cur = tmp;
			}
		}
    }
	else if ((cur->Get_type() == is_catalog) && (pivot->Get_type() == is_file)) 
	{
		// During partition, both the head and end of the list might change 
		// which is updated in the newHead and newEnd variables 
		while (cur != pivot)
		{
			if (cur->Catalog_info.Get_time() < pivot->File_info.Get_time())
			{
				// First node that has a value less than the pivot - becomes 
				// the new head 
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
				cur->next->prev = cur; // CARREFUL
			}
			else // If cur node is greater than pivot 
			{
				// Move cur node to next of tail, and change tail 
				if (prev)
					prev->next = cur->next;
				prev->next->prev = prev;	// ADDED
				list_node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail->next->prev = tail;	// ADDED
				tail = cur;
				cur = tmp;
			}
		}
	}

	else if ((cur->Get_type() == is_file) && (pivot->Get_type() == is_catalog))
	{
		// During partition, both the head and end of the list might change 
		// which is updated in the newHead and newEnd variables 
		while (cur != pivot)
		{
			if (cur->File_info.Get_time() < pivot->Catalog_info.Get_time())
			{
				// First node that has a value less than the pivot - becomes 
				// the new head 
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
				cur->next->prev = cur; // ADDED
			}
			else // If cur node is greater than pivot 
			{
				// Move cur node to next of tail, and change tail 
				if (prev)
					prev->next = cur->next;
				prev->next->prev = prev;	// ADDED
				list_node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail->next->prev = tail;	// ADDED
				tail = cur;
				cur = tmp;
			}
		}
	}

	else 
	{
		// During partition, both the head and end of the list might change 
		// which is updated in the newHead and newEnd variables 
		while (cur != pivot)
		{
			if (cur->File_info.Get_time() < pivot->File_info.Get_time())
			{
				// First node that has a value less than the pivot - becomes 
				// the new head 
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
				cur->next->prev = cur; // CARREFUL
			}
			else // If cur node is greater than pivot 
			{
				// Move cur node to next of tail, and change tail 
				if (prev)
					prev->next = cur->next;
				prev->next->prev = prev;	// ADDED
				list_node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail->next->prev = tail;	// ADDED
				tail = cur;
				cur = tmp;
			}
		}
	}
	// If the pivot data is the smallest element in the current list, 
	// pivot becomes the head 
	if ((*newHead) == nullptr)
		(*newHead) = pivot;

	// Update newEnd to the current last node 
	(*newTail) = tail;

	// Return the pivot node 
	return pivot;
	
}

list_node * Quicksort::Q_Sort_partition_changed_time(list_node * head, list_node * end, list_node ** newHead, list_node ** newTail)
{
	list_node *pivot = end;
	list_node *prev = nullptr, *cur = head, *tail = pivot;
	if ((cur->Get_type() == is_catalog) && (pivot->Get_type() == is_catalog)) {
		// During partition, both the head and end of the list might change 
		// which is updated in the newHead and newEnd variables 
		while (cur != pivot)
		{
			if (cur->Catalog_info.Get_changed_time() < pivot->Catalog_info.Get_changed_time())
			{
				// First node that has a value less than the pivot - becomes 
				// the new head 
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
				cur->next->prev = cur; // CARREFUL
			}
			else // If cur node is greater than pivot 
			{
				// Move cur node to next of tail, and change tail 
				if (prev)
					prev->next = cur->next;
				prev->next->prev = prev;	// ADDED
				list_node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail->next->prev = tail;	// ADDED
				tail = cur;
				cur = tmp;
			}
		}
	}
	else if ((cur->Get_type() == is_catalog) && (pivot->Get_type() == is_file))
	{
		// During partition, both the head and end of the list might change 
		// which is updated in the newHead and newEnd variables 
		while (cur != pivot)
		{
			if (cur->Catalog_info.Get_changed_time() < pivot->File_info.Get_changed_time())
			{
				// First node that has a value less than the pivot - becomes 
				// the new head 
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
				cur->next->prev = cur; // CARREFUL
			}
			else // If cur node is greater than pivot 
			{
				// Move cur node to next of tail, and change tail 
				if (prev)
					prev->next = cur->next;
				prev->next->prev = prev;	// ADDED
				list_node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail->next->prev = tail;	// ADDED
				tail = cur;
				cur = tmp;
			}
		}
	}

	else if ((cur->Get_type() == is_file) && (pivot->Get_type() == is_catalog))
	{
		// During partition, both the head and end of the list might change 
		// which is updated in the newHead and newEnd variables 
		while (cur != pivot)
		{
			if (cur->File_info.Get_changed_time() < pivot->Catalog_info.Get_changed_time())
			{
				// First node that has a value less than the pivot - becomes 
				// the new head 
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
				cur->next->prev = cur; // ADDED
			}
			else // If cur node is greater than pivot 
			{
				// Move cur node to next of tail, and change tail 
				if (prev)
					prev->next = cur->next;
				prev->next->prev = prev;	// ADDED
				list_node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail->next->prev = tail;	// ADDED
				tail = cur;
				cur = tmp;
			}
		}
	}

	else
	{
		// During partition, both the head and end of the list might change 
		// which is updated in the newHead and newEnd variables 
		while (cur != pivot)
		{
			if (cur->File_info.Get_changed_time() < pivot->File_info.Get_changed_time())
			{
				// First node that has a value less than the pivot - becomes 
				// the new head 
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
				cur->next->prev = cur; // CARREFUL
			}
			else // If cur node is greater than pivot 
			{
				// Move cur node to next of tail, and change tail 
				if (prev)
					prev->next = cur->next;
				prev->next->prev = prev;	// ADDED
				list_node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail->next->prev = tail;	// ADDED
				tail = cur;
				cur = tmp;
			}
		}
	}
	// If the pivot data is the smallest element in the current list, 
	// pivot becomes the head 
	if ((*newHead) == nullptr)
		(*newHead) = pivot;

	// Update newEnd to the current last node 
	(*newTail) = tail;

	// Return the pivot node 
	return pivot;

}

list_node * Quicksort::Q_Sort_partition_name(list_node * head, list_node * end, list_node ** newHead, list_node ** newTail)
{
	list_node *pivot = end;
	list_node *prev = nullptr, *cur = head, *tail = pivot;
	if ((cur->Get_type() == is_catalog) && (pivot->Get_type() == is_catalog)) {
		// During partition, both the head and end of the list might change 
		// which is updated in the newHead and newEnd variables 
		while (cur != pivot)
		{
			if (cur->Catalog_info.Get_name() < pivot->Catalog_info.Get_name())
			{
				// First node that has a value less than the pivot - becomes 
				// the new head 
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
				cur->next->prev = cur; // CARREFUL
			}
			else // If cur node is greater than pivot 
			{
				// Move cur node to next of tail, and change tail 
				if (prev)
					prev->next = cur->next;
				prev->next->prev = prev;	// ADDED
				list_node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail->next->prev = tail;	// ADDED
				tail = cur;
				cur = tmp;
			}
		}
	}
	else if ((cur->Get_type() == is_catalog) && (pivot->Get_type() == is_file))
	{
		// During partition, both the head and end of the list might change 
		// which is updated in the newHead and newEnd variables 
		while (cur != pivot)
		{
			if (cur->Catalog_info.Get_name() < pivot->File_info.Get_name())
			{
				// First node that has a value less than the pivot - becomes 
				// the new head 
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
				cur->next->prev = cur; // CARREFUL
			}
			else // If cur node is greater than pivot 
			{
				// Move cur node to next of tail, and change tail 
				if (prev)
					prev->next = cur->next;
				prev->next->prev = prev;	// ADDED
				list_node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail->next->prev = tail;	// ADDED
				tail = cur;
				cur = tmp;
			}
		}
	}

	else if ((cur->Get_type() == is_file) && (pivot->Get_type() == is_catalog))
	{
		// During partition, both the head and end of the list might change 
		// which is updated in the newHead and newEnd variables 
		while (cur != pivot)
		{
			if (cur->File_info.Get_name() < pivot->Catalog_info.Get_name())
			{
				// First node that has a value less than the pivot - becomes 
				// the new head 
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
				cur->next->prev = cur; // ADDED
			}
			else // If cur node is greater than pivot 
			{
				// Move cur node to next of tail, and change tail 
				if (prev)
					prev->next = cur->next;
				prev->next->prev = prev;	// ADDED
				list_node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail->next->prev = tail;	// ADDED
				tail = cur;
				cur = tmp;
			}
		}
	}

	else
	{
		// During partition, both the head and end of the list might change 
		// which is updated in the newHead and newEnd variables 
		while (cur != pivot)
		{
			if (cur->File_info.Get_name() < pivot->File_info.Get_name())
			{
				// First node that has a value less than the pivot - becomes 
				// the new head 
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
				cur->next->prev = cur; // CARREFUL
			}
			else // If cur node is greater than pivot 
			{
				// Move cur node to next of tail, and change tail 
				if (prev)
					prev->next = cur->next;
				prev->next->prev = prev;	// ADDED
				list_node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail->next->prev = tail;	// ADDED
				tail = cur;
				cur = tmp;
			}
		}
	}
	// If the pivot data is the smallest element in the current list, 
	// pivot becomes the head 
	if ((*newHead) == nullptr)
		(*newHead) = pivot;

	// Update newEnd to the current last node 
	(*newTail) = tail;

	// Return the pivot node 
	return pivot;

}

list_node * Quicksort::Q_Sort_partition_size(list_node * head, list_node * end, list_node ** newHead, list_node ** newTail)
{
	list_node *pivot = end;
	list_node *prev = nullptr, *cur = head, *tail = pivot;
	if ((cur->Get_type() == is_catalog) && (pivot->Get_type() == is_catalog)) {
		// During partition, both the head and end of the list might change 
		// which is updated in the newHead and newEnd variables 
		while (cur != pivot)
		{
			if (cur->Catalog_info.Get_size() < pivot->Catalog_info.Get_size())
			{
				// First node that has a value less than the pivot - becomes 
				// the new head 
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
				cur->next->prev = cur; // CARREFUL
			}
			else // If cur node is greater than pivot 
			{
				// Move cur node to next of tail, and change tail 
				if (prev)
					prev->next = cur->next;
				prev->next->prev = prev;	// ADDED
				list_node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail->next->prev = tail;	// ADDED
				tail = cur;
				cur = tmp;
			}
		}
	}
	else if ((cur->Get_type() == is_catalog) && (pivot->Get_type() == is_file))
	{
		// During partition, both the head and end of the list might change 
		// which is updated in the newHead and newEnd variables 
		while (cur != pivot)
		{
			if (cur->Catalog_info.Get_size() < pivot->File_info.Get_size())
			{
				// First node that has a value less than the pivot - becomes 
				// the new head 
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
				cur->next->prev = cur; // CARREFUL
			}
			else // If cur node is greater than pivot 
			{
				// Move cur node to next of tail, and change tail 
				if (prev)
					prev->next = cur->next;
				prev->next->prev = prev;	// ADDED
				list_node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail->next->prev = tail;	// ADDED
				tail = cur;
				cur = tmp;
			}
		}
	}

	else if ((cur->Get_type() == is_file) && (pivot->Get_type() == is_catalog))
	{
		// During partition, both the head and end of the list might change 
		// which is updated in the newHead and newEnd variables 
		while (cur != pivot)
		{
			if (cur->File_info.Get_size() < pivot->Catalog_info.Get_size())
			{
				// First node that has a value less than the pivot - becomes 
				// the new head 
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
				cur->next->prev = cur; // ADDED
			}
			else // If cur node is greater than pivot 
			{
				// Move cur node to next of tail, and change tail 
				if (prev)
					prev->next = cur->next;
				prev->next->prev = prev;	// ADDED
				list_node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail->next->prev = tail;	// ADDED
				tail = cur;
				cur = tmp;
			}
		}
	}

	else
	{
		// During partition, both the head and end of the list might change 
		// which is updated in the newHead and newEnd variables 
		while (cur != pivot)
		{
			if (cur->File_info.Get_size() < pivot->File_info.Get_size())
			{
				// First node that has a value less than the pivot - becomes 
				// the new head 
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
				cur->next->prev = cur; // CARREFUL
			}
			else // If cur node is greater than pivot 
			{
				// Move cur node to next of tail, and change tail 
				if (prev)
					prev->next = cur->next;
				prev->next->prev = prev;	// ADDED
				list_node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail->next->prev = tail;	// ADDED
				tail = cur;
				cur = tmp;
			}
		}
	}
	// If the pivot data is the smallest element in the current list, 
	// pivot becomes the head 
	if ((*newHead) == nullptr)
		(*newHead) = pivot;

	// Update newEnd to the current last node 
	(*newTail) = tail;

	// Return the pivot node 
	return pivot;

}

list_node * Quicksort::getTail(list_node * cur)
{
	while (cur != nullptr && cur->next != nullptr) {
		cur = cur->next;
	}
	return cur;
}

list_node* Quicksort::_quickSort_time_recur(list_node * head, list_node * end)
{
	// base condition 
	if (!head || head == end) {
		return head;
	}

	list_node *newHead = nullptr, *newEnd = nullptr;

	// Partition the list, newHead and newEnd will be updated 
	// by the partition function 
	list_node *pivot = Q_Sort_partition_time(head, end, &newHead, &newEnd);

	// If pivot is the smallest element - no need to recur for 
	// the left part. 
	if (newHead != pivot)
	{
		// Set the node before the pivot node as NULL 
		list_node *tmp = newHead;
		while (tmp->next != pivot) {
			tmp = tmp->next;
		}
		tmp->next = nullptr;

		// Recur for the list before pivot 
		newHead = _quickSort_time_recur(newHead, tmp);

		// Change next of last node of the left half to pivot 
		tmp = getTail(newHead);
		tmp->next = pivot;
	}

	// Recur for the list after the pivot element 
	pivot->next = _quickSort_time_recur(pivot->next, newEnd);

	return newHead;
}

void Quicksort::quickSort_time(list_node ** headRef)
{
	(*headRef) = _quickSort_time_recur(*headRef, getTail(*headRef));
}

Quicksort::Quicksort()
{
}


Quicksort::~Quicksort()
{
}
