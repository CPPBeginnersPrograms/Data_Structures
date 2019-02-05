/*
 * BST.h
 *
 *  Created on: Jan 9, 2019
 *      Author: raswantkoushikpeesapati
 */

#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <cstdlib>

using namespace std;


class BST {
private:

	struct node
	{
		int key;
		node *left;
		node *right;
	};

	node* root;

	node* CreateLeaf(int key);
	void AddLeafPrivate(int key, node* ptr);
	void PrintInOrderPrivate(node* ptr);

	//helper function
	node* ReturnNode(int key);
	node* ReturnNodePrivate(int key, node* ptr);
	int FindSmallestPrivate(node* ptr);
	int FindLargestPrivate(node* ptr);
	void RemoveNodePrivate(int key, node* parent);
	void RemoveRootMatch();
	void RemoveMatch(node* parent, node* match, bool left);
	void RemoveSubTree(node* ptr);
public:
	BST();
	virtual ~BST();
	void AddLeaf(int key);
	void PrintInOrder();
	int ReturnRootKey();
	void PrintChild(int key);
	int FindSmallest();
	int FindLargest();
	void RemoveNode(int key);
};

#endif /* BST_H_ */
