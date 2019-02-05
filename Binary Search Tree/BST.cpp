/*
 * BST.cpp
 *
 *  Created on: Jan 9, 2019
 *      Author: raswantkoushikpeesapati
 */

#include "BST.h"

BST::BST(){
	// TODO Auto-generated constructor stub
	root = NULL;

}

BST::~BST() {
	// TODO Auto-generated destructor stub
	RemoveSubTree(root);
}

BST::node*::BST::CreateLeaf(int key)
{
	node* n = new node;
	n->key = key;
	n->left = NULL;
	n->right = NULL;

	return n;
}

void BST::AddLeaf(int key)
{
	AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node* ptr)
{
	if(root == NULL)
	{
		root = CreateLeaf(key);
	}
	else if(key < ptr->key)
	{
		if(ptr->left != NULL)
		{
			AddLeafPrivate(key, ptr->left);
		}
		else
		{
			ptr->left = CreateLeaf(key);
		}
	}
	else if(key > ptr->key)
	{
		if(ptr->right != NULL)
		{
			AddLeafPrivate(key, ptr->right);
		}
		else
		{
			ptr->right = CreateLeaf(key);
		}
	}
	else
	{
		cout << "The Key "<< key << " is alrea been added in the tree.\n"<<endl;
	}
}

void BST::PrintInOrder()
{
	PrintInOrderPrivate(root);
}
void BST::PrintInOrderPrivate(node *ptr)
{
	if(root != NULL)
	{
		if(ptr->left != NULL)
		{
			PrintInOrderPrivate(ptr->left);
		}

		cout<<ptr->key<< " ";

		if(ptr->right != NULL)
		{
			PrintInOrderPrivate(ptr->right);
		}
	}
	else
	{
		cout <<" The Tree is Empty. "<<endl;
	}
}

BST::node*::BST::ReturnNode(int key)
{
	return ReturnNodePrivate(key, root);
}

BST::node*::BST::ReturnNodePrivate(int key, node* ptr)
{
	if(root != NULL)
	{
		if(ptr->key == key)
		{
			return ptr;
		}
		else if(key < ptr->key)
		{
			return ReturnNodePrivate(key, ptr->left);
		}
		else
		{
			return ReturnNodePrivate(key, ptr->right);
		}
	}
	else
	{
		return NULL;
	}
}

int BST::ReturnRootKey()
{
	if(root != NULL)
	{
		return root->key;
	}
	else
		return -1000;
}

void BST::PrintChild(int key)
{
	node* ptr = ReturnNode(key);

	if(ptr != NULL)
	{
		cout << "Parent Node = "<< ptr->key <<endl;

		//conditional statements instead of if/else

		ptr->left == NULL ?
		cout<< "Left Child = NULL\n " :
		cout<< "Left Child = "<<ptr->left->key<<endl;

		ptr->right == NULL ?
		cout<< "Right Child = NULL\n " :
		cout<< "Right Child = "<<ptr->right->key<<endl;

	}
	else
	{
		cout << "The Key "<< key << " is not in the tree."<<endl;
	}
}

int BST::FindSmallest()
{
	return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* ptr)
{
	if(root == NULL)
	{
		cout<<"The tree is Empty."<<endl;
		return -1000;
	}
	else
	{
		if(ptr->left != NULL)
		{
			return FindSmallestPrivate(ptr->left);
		}
		else
		{
			return ptr->key;
		}
	}
}

int BST::FindLargest()
{
	return FindLargestPrivate(root);
}

int BST::FindLargestPrivate(node* ptr)
{
	if(root == NULL)
	{
		cout<<"The tree is Empty."<<endl;
		return -1000;
	}
	else
	{
		if(ptr->right != NULL)
		{
			return FindLargestPrivate(ptr->right);
		}
		else
		{
			return ptr->key;
		}
	}
}

void BST::RemoveRootMatch()
{
	if(root != NULL)
	{
		node* delPtr = root;
		int rootKey = root->key;
		int SmallestInRightSubTree;

		//case 0 - 0 children
		if(root->left == NULL && root->right == NULL)
		{
			root = NULL;
			delete delPtr;
		}
		//case 1 - 1 child
		else if(root->left == NULL && root->right != NULL)
		{
			root = root->right;
			delPtr->right = NULL;
			delete delPtr;
			cout<<"The root node with key "<<rootKey<< " was deleted "<< "\n and the new root is "<<root->key << endl;
		}
		else if(root->left != NULL && root->right == NULL)
		{
			root = root->left;
			delPtr->left = NULL;
			delete delPtr;
			cout<<"The root node with key "<<rootKey<< " was deleted "<< "\n and the new root is "<<root->key << endl;
		}
		//case 2 2 children
		else
		{
			SmallestInRightSubTree = FindSmallestPrivate(root->right);
			RemoveNodePrivate(SmallestInRightSubTree, root);
			root->key = SmallestInRightSubTree;
			cout<<"The root node with key "<<rootKey<< " was deleted "<< "\n and overwritten with "<<root->key << endl;
		}

	}
	else
	{
		cout <<"Cannot Remove Root. The tree is empty."<<endl;
	}
}

void BST::RemoveMatch(node* parent, node* match, bool left)
{
	if(root != NULL)
	{
		node* delPtr;
		int matchKey = match->key;
		int SmallestInRightSubTree;

		//case 0 0 children
		if(match->left == NULL && match->right == NULL)
		{
			delPtr = match;
			left == true ? parent->left = NULL : parent->right = NULL;
			delete delPtr;
			cout<<"The Node containing key "<< matchKey << " is deleted."<<endl;
		}
		//case 1 1 child
		else if(match->left == NULL && match->right != NULL)
		{
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
			delPtr = match;
			delete delPtr;
			cout<<"The Node containing key "<< matchKey << " is deleted."<<endl;
		}
		else if(match->left != NULL && match->right == NULL)
		{
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
			delPtr = match;
			delete delPtr;
			cout<<"The Node containing key "<< matchKey << " is deleted."<<endl;
		}

		//case 2 2 child
		else
		{
			SmallestInRightSubTree = FindSmallestPrivate(match->right);
			RemoveNodePrivate(SmallestInRightSubTree, match);
			match->key = SmallestInRightSubTree;
		}
	}
	else
	{
		cout << "Cannot Remove match. The tree is empty"<<endl;
	}
}

void BST::RemoveNode(int key)
{
	RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* parent)
{
	if(root != NULL)
	{
		if(root->key == key)
		{
			RemoveRootMatch();
		}
		else
		{
			if(key < parent->key && parent->left != NULL)
			{
				parent->left->key == key ?
				RemoveMatch(parent, parent->left, true):
				RemoveNodePrivate(key, parent->left);
			}
			else if(key > parent->key && parent->right != NULL)
			{
				parent->right->key == key ? RemoveMatch(parent, parent->right, false) : RemoveNodePrivate(key, parent->right);
			}
			else
			{
				cout << "The Key "<< key << " is not found in the Tree."<<endl;
			}
		}
	}
	else
	{
		cout << "The Tree is Empty. "<<endl;
	}
}

void BST :: RemoveSubTree(node *ptr)
{
	if(ptr != NULL)
	{
		if(ptr->left != NULL)
		{
			RemoveSubTree(ptr->left);
		}
		if(ptr->right != NULL)
		{
			RemoveSubTree(ptr->right);
		}
		cout<<"Deleting the node containing the key "<< ptr->key <<endl;
		delete ptr;
	}
}
