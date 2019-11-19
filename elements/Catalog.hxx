/**
	*file
	*brief hxx file containing implementations of Catalog.h
*/

#include "Catalog.h"

/**
	*brief initialize all protected fields with 0
*/
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
/**
	*brief overloaded assignment operator
	@param other Other Catalog class that we assign to current Catalog
	*details assign all fields of other Catalog to this
	@return *this
*/
 Catalog Catalog::operator=(Catalog other)
{
	 _name = other._name;
	 _size = other._size;
	 _time = other._time;
	 _changed_time = other._changed_time;
	return *this;
}
 /**
	*brief returns true, if this catalog wasn't created, false if it exists and has a proper name and size
	@return true, if this catalog has empty name and size ==0 , false if it has name and size that are bigger than 0
*/
bool Catalog::is_empty()
{
	if (_name==""&& _size==0)
	{
		return true;
	}
	return false;
}
/**
	*brief set all private fields of file class, by user's input
	@param parent A pointer to Catalog which set the parent of current catalog
	*details output and input in console

*/
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
	this->parent = parent;
}
/**
	*brief print in console all private fields of catalog class
	*details output and input in console
*/
void Catalog::print_info()//print
{
	//cout << '\t' << "File info: " << '\n';
	cout << "Catalog name: " << _name << '\n';
	cout << "Catalog size: " << _size << '\n';
	cout << "Time of creation: ";
	_time.PrintTime();
	cout << "Time of the last change: ";
	_changed_time.PrintTime();
}


/**
	*returns protected variable string _name of class catalog
	@return string _name of class catalog
*/
string Catalog::Get_name() const
{
	return _name;
}
/**
	*returns protected variable int _size of class catalog
	@return int _size of class catalog
*/
int Catalog::Get_size() const
{
	return _size;
}
/**
	*returns protected variable Taime _time (time of creation) of class catalog
	@return Taime _time of class catalog
*/
Taime Catalog::Get_time() const
{
	return _time;
}
/**
	*returns protected variable Taime _changed_time (time of last change) of class catalog
	@return Taime _changed_time of class catalog
*/
Taime Catalog::Get_changed_time() const
{
	return _changed_time;
}
/**
	*returns pointer to parent of class catalog
	@return pointer to parent of class catalog
*/
Catalog* Catalog::Get_parent() const
{
	return parent;
}



