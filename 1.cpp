
#include "pch.h"
#include <iostream>
#include "FILE.h"
#include "mylist.h"
#include "list_realisation.h"
//#include <vector>
using namespace std;
//void menu();
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
/*
 void menu( )
{
	char input;
	cout << "to add a file and create a list press 1 : ";
	cin >> input;
	switch (input)
	{
	case '1':
	default:
		break;
	}
}*/
