#pragma once
#ifndef _BINARYTREE_H
#define _BINARYTREE_H
#include "TreeNode.h"

class BinaryTree {
private:
	TreeNode *root;
	void InorderDisplay(TreeNode* current) const;											//display by inorder travesal
	void PostorderDelete(TreeNode* current);												//delete node by postorder travesal
	void inorderFind(TreeNode* current, double val, int &index, bool &already_find) const;	//find the least of value in tree
	void inorderSearch(TreeNode* current, double val, bool &already_find) const;			//search the value if exists in tree by inorder travesal
	double succesor(TreeNode* current, TreeNode* ancestor);									//return the value after succesor
public:
	BinaryTree();
	void insert(double new_data);															//insert new data
	int find(double find_data) const;														//find least of value
	void delete_key(double delete_data);													//delete data
	void show() const;																		//show the tree
	void clear();																			//clear the tree
	bool IsEmpty() const;																	//check if the tree is empty
	bool IsExist(double find_data) const;													//check if the data has existed
};

#endif // !_BINARYTREE_H