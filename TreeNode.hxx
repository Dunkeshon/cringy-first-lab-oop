#include "TreeNode.h"
#pragma once



TreeNode::TreeNode()
{
}


 TreeNode::~TreeNode()
{
}
 
 
 void TreeNode::create_file_children()
{
	 file *new_node = new file;
	 new_node->set_info(&info);
	 file_children.push_back(new_node);//положить в вектор
	 
}

 void TreeNode::create_catalog_children()
 {
	 TreeNode * new_node = new TreeNode;//create new tree node
	 new_node->info.set_common_info(&info);// create catalog
	 catalog_children.push_back(new_node);// push to vector
 }

  void TreeNode::print_catalog_child_names()
 {
	  for (int i = 0; i != catalog_children.size(); i++) {//ask
		  cout << catalog_children[i]->info.Get_name << endl;
	  }
 }

  void TreeNode::print_file_child_names()
  {
	  for (int i = 0; i != file_children.size(); i++) {//ask
		  cout << file_children[i]->Get_name << endl;
	  }
  }
