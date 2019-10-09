#pragma once
#include <string>
#include <iostream>
#include "Taime.h"

using namespace std;


class file
{
private:
	string _file_type;
protected:
	string _name;
	int _size;
	Taime _time;
	Taime _changed_time;
public:
	file();
	~file();
	void set_info();
	void print_info();
	string Get_name() const;
	int Get_size() const;
	Taime Get_time() const;
	Taime Get_changed_time() const;
	string Get_type() const;

};


#include "File.hxx"