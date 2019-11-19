/**
	*file
	*brief hxx file containing implementations of list_realisation.h
*/
#include "pch.h"
#include "list_realisation.h"

/**
	*brief Constructor, initialisation of private fields with nullptr
*/
list_realisation::list_realisation()
{
	head = tail=nullptr;
}
/**
	*brief Destructor, delete all list
*/
list_realisation::~list_realisation()
{
	list_node *current = head;
	list_node *temp;

	while (current)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
}
/**
	*brief Print list in console
	*details output all fields of list nodes in console.If list is empty : message "list is empty".
*/
void list_realisation::printFuncList()
{
	list_node *tmp = new list_node;
	 tmp = head;
	if (head != tail) {
		while (tmp){
			if (tmp->Get_type() == is_catalog) {
				tmp->Catalog_info.print_info();
			}
			else if (tmp->Get_type() == is_file) {
				tmp->File_info.print_info();
			}
			cout << "######################" << endl;
			tmp = tmp->next;
		} 
	}
	else if ((head == tail)&&(head!=nullptr))
	{
		if (tmp->Get_type() == is_catalog) {
			tmp->Catalog_info.print_info();
		}
		else if (tmp->Get_type() == is_file) {
			tmp->File_info.print_info();
		}
	}
	else
	{
		cout << "list is empty" << endl;
	}
}
/**
	*brief adds catalog in the list
	@param Element A copy of already existing catalog that we add in the list
	*details we set that this list node will store Catalog, by setting type_of_el to is_catalog
*/
void list_realisation::addEl_Catalog( Catalog Element)
{
	list_node *temp = new list_node();
	temp->Set_type_of_el(is_catalog);
	temp->Catalog_info = Element;

	if (head == nullptr) {
		head = temp;
		tail = temp;
	}
	else
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
}
/**
	*brief adds file in the list
	@param Element A copy of already existing element that we add in the list
	*details we set that this list node will store File, by setting type_of_el to is_file
*/
void list_realisation::addEl_File(file Element)
{
	list_node *temp = new list_node();
	temp->Set_type_of_el(is_file);
	temp->File_info = Element;

	if (head == nullptr) {
		head = temp;
		tail = temp;
	}
	else
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
}
/**
	*brief deletion of list
	*details Delete all information and then set head=tail=nullptr , so that we can use this list again
*/
void list_realisation::deletion()
{
	auto current = head;
	auto temp = head;
	while (current)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
	head = nullptr;
	tail = nullptr;
}
/**
	*brief searching by name, returns adress of an element with such name
	@param [in] key A name that we search in our list
	@return adress of an element whose field _name = key
	*details If list hasn't got any element with name we searched for : print message "file with this name doesn't exist".
*/
list_node* list_realisation::search_name(string key)
{
	list_node *temp = new list_node;
	temp = head;
	while (temp) {
		if (temp->Get_type()==is_catalog&& temp->Catalog_info.Get_name() == key){
			return temp;
		}
		else if (temp->Get_type() == is_file && temp->File_info.Get_name() == key) {
			return temp;
		}
		else {
			temp = temp->next;
		}
	}
	cout << "file with this name doesn't exist" << endl;
	return nullptr;
}
/**
	*brief Returns pointer to the tail of the list
	@return pointer to tail
*/
 list_node * list_realisation::Get_head()
{
	return head;
}
/**
	*brief Returns pointer to the head of the list
	@return pointer to head
*/
 list_node * list_realisation::Get_tail()
 {
	 return tail;
 }
/**
	*brief delete element from the list
	@param [in] el_to_delete A pointer to an element that we want to delete from list
	*details Prints message "element has been deleted" after deletion of the element
*/
 void list_realisation::delete_element(list_node * el_to_delete)
 {	 if ((el_to_delete == head) && (el_to_delete == tail))
	 {
		 delete el_to_delete;
		 head = nullptr;
		 tail = nullptr;
		 cout << "element has been deleted" << endl;
		 return;
	 }
	 else if (el_to_delete==head) {
		 el_to_delete->next->prev = nullptr;
		 head = el_to_delete->next;
		 delete el_to_delete;
	 }
	 else if(el_to_delete==tail){
		 el_to_delete->prev->next = nullptr;
		 tail = el_to_delete->prev;
		 delete el_to_delete;
	 }
	 
	 else {
		 el_to_delete->prev->next = el_to_delete->next;
		 el_to_delete->next->prev = el_to_delete->prev;
		 delete el_to_delete;
	 }
	 cout << "element has been deleted" << endl;
 }
/**
	*brief Realization of merge sort
	*details user choose based on which parameter he want to sort our list.
	After sorting our list go through the list and renew our tail 
 */
 void list_realisation::merge_sort()
 {
	 cout << "\t\t Choose the parameter, based on which you want to sort your list " << endl;
	 int i;
	 cout << "\t sort by time of creation press 1 "<< endl;
	 cout << "\t sort by changed time press 2 " << endl;
	 cout << "\t sort by name press 3 " << endl;
	 cout << "\t sort by size press 4 " << endl;
	 cout << ">>>";
	 cin >> i;
	 list_node* temp;
	 switch (i)
	 {
	 case 1: MergeSort_time(&head);
		 temp = head;
		 while (temp!=nullptr) {
			 if (temp->next == nullptr) {
				 tail = temp;
			 }
			 temp = temp->next;
		 };
		 break;
	 case 2: MergeSort_changed_time(&head);
		 temp = head;
		 while (temp != nullptr) {
			 if (temp->next == nullptr) {
				 tail = temp;
			 }
			 temp = temp->next;
		 };
		 break;
	 case 3: MergeSort_name(&head);
		 temp = head;
		 while (temp != nullptr) {
			 if (temp->next == nullptr) {
				 tail = temp;
			 }
			 temp = temp->next;
		 };
		 break;
	 case 4: MergeSort_size(&head);
		 temp = head;
		 while (temp != nullptr) {
			 if (temp->next == nullptr) {
				 tail = temp;
			 }
			 temp = temp->next;
		 };
		 break;
	 default:
		 break;
	 }
 }
/**
	*brief Realization of quick sort
	*details user choose based on which parameter he want to sort our list.
	I don't need to renew tail because i do it in the method of quick_sort 
 */
 void list_realisation::quick_sort()
 {
	 cout << "\t\t Choose the parameter, based on which you want to sort your list " << endl;
	 int i;
	 cout << "\t sort by time of creation press 1 " << endl;
	 cout << "\t sort by changed time press 2 " << endl;
	 cout << "\t sort by name press 3 " << endl;
	 cout << "\t sort by size press 4 " << endl;
	 cout << ">>>";
	 cin >> i;
	 list_node* temp;
	 switch (i)
	 {
	 case 1:quickSort_time(&head, &tail);
		 break;
	 case 2: quickSort_changed_time(&head, &tail);
		 break;
	 case 3: quickSort_name(&head, &tail);
		 break;
	 case 4: quickSort_size(&head, &tail);
		 break;
	 default:
		 break;
	 }
 }
/**
	*brief Realization of insertion sort
	*details user choose based on which parameter he want to sort our list.
	After sorting our list go through the list and renew our tail
*/
  void list_realisation::insertion_sort()
 {
	  cout << "\t\t Choose the parameter, based on which you want to sort your list " << endl;
	  int i;
	  cout << "\t sort by time of creation press 1 " << endl;
	  cout << "\t sort by changed time press 2 " << endl;
	  cout << "\t sort by name press 3 " << endl;
	  cout << "\t sort by size press 4 " << endl;
	  cout << ">>>";
	  cin >> i;
	  list_node* temp;
	  switch (i)
	  {
	  case 1: insertionSort_time(&head);
		  temp = head;
		  while (temp != nullptr) {
			  if (temp->next == nullptr) {
				  tail = temp;
			  }
			  temp = temp->next;
		  };
		  break;
	  case 2: insertionSort_changed_time(&head);
		  temp = head;
		  while (temp != nullptr) {
			  if (temp->next == nullptr) {
				  tail = temp;
			  }
			  temp = temp->next;
		  };
		  break;
	  case 3: insertionSort_name(&head);
		  temp = head;
		  while (temp != nullptr) {
			  if (temp->next == nullptr) {
				  tail = temp;
			  }
			  temp = temp->next;
		  };
		  break;
	  case 4: insertionSort_size(&head);
		  temp = head;
		  while (temp != nullptr) {
			  if (temp->next == nullptr) {
				  tail = temp;
			  }
			  temp = temp->next;
		  };
		  break;
	  default:
		  break;
	  }
 }
