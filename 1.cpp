//I need to write other menu , because me logic has changed. Firstly i need to create catalogs and files inside 
//the first catalog, and then decide which ones i want to put in list (and what operations i should do on them) 
#include "pch.h"
#include <iostream>
#include "FILE.h"
#include "list_node.h"
#include "list_realisation.h"
#include "TreeNode.h"
//#include <vector>
void menu(TreeNode &current,int &input);
using namespace std;
int main() {
	TreeNode Mytree;//tree, that we will use to store objects
	int input;// используется в меню
	return 0;
}
void menu(TreeNode &current, int &input)
{
	string input_name;
	cout << "\t\t  MENU " << endl;
	if ((current.info.Get_parent()==0) && (current.info.is_empty())) {// if current object don't have parent and is empty create first element
		cout << "To create first element press 1: " << endl;
	}
	cout << "\t To add a file press 1 : " << endl;

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