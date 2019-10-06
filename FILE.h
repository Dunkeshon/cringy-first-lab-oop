#pragma once
#include <string>
#include <iostream>
using namespace std;
enum fileInfo
{
	name,Size,time,changed_time,file_type
};
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
	T Get(fileInfo);
};

