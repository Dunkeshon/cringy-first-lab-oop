#pragma once
#include "System_object.h"
#include "Catalog.h"
class file:public System_object
{
private:
	Catalog *parent;
	string _file_type;
public:
	file();
	~file();
	void set_info(Catalog *father);
	void print_info();
	string Get_type() const;


};


#include "File.hxx"