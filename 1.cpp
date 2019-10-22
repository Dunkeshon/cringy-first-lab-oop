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

void menu(TreeNode *current,int &input);
void file_element_menu(file *current, int &input,list_realisation<Catalog> &Mylist, TreeNode *Catalog_node);
void catalog_element_menu(Catalog *current, int &input, list_realisation<Catalog> &Mylist, TreeNode *Catalog_node);


int main() {
	TreeNode Mytree;//tree, that we will use to store objects
	list_realisation<Catalog> Mylist;
	int input;// используется в меню
	menu(&Mytree,input);
	return 0;
}
void menu(TreeNode *current, int &input)
{
	string input_name;
	cout << "\t\t  MENU " << endl;
	if ((current->info.Get_parent()==0) && (current->info.is_empty())) {// if current object don't have parent and is empty create first element
		cout << "To create first element press 1: " << endl;
		cin >> input;
		if (input == 1) {
			current->info.set_info(nullptr);//set info to 1-st el and say that he hasn't got father
		}
	}
	//checkout
}

void file_element_menu(file *current,int &input, list_realisation<Catalog> &Mylist,TreeNode *Catalog_node) {
	cout << "Print file info press 1: " << endl;
	cout << "Add file to list press 2: " << endl;
	cout << "Checkout parent press 3:" << endl;
	cout << ">>>";
	cin >> input;
	switch (input)
	{
	case 1: current->print_info(); break;
	case 2: Mylist.addEl(current); break;// add to list; break;
	case 3: catalog_element_menu(current->Get_parent(), input, Mylist, Catalog_node);//checkout
 	 break;
	default: 
		break;
	}
}
void catalog_element_menu(Catalog *current,int &input, list_realisation<Catalog> &Mylist,TreeNode *Catalog_node)// checkout catalog
{
	cout << "\t Print this catalog info press 1: " << endl;
	cout << "\t Add this catalog to list press 2: " << endl;
	cout << "\t Checkout parent press 3:" << endl;
	cout << "\t Create a file inside this catalog press 4:" << endl;
	cout << "\t Create a catalog inside this catalog press 5: " << endl;
	cout << "\t Print children files press 6:" << endl;
	cout << "\t Print children catalogs press 7:" << endl;
	cout << "\t checkout to children file press 8: " << endl;// need to choose the name of file and then checkout choosen file by pointer
	cout << "\t checkout to children catalog press 9: " << endl;// same for catalog
	cout << "\t Return to menu press 10 :" << endl;
	cout << ">>>";
	cin >> input;

	switch (input)
	{
	case 1: current->print_info(); break;
	case 2: // add to list; break;
	case 3: catalog_element_menu(current->Get_parent(), input, Mylist, Catalog_node);//checkout
		break;
	case 4: 
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