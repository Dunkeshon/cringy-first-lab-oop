#pragma once
#include "System_object.h"
//#include "FILE.h"
#include "mylist.h"
#include <vector>
using namespace std;
class Catalog:public System_object
{
private:
	//vector<file*> children_files;
	//vector<Catalog*> children_catalogs;
	Catalog *parent;
public:
	Catalog();
	~Catalog();
	void create_child_file();
	void set_info(Catalog *father);
};

#include "Catalog.hxx"