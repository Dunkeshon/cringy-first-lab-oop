#include "Catalog.h"


Catalog::Catalog()
{
	parent = nullptr;
	_name = string();
	_size = 0;
	_time = Taime();
	_changed_time = Taime();
}


Catalog::~Catalog()
{
}

bool Catalog::is_empty()
{
	if (_name==""&& _size==0)
	{
		return true;
	}
	return false;
}

void Catalog::set_info(Catalog *parent)
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

void Catalog::print_info()//print
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
getters
*/

string Catalog::Get_name() const
{
	return _name;
}
int Catalog::Get_size() const
{
	return _size;
}

Taime Catalog::Get_time() const
{
	return _time;
}

Taime Catalog::Get_changed_time() const
{
	return _changed_time;
}

Catalog* Catalog::Get_parent() const
{
	return parent;
}



