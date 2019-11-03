//I need to write other menu , because me logic has changed. Firstly i need to create catalogs and files inside 
//the first catalog, and then decide which ones i want to put in list (and what operations i should do on them) 
#include "pch.h"
#include <iostream>
#include "Catalog.h"
#include "FILE.h"
#include "list_node.h"
#include "list_realisation.h"
#include "TreeNode.h"
//#include <vector>

using namespace std;

void menu(TreeNode *current,int &input, list_realisation *Mylist,string &input_name);
void file_element_menu(file *current, // pointer to current file 
						int &input, // users input
						list_realisation *Mylist, // list
						TreeNode * father_Tree_node,  // pointer to father TreeNode . Catalog_node->info : father of current file
						string &input_name); // users input of name 
void catalog_element_menu(TreeNode *Tree_node, // pointer to current catalog (with children) 
						int &input, // users input
						list_realisation *Mylist, // list
						string &input_name);// users input of name
//void catalog_element_menu(file current, int &input, list_realisation &Mylist, TreeNode *Catalog_node);//acces from file

int main() {
	TreeNode Mytree;//tree, that we will use to store objects
	list_realisation Mylist;
	int input;// используется в меню
	string input_name;
	menu(&Mytree,input,&Mylist,input_name);
	return 0;
}
void menu(TreeNode *current, int &input, list_realisation *Mylist, string &input_name)
{
	cout << "\t\t  MENU " << endl;
	if ((current->info.Get_parent()==nullptr) && (current->info.is_empty())) {// if current object don't have parent and is empty create first element
		cout << "To create first element press 1: " << endl;
		cin >> input;
		if (input == 1) {
			current->info.set_info(nullptr);//set info to 1-st el and say that he hasn't got father
			cout << "first element created" << endl;
		}
		catalog_element_menu(current, input, Mylist, input_name);
	}	
	//
	// menu of list 
}

void file_element_menu(file *current,int &input, list_realisation *Mylist, TreeNode * father_Tree_node, string &input_name) {
	cout << "\t\t  file menu" << endl;
	cout << "Print file info press 1:" << endl;
	cout << "Add file to list press 2:" << endl;
	cout << "Checkout parent press 3:" << endl;
	cout << "Return to menu press 4:" << endl;
	cout << ">>>";
	cin >> input;
	switch (input)
	{
		case 1: current->print_info();
			file_element_menu(current, input, Mylist, father_Tree_node, input_name); break;
		case 2: Mylist->addEl_File(*current);
			cout << "file was added to list" << endl;
			file_element_menu(current, input, Mylist, father_Tree_node, input_name); break;
		case 3: catalog_element_menu(father_Tree_node, input, Mylist, input_name);//checkout parent
		 break;
		case 4: menu(father_Tree_node, input, Mylist, input_name);
		default: 
			break;
	}
}
void catalog_element_menu(TreeNode *Tree_node, // pointer to current catalog (with children) 
	int &input, // users input
	list_realisation *Mylist, // list
	string &input_name)// users input of name
	//checkout catalog
{
	cout << "\t Print this catalog info press 1: " << endl;
	cout << "\t Add this catalog to list press 2: " << endl;
	cout << "\t Checkout parent press 3:" << endl;
	cout << "\t Create a file inside this catalog press 4:" << endl;
	cout << "\t Create a catalog inside this catalog press 5: " << endl;
	cout << "\t Print children files press 6:" << endl; // print names
	cout << "\t Print children catalogs press 7:" << endl; // print names
	cout << "\t checkout to children file press 8: " << endl;// need to choose the name of file and then checkout choosen file by pointer
	cout << "\t checkout to children catalog press 9: " << endl;// same for catalog
	cout << "\t Return to menu press 10 :" << endl;
	cout << ">>>";
	cin >> input;

	switch (input)
	{
	case 1: Tree_node->info.print_info();
		catalog_element_menu(Tree_node, input, Mylist, input_name);
		break;
	case 2: Mylist->addEl_Catalog(Tree_node->info);
		cout << "catalog was added to list" << endl;
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
	case 8: cout << "enter name of file that you want to checkout " << endl;
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
	case 9:
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
	case 10:
		menu(Tree_node, input, Mylist, input_name);
	default:
		break;
	}
	
}


/*

{
	int input;// используется в меню
	//vector<int> files;//количество файлов 
	list_realisation<file> list;
	menu(list,input);
	cout << "you escaped the menu";
	return 0;
}

void menu(list_realisation<file> &list,int &input)
{
	string input_name;
	cout << "\t\t  MENU " << endl;
	cout << "\t To add a file press 1 : " << endl;
	cout << "\t To print your list press 2 : " << endl;
	cout << "\t To delete your list press 3 :" << endl;
	cout << "\t To delete a file press 4 :" << endl;
	cout << "\t To insert a file inside your list press 5 : " << endl;
	cout << "\t To exit from menu press 6 :" << endl;
	cout << ">>>";
	cin >> input;
	switch (input)
	{
	case 1:
		if (input == 1) {
		//	list.addEl();
		}
		break;
	case 2:
		if (input == 2) {
			list.printFuncList();
		}
		break;

	case 3:
		list.deletion();
		cout << "your list have been deleted" << endl;
		break;
	case 4:
		cout << "choose the name of the file which you want to delete: " << endl;
		list.printFuncList();
		if ((list.Get_head() == nullptr)) {
			break;
			//goto skip;// УЖЕ ВЫВЕДЕТСЯ ЧТО СПИСОК ПУСТ , ПОЭТОМУ ВЫЙТИ ИЗ ФУНКЦИИ,нужно вызвать меню
		}
		cout << "enter the chosen name :";
		cin >> input_name;
		list.delete_element(list.search_name(input_name));
		break;
	case 5:
		cout << "choose the name of the file after which you want to insert a new file: " << endl;
		list.printFuncList();
		if ((list.Get_head() == nullptr)) {
			break;// УЖЕ ВЫВЕДЕТСЯ ЧТО СПИСОК ПУСТ , ПОЭТОМУ ВЫЙТИ ИЗ ФУНКЦИИУ
		}
		cout << "enter the chosen name :";
		cin >> input_name;
		//list.insertion(list.search_name(input_name)); нужно добавить адресс єлемента который нужно вставить
		break;
	case 6: 
		return;
	default:
		break;
	}
	menu(list, input);
}
*/