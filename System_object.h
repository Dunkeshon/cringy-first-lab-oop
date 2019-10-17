#pragma once
#include <string>
#include <iostream>
#include "Taime.h"

using namespace std;

class System_object
{
protected:
	//Catalog *parent;
	string _name;
	int _size;
	Taime _time;
	Taime _changed_time;
public:
	void set_common_info();
	void print_common_info();
	string Get_name() const;
	int Get_size() const;
	Taime Get_time() const;
	Taime Get_changed_time() const;
	//void Set_Parent(Catalog *father);
	System_object();
	~System_object();
};

#include "System_object.hxx"