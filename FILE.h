#pragma once
#include "Catalog.h"
class file :public Catalog
{
private:
	string _file_type;
public:
	file();
	~file();
	void set_info(Catalog *parent)override;// i will call this method for a file , created by method of catalog "Create_file_child"
	void print_info()override;
	string Get_type() const;
	file operator =(file other);


};
#include"FILE.hxx"