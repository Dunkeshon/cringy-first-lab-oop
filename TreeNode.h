/**
*file
*brief Header file containing class TreeNode
*This file contains definition and implementation of node, where is stored class Catalog whith all his children elements , TreeNode
*/

#pragma once
#include "Catalog.h"
#include "FILE.h"
#include <vector>
#include <string>
using namespace std;


/**

*brief Node, where is stored catalog and all his children elements , TreeNode
*details An implementation of TreeNode. This is a class where we store catalog and his children in vectors : file_children, catalog_children
*/
class TreeNode
{
public:
	/**
	pointer to parent TreeNode with parent catalog inside
	*/
	TreeNode *parent;
	/**
	*stores Catalog
	*/
	Catalog info; 
	/**
	*vector with files , that are stored in this catalog
	*/
	vector<file>file_children;
	/**
	*vector with TreeNodes , that are stored in this TreeNodes
	*/
	vector<TreeNode>catalog_children;
	/**
	*brief Creates file inside current catalog, pushes it in vector of file_children
	*/
	void create_file_children();
	/**
	*brief Creates catalog inside current catalog, pushes it in vector of catalog_children
	*details Creates TreeNode , that performs as catalog and pushes it in vector of catalog_children
	*/
	void create_catalog_children();
	/**
	*brief Search file in vector of children files by it's name
	@param file_name . Name of file, that we want to find
	@return pointer to file with the name that we put in function. if there is no file with such name - return nullptr  
	*/
	file* search_child_file_by_name(string file_name);
	/**
	*brief Search catalog in vector of children catalogs by it's name
	@param catalog_name . Name of catalog, that we want to find
	@return pointer to TreeNode with the name that we put in function. if there is no catalog with such name - return nullptr
	*/
	TreeNode* search_child_catalog_by_name(string catalog_name);
	/**
	*brief Print all names of files that are located in this catalog in console
	*/
	void print_file_child_names();
	/**
	*brief Print all names of catalogs that are located in this catalog in console
	*/
	void print_catalog_child_names();
	

	TreeNode();
	~TreeNode();
};
#include "TreeNode.hxx"
