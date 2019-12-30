#pragma once
#ifndef _TREENODE_H
#define _TREENODE_H

class TreeNode {
private:
	double data;
	TreeNode *lchild;
	TreeNode *rchild;

	friend class BinaryTree;	//BinaryTree can access the data of node directly
public:
	TreeNode();
	TreeNode(double new_data);
};

#endif // !_TREENODE_H