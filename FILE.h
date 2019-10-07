#pragma once
#include <string>
#include <iostream>

using namespace std;

template <class T,class V>
class file
{
private:
	string _file_type;
protected:
	T _name;
	V _size;
	T _time;
	T _changed_time;
public:
	file();
	~file();
	void print_info();
	T Get_name();
	V Get_size();
	T Get_time();
	T Get_changed_time();
	T Get_type();
	/*T Get(fileInfo);*/
};


#include "File.hxx"