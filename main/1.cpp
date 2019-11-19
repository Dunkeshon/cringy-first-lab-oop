/**
	*file
	*brief Main C++ file
	This file contains main function
*/

#include "pch.h"
#include <iostream>
#include "Catalog.h"
#include "FILE.h"
#include "list_node.h"
#include "list_realisation.h"
#include "TreeNode.h"


using namespace std;
/**
*param[in] current A pointer to node, that contains catalog and its children 
*param[in] input a reference to user's input, that allows you to choose menu options
*param[in] Mylist a pointer to list, that i use in my progam  
*param[in] input_name a reference to user's input, where tou can input names
*brief basic menu, where you can create your first catalog
*/
void menu(TreeNode *current,int &input, list_realisation *Mylist,string &input_name);
/**
*param[in] current A pointer to current file 
*param[in] input a reference to user's input, that allows you to choose menu options
*param[in] Mylist a pointer to list, that i use in my progam
 *param[in] father_Tree_node A pointer to father node, that contains catalog and its children 
*param[in] input_name a reference to user's input, where tou can input names
 *brief file element menu : list of option that you can do to your file 
*/
void file_element_menu(file *current, // pointer to current file 
						int &input, // users input
						list_realisation *Mylist, // list
						TreeNode * father_Tree_node,  // pointer to father TreeNode . Catalog_node->info : father of current file
						string &input_name); // users input of name 
/**
*param[in] current A pointer to node, that contains current catalog and its children
*param[in] input a reference to user's input, that allows you to choose menu options
*param[in] Mylist a pointer to list, that i use in my progam
*param[in] input_name a reference to user's input, where tou can input names
*brief menu of catalog element, where you can choose options that you can do to your catalog
*/
void catalog_element_menu(TreeNode *Tree_node, // pointer to current catalog (with children) 
						int &input, // users input
						list_realisation *Mylist, // list
						string &input_name);// users input of name
/**
*param[in] input a reference to user's input, that allows you to choose menu options
*param[in] Mylist a pointer to list, that i use in my progam
*param[in] input_name a reference to user's input, where tou can input names
*brief menu of list, where you can choose options, that you can do to your list
*/
void list_menu(int &input, // users input
				list_realisation *Mylist, // list
				string &input_name);// users input of name


int main() {
	TreeNode Mytree;//tree, that we will use to store objects
	list_realisation Mylist;
	int input;// is used in menu
	string input_name; // is used in menu
	menu(&Mytree,input,&Mylist,input_name);
	return 0;
}

/**
*param[in] current A pointer to node, that contains catalog and its children
*param[in] input a reference to user's input, that allows you to choose menu options
*param[in] Mylist a pointer to list, that i use in my progam
*param[in] input_name a reference to user's input, where tou can input names
*brief basic menu, where you can create your first catalog
*/
void menu(TreeNode *current, int &input, list_realisation *Mylist, string &input_name)
{
	cout << "\t\t  MENU " << endl;
	if ((current->info.Get_parent()==nullptr) && (current->info.is_empty())) {// if current object don't have parent and is empty create first element
		cout << "\t To create first element press 1: " << endl;
		cout << ">>>";
		cin >> input;
		if (input == 1) {
			current->info.set_info(nullptr);//set info to 1-st el and say that he hasn't got father
			cout << "first element created" << endl;
		}
		system("pause");
		system("cls");
		catalog_element_menu(current, input, Mylist, input_name);
	}	
}
/**
*param[in] current A pointer to current file
*param[in] input a reference to user's input, that allows you to choose menu options
*param[in] Mylist a pointer to list, that i use in my progam
 *param[in] father_Tree_node A pointer to father node, that contains catalog and its children
*param[in] input_name a reference to user's input, where tou can input names
 *brief file element menu : list of option that you can do to your file
*/
void file_element_menu(file *current,int &input, list_realisation *Mylist, TreeNode * father_Tree_node, string &input_name) {
	cout << "\t\t  file "<< current->Get_name() <<" menu" << endl;
	cout << "\t Print file info press 1:" << endl;
	cout << "\t Add file to list press 2:" << endl;
	cout << "\t Checkout parent press 3:" << endl;
	cout << "\t Menu of list press 4:" << endl;
	cout << ">>>";
	cin >> input;
	switch (input)
	{
		case 1: current->print_info();
			file_element_menu(current, input, Mylist, father_Tree_node, input_name); break;
		case 2: Mylist->addEl_File(*current);
			cout << "file "<< current->Get_name() << " was added to list" << endl;
			file_element_menu(current, input, Mylist, father_Tree_node, input_name); break;
		case 3: catalog_element_menu(father_Tree_node, input, Mylist, input_name);//checkout parent
		 break;
		case 4:
			list_menu(input, Mylist, input_name);
			file_element_menu(current, input, Mylist, father_Tree_node, input_name); break;
		default: 
			break;
	}
}
/**
*param[in] current A pointer to node, that contains current catalog and its children
*param[in] input a reference to user's input, that allows you to choose menu options
*param[in] Mylist a pointer to list, that i use in my progam
*param[in] input_name a reference to user's input, where tou can input names
*brief menu of catalog element, where you can choose options that you can do to your catalog
*/
void catalog_element_menu(TreeNode *Tree_node, // pointer to current catalog (with children) 
						int &input, // users input
						list_realisation *Mylist, // list
						string &input_name)// users input of name
						//checkout catalog
{
	cout << "\t\t  Catalog "<< Tree_node->info.Get_name() <<" menu" << endl;
	cout << "\t Print this catalog info press 1: " << endl;
	cout << "\t Add this catalog to list press 2: " << endl;
	cout << "\t Checkout parent press 3:" << endl;
	cout << "\t Create a file inside this catalog press 4:" << endl;
	cout << "\t Create a catalog inside this catalog press 5: " << endl;
	cout << "\t Print children files press 6:" << endl; // print names
	cout << "\t Print children catalogs press 7:" << endl; // print names
	cout << "\t Checkout to children file press 8: " << endl;// need to choose the name of file and then checkout choosen file by pointer
	cout << "\t Checkout to children catalog press 9: " << endl;// same for catalog
	cout << "\t Menu of list press 10 :" << endl;
	cout << ">>>";
	cin >> input;

	switch (input)
	{
	case 1: Tree_node->info.print_info();
		catalog_element_menu(Tree_node, input, Mylist, input_name);
		break;
	case 2: Mylist->addEl_Catalog(Tree_node->info);
		cout << "catalog "<< Tree_node->info.Get_name() <<" was added to list" << endl;
		catalog_element_menu(Tree_node, input, Mylist, input_name);
		break;
	case 3: 
		if (Tree_node->parent==nullptr) 
		{
			cout << "this catalog hasn't got a parent" << endl;
			catalog_element_menu(Tree_node, input, Mylist, input_name);
		}
		else 
		{
			catalog_element_menu(Tree_node->parent, input, Mylist, input_name);
		}
		break;
	case 4: Tree_node->create_file_children();
		catalog_element_menu(Tree_node, input, Mylist, input_name); 
		break;
	case 5: Tree_node->create_catalog_children(); 
		catalog_element_menu(Tree_node, input, Mylist, input_name);
		break;
	case 6: Tree_node->print_file_child_names() ;
		catalog_element_menu(Tree_node, input, Mylist, input_name); 
		break;
	case 7: Tree_node->print_catalog_child_names();
		catalog_element_menu(Tree_node, input, Mylist, input_name); 
		break;
	case 8: 
		if (Tree_node->file_children.empty())
		{
			cout << "This catalog hasn't got any files inside" << endl;
			catalog_element_menu(Tree_node, input, Mylist, input_name);
		}
		else
		{
			cout << "enter name of file that you want to checkout " << endl;
			cout << ">>>";
			cin >> input_name;
			if (Tree_node->search_child_file_by_name(input_name) != nullptr)
			{
				file_element_menu(Tree_node->search_child_file_by_name(input_name), input, Mylist, Tree_node, input_name);
			}
			else
			{
				cout << "there is no file with such name" << endl;
				catalog_element_menu(Tree_node, input, Mylist, input_name);
			}
			// найти по имени , если такой есть - чекаут этот элемент, если нет(нульпоинтер), чекаут тот же еллемент что был до этоого
		}
	case 9:
		if (Tree_node->catalog_children.empty())
		{
			cout << "This catalog hasn't got any catalogs inside" << endl;
			catalog_element_menu(Tree_node, input, Mylist, input_name);
		}
		else
		{
			cout << "enter name of catalog that you want to checkout " << endl;
			cout << ">>>";
			cin >> input_name;
			if (Tree_node->search_child_catalog_by_name(input_name) != nullptr)
			{
				catalog_element_menu(Tree_node->search_child_catalog_by_name(input_name), input, Mylist, input_name);
			}
			else
			{
				cout << "there is no catalog with such name" << endl;
				catalog_element_menu(Tree_node, input, Mylist, input_name);
			}
		}
	case 10:
		list_menu(input, Mylist, input_name);
		catalog_element_menu(Tree_node, input, Mylist, input_name);
	default:
		break;
	}
	
}
/**
*param[in] input a reference to user's input, that allows you to choose menu options
*param[in] Mylist a pointer to list, that i use in my progam
*param[in] input_name a reference to user's input, where tou can input names
*brief menu of list, where you can choose options, that you can do to your list
*/
void list_menu(int & input, list_realisation * Mylist, string & input_name)
{
	cout << "\t\t LIST MENU " << endl;
	cout << "\t To print your list press 1 : " << endl;
	cout << "\t To delete your list press 2 :" << endl;
	cout << "\t To delete an element from your list press 3 :" << endl;
	cout << "\t To sort your list press 4:" << endl;
	cout << "\t Exit list menu press 5 :" << endl;
	cout << ">>>";
	cin >> input;
	switch (input)
	{
	case 1: 
		Mylist->printFuncList();
		list_menu(input, Mylist, input_name);
		break;
	case 2:
		Mylist->deletion();
		cout << "your list have been deleted" << endl;
		list_menu(input, Mylist, input_name);
		break;
	case 3:
		cout << "choose the name of the element that you want to delete: " << endl;
		Mylist->printFuncList();
		if ((Mylist->Get_head() == nullptr)) {
			list_menu(input, Mylist, input_name);
			break;//message "list is empty" will be shown
		}
		cout << "enter the chosen name : ";
		cin >> input_name;
		Mylist->delete_element(Mylist->search_name(input_name));
		list_menu(input, Mylist, input_name);
		break;
	case 4:
		cout << "\t\t Choose sorting type " << endl;
		cout << "\t Merge sort press 1 : " << endl;
		cout << "\t Quick sort press 2 : " << endl;
		cout << "\t Insertion sort press 3 : " << endl;
		int i;
		cout << ">>>";
		cin >> i;
		if (i == 1) {
			Mylist->merge_sort();// contains menu of choosing the parameter on which we will sort
			cout << "Your list was sorted by merge sort" << endl;
		}
		else if (i == 2) {
			Mylist->quick_sort();// contains menu of choosing the parameter on which we will sort
			cout << "Your list was sorted by quick sort" << endl;
		}
		else if (i == 3) {
			Mylist->insertion_sort();// contains menu of choosing the parameter on which we will sort
			cout << "Your list was sorted by insertion sort" << endl;
		}
		list_menu(input, Mylist, input_name);
		break;
	case 5: break;
	default: break;
	}
}
