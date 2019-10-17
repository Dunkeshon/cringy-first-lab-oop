#include "System_object.h"



System_object::System_object()
{
}


System_object::~System_object()
{
}

void System_object::set_common_info()
{
	string temp_name;
	int temp_size;
	cout << "enter name : ";
	cin >> temp_name;
	cout << "enter size : ";
	cin >> temp_size;
	cout << "enter the time of creation : " << endl;
	_time.SetTime();
	cout << "enter the time of the last change : " << endl;
	_changed_time.SetTime();
	_name = temp_name;
	_size = temp_size;
}

void System_object::print_common_info()//вывод информации о файле 
{
	//cout << '\t' << "File info: " << '\n';
	cout << "File _name: " << _name << '\n';
	cout << "File _size: " << _size << '\n';
	cout << "Time of creation: ";
	_time.PrintTime();
	cout << "Time of the last change: ";
	_changed_time.PrintTime();
}

/**
геттеры для получиния информации из private полей
*/

string System_object::Get_name() const
{
	return _name;
}
int System_object::Get_size() const
{
	return _size;
}

Taime System_object::Get_time() const
{
	return _time;
}

Taime System_object::Get_changed_time() const
{
	return _changed_time;
}



