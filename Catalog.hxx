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
	file *new_file = new file;
	new_file->set_info(this);


}
