//this class is a super  class for "file" and "catalog". It has common info and methods for both of them
#pragma once
#include <iostream>
#include <string>
#include "Taime.h"

using namespace std;

class Catalog
{
protected:
	Catalog *parent;
	string _name;
	int _size;
	Taime _time;
	Taime _changed_time;
public:
	bool is_empty();
	void set_common_info(Catalog *parent);
	void print_common_info();
	string Get_name() const;
	int Get_size() const;
	Taime Get_time() const;
	Taime Get_changed_time() const;
	Catalog* Get_parent() const;
	Catalog();
	~Catalog();
};

#include "Catalog.hxx"