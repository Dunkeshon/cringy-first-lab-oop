#pragma once
#include "System_object.h"
#include "Catalog.h"
class file :public System_object
{
private:
	Catalog *parent;// i need to set parent
	string _file_type;
public:
	file();
	~file();
	void set_info(Catalog *father);// i will call this method for a file , created by method of catalog "Create_file_child"
	void print_info();
	string Get_type() const;


};
#include"FILE.hxx"