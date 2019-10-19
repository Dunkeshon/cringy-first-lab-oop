//I need to write other menu , because me logic has changed. Firstly i need to create catalogs and files inside 
//the first catalog, and then decide which ones i want to put in list (and what operations i should do on them) 
#include "pch.h"
#include <iostream>
#include "FILE.h"
#include "mylist.h"
#include "list_realisation.h"
//#include <vector>
using namespace std;
void menu(list_realisation<file> &list,int &input);
int main()
{
	int input;// используется в меню
	//vector<int> files;//количество файлов 
	list_realisation<file> list;
	menu(list,input);
	cout << "you escaped the menu";
	return 0;
}
/*
int main()
{
	string input;// используется в меню
	//vector<int> files;//количество файлов
	list_realisation<file> list;

	menu:
	cout << "to add a file press 1 : "<<endl;
	cout << "to print your list press 2 : "<<endl;
	cout << "to delete tour list press 3 :" << endl;
	cout << "to delete a file press 4 :" << endl;
	cout << "to insert a file inside your list press 5 : " << endl;

	cin >> input;
	if (input == "1") {
		list.addEl();
	}
	if (input == "2") {
		list.printFuncList();
	}
	if (input == "3") {
		list.deletion();
		cout << "your list have been deleted" << endl;
	}
	if (input == "4") {
		cout << "choose the name of the file which you want to delete: " << endl;
		list.printFuncList();
		if ((list.Get_head() == nullptr)) {
			goto skip;// УЖЕ ВЫВЕДЕТСЯ ЧТО СПИСОК ПУСТ , ПОЭТОМУ ВЫЙТИ ИЗ ФУНКЦИИУ
		}
		cout << "enter the chosen name :";
		cin >> input;
		list.delete_element(list.search_name(input));

	}
	if (input == "5") {
		cout << "choose the name of the file after which you want to insert a new file: " << endl;
		list.printFuncList();
		if ((list.Get_head() == nullptr)) {
			goto skip;// УЖЕ ВЫВЕДЕТСЯ ЧТО СПИСОК ПУСТ , ПОЭТОМУ ВЫЙТИ ИЗ ФУНКЦИИУ
		}
		cout << "enter the chosen name :";
		cin >> input;
		list.insertion(list.search_name(input));

	}
	skip:// СЮДЫ ВЫХОДИМ
	goto menu;
	//autism
	return 0;
}
}*/

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
