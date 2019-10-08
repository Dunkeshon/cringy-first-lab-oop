#pragma once
#include <string>
#include <iostream>
#include "Taime.h"

using namespace std;

template <class T,class V>
class file
{
private:
	string _file_type;
protected:
	T _name;
	V _size;
	Taime _time;
	Taime _changed_time;
public:
	file();
	~file();
	void print_info();
	T Get_name() const;
	V Get_size() const;
	Taime Get_time() const;
	Taime Get_changed_time() const;
	T Get_type() const;

};


#include "File.hxx"