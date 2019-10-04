#pragma once
#include <string>
using namespace std;
class file
{
protected:
	string _name;
	int _size;
	string _time;
	string _changed_time;
	string _file_type;
public:
	file();
	~file();
};

