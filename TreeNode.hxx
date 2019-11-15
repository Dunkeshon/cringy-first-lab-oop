/**
	*file
	*brief hxx file containing implementations of TreeNode.h
*/

#include "TreeNode.h"
#pragma once

TreeNode::TreeNode()
{
	parent = nullptr;
	info=Catalog();
}

 TreeNode::~TreeNode()
{
}
 /**
	 *brief Creates file inside current catalog, pushes it in vector of file_children
 */
 void TreeNode::create_file_children()
{
	 file new_node;
	 new_node.set_info(&info);
	 file_children.push_back(new_node);
	 cout << "file "<<new_node.Get_name() <<" has been created inside catalog " << info.Get_name()<<endl;
}
/**
	*brief Creates catalog inside current catalog, pushes it in vector of catalog_children
	*details Creates TreeNode , that performs as catalog and pushes it in vector of catalog_children
*/
 void TreeNode::create_catalog_children()
 {
	 TreeNode new_node;//	create new tree node
	 new_node.info.set_info(&info);//	create catalog
	 new_node.parent = this;
	 catalog_children.push_back(new_node);//	push to vector
	 cout << "catalog "<< new_node.info.Get_name() <<" has been created inside catalog " << info.Get_name() << endl;
 }
/**
	*brief Search file in vector of children files by it's name
	@param [in] file_name . Name of file, that we want to find
	@return pointer to file with the name that we put in function. if there is no file with such name - return nullptr
*/
file * TreeNode::search_child_file_by_name(string file_name)
{
	for (std::vector<file>::iterator it = file_children.begin(); it != file_children.end(); ++it) {
		if (it._Ptr->Get_name() == file_name)
		{
			return it._Ptr;
		}
	}
	return nullptr; //there is no such file with this name
	
}
/**
	*brief Search catalog in vector of children catalogs by it's name
	@param [in] catalog_name . Name of catalog, that we want to find
	@return pointer to TreeNode with the name that we put in function. if there is no catalog with such name - return nullptr
*/
TreeNode * TreeNode::search_child_catalog_by_name(string catalog_name)
{
	 for (std::vector<TreeNode>::iterator it = catalog_children.begin(); it != catalog_children.end(); ++it) {
		 if (it._Ptr->info.Get_name() == catalog_name)
		 {
			 return it._Ptr;
		 }
	 }
	 return nullptr;// there is no such catalog with this name
}
/**
	*brief Print all names of files that are located in this catalog in console
*/
void TreeNode::print_catalog_child_names()
{
	for(std::vector<TreeNode>::iterator it = catalog_children.begin(); it != catalog_children.end(); ++it)
	{
		cout << it._Ptr->info.Get_name() << endl;
	}
}
/**
	*brief Print all names of catalogs that are located in this catalog in console
*/
  void TreeNode::print_file_child_names()
  {
	  for(vector<file>::iterator it = file_children.begin();it!=file_children.end();++it)
	  {
		  cout << it._Ptr->Get_name() << endl;
	  }
  }
