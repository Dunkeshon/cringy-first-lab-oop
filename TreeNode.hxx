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
  
 void TreeNode::create_file_children()
{
	 file new_node;
	 new_node.set_info(&info);//	передаем ссылку на отца
	 file_children.push_back(new_node);//	положить в вектор
	 cout << "file "<<new_node.Get_name() <<" has been created inside catalog " << info.Get_name()<<endl;
}

 void TreeNode::create_catalog_children()
 {
	 TreeNode new_node;//	create new tree node
	 new_node.info.set_info(&info);//	create catalog
	 new_node.parent = this;
	 catalog_children.push_back(new_node);//	push to vector
	 cout << "catalog "<< new_node.info.Get_name() <<" has been created inside catalog " << info.Get_name() << endl;
 }

file * TreeNode::search_child_file_by_name(string file_name)
{
	for (std::vector<file>::iterator it = file_children.begin(); it != file_children.end(); ++it) {
		if (it._Ptr->Get_name() == file_name)
		{
			return it._Ptr;
		}
	}
	return nullptr;//there is no such file with this name
	
}

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

void TreeNode::print_catalog_child_names()
{
	for(std::vector<TreeNode>::iterator it = catalog_children.begin(); it != catalog_children.end(); ++it)
	{
		cout << it._Ptr->info.Get_name() << endl;
	}
}

  void TreeNode::print_file_child_names()
  {
	  for(vector<file>::iterator it = file_children.begin();it!=file_children.end();++it)
	  {
		  cout << it._Ptr->Get_name() << endl;
	  }
  }
