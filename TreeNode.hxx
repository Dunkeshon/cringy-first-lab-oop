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
}
