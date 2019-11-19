/**
	*file
	*brief hxx file containing implementations of FILE.h
*/
#include "pch.h"
#include"FILE.h"

/**
	*brief initialize all private fields with 0
*/
file::file()
{
	_file_type = string();
}


file::~file()
{

}

/**
#override virtual void set_info(Catalog *parent)
*brief set all private fields of file class, by user's input
@param parent A pointer to Catalog which set the parent of current file
*/
void file::set_info(Catalog *parent) 
{
	Catalog::set_info(parent);// basic class function 
	string temp_file_type;
	cout << "enter the file type : ";
	cin >> temp_file_type;
	_file_type = temp_file_type;
}
/**
#override virtual void Catalog :: print_info()
*brief print in console all private fields of file class
*/
void file::print_info()//print file info
{
	cout << "File name: " << _name << '\n';
	cout << "File size: " << _size << '\n';
	cout << "Time of creation: ";
	_time.PrintTime();
	cout << "Time of the last change: ";
	_changed_time.PrintTime();
	cout << "File type: " << _file_type << '\n';
}

/**
*returns protected variable string _file_type of class file
@return string _file_type of class file
*/
string file::Get_type() const
{
	return _file_type;
}
/**
*brief overloaded assignment operator
@param other Other file class that we assign to current file
*details assign all fields of other file to this
@return *this
*/
file file::operator=(file other)
{
	_name = other._name;
	_size = other._size;
	_time = other._time;
	_changed_time = other._changed_time;
	_file_type = other._file_type;
	return *this;
}
