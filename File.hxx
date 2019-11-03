#include "pch.h"
#include"FILE.h"

file::file()
{
	_file_type = string();
}


file::~file()
{

}

void file::set_info(Catalog *parent) 
{
	Catalog::set_info(parent);// basic class function 
	string temp_file_type;
	cout << "enter the file type : ";
	cin >> temp_file_type;
	_file_type = temp_file_type;
}

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
getter
*/


string file::Get_type() const
{
	return _file_type;
}

file file::operator=(file other)
{
	_name = other._name;
	_size = other._size;
	_time = other._time;
	_changed_time = other._changed_time;
	_file_type = other._file_type;
	return *this;
}
