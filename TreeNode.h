#pragma once
#include "Catalog.h"
#include "FILE.h"
#include <vector>
#include <string>
using namespace std;
class TreeNode
{
public:
	Catalog info; // хранить всю информацию о текущем елементе и испольховать его адрес в качестве ссылки на этот элемент
	vector<file>file_children;
	vector<TreeNode>catalog_children;
	void create_file_children();
	void create_catalog_children();
	//void checkout_file_child(string name);
	//void checkout_catalog_child(string name);
	void print_catalog_child_names();
	void print_file_child_names();

	TreeNode();
	~TreeNode();
};
#include "TreeNode.hxx"
