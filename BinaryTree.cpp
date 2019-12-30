#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree() : root(nullptr){}

void BinaryTree::insert(double new_data) {
	TreeNode *newNode = new TreeNode(new_data);

	if (IsEmpty()) {
		root = newNode;
	}
	else {
		TreeNode *current = root;

		while (true){
			if (new_data > current->data) {				//move right
				if (current->rchild == nullptr) {
					current->rchild = newNode;
					break;
				}
				else {
					current = current->rchild;
					continue;
				}
			}
			else if (new_data < current->data) {		//move left
				if (current->lchild == nullptr) {
					current->lchild = newNode;
					break;
				}
				else {
					current = current->lchild;
					continue;
				}
			}
			else if (new_data == current->data) {		//print error message
				std::cout << "There is a same data in the tree. Number:" << new_data << std::endl;
				delete newNode;
				return;
			}
		}
	}
}

void BinaryTree::delete_key(double delete_data) {
	if (IsEmpty()) {
		std::cout << "Tree is Empty!!!" << std::endl;
		return;
	}
	else {
		TreeNode *current = root;
		TreeNode *parent = root;

		while (true) {
			if (delete_data > current->data) {			//move right
				if (current->rchild == nullptr) {
					std::cout << "Number:" << delete_data << " doesn't exist!!!" << std::endl;
					return;
				}
				else {
					parent = current;
					current = current->rchild;
					continue;
				}
			}
			else if (delete_data < current->data) {		//move left
				if (current->lchild == nullptr) {
					std::cout << "Number:" << delete_data << " doesn't exist!!!" << std::endl;
					break;
				}
				else {
					parent = current;
					current = current->lchild;
					continue;
				}
			}
			else if (delete_data == current->data) {	//delete data
				if (current->rchild) {					//if the node has rchild, use succesor to chage the data 
					current->data = succesor(current->rchild, current);
					break;
				}
				else if (!current->rchild) {			/*let the node's parrent which was deleted connect with with this node's lchild*/
					if (current == root) {
						root = current->lchild;
					}
					else if (parent->lchild == current) {
						parent->lchild = current->lchild;
					}
					else if (parent->rchild == current) {
						parent->rchild = current->lchild;
					}
					delete current;
					break;
				}
			}
		}
	}

	std::cout << "Number:" << delete_data << " has been deleted!!!" << std::endl;
}

void BinaryTree::show() const{
	if (IsEmpty()) {
		std::cout << "Tree is empty!!!" << std::endl;
	}
	else {
		std::cout << "Inorder Travesal: ";
		InorderDisplay(root);
	}
	
}

void BinaryTree::InorderDisplay(TreeNode* current) const {
	if (current) {
		InorderDisplay(current->lchild);
		std::cout << current->data << " ";
		InorderDisplay(current->rchild);
	}
}

bool BinaryTree::IsEmpty() const{
	if (root == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

int BinaryTree::find(double find_data) const{
	TreeNode* current = root;
	int index = 0;
	bool already_find = false;

	if (current) {
		inorderFind(current, find_data, index, already_find);
		return index;
	}
    return 0;
}

void BinaryTree::inorderFind(TreeNode* current, double val,int &index, bool &already_find) const{
	if (current) {
		inorderFind(current->lchild, val, index, already_find);
		if (current->data == val) {
			already_find = true;
			index++;
			return;
		}
		if (!already_find) {
			index++;
		}
		inorderFind(current->rchild, val, index, already_find);
	}
}

void BinaryTree::clear() {
	if (!IsEmpty()) {
		std::cout << "Clear Tree" << std::endl;
		PostorderDelete(root);
		root = nullptr;
	}
}

void BinaryTree::PostorderDelete(TreeNode* current) {
	if (current) {
		PostorderDelete(current->lchild);
		PostorderDelete(current->rchild);
		delete current;
	}
}

bool BinaryTree::IsExist(double find_data) const{
	if (IsEmpty()) {
		return false;
	}
	else {
		bool already_find = false;
		inorderSearch(root, find_data, already_find);
		return already_find;
	}
}

void BinaryTree::inorderSearch(TreeNode* current, double val, bool &already_find) const {
	if (current) {
		inorderSearch(current->lchild, val, already_find);
		if (current->data == val) {
			already_find = true;
			return;
		}
		inorderSearch(current->rchild, val, already_find);
	}
}

double BinaryTree::succesor(TreeNode* current, TreeNode* first_parent) {
	double result;

	if (current->lchild) {
		TreeNode* parent = nullptr;

		while (current->lchild) {
			parent = current;
			current = current->lchild;
		}

		parent->lchild = current->rchild;
	}
	else {
		first_parent->rchild = current->rchild;
	}

	result = current->data;
	delete current;
	return result;
}
