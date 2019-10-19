#pragma once
#include "pch.h"
#include "Catalog.h"
Catalog::Catalog()
{
	parent = nullptr;
	_name = string();
	_size = 0;
	_time = Taime();
	_changed_time = Taime();
}


Catalog::~Catalog()
{
}

void Catalog::create_child_file()
{
	
	//file *new_file = new file;
	//new_file->set_info(this);
	

}

inline void Catalog::set_info(Catalog * father)// if this is first catalog-> set nullptr
{
	set_common_info();// basic class function 
	parent = father;
}
