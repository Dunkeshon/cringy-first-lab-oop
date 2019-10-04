#pragma once
#include <string>
#include <iostream>
using namespace std;
class file
{
private:
	string _file_type;
protected:
	string _name;
	int _size;
	string _time;
	string _changed_time;
public:
	file();
	~file();
	void print_info();
};

