/*
 * main.cpp
 *
 *  Created on: Jan 9, 2019
 *      Author: raswantkoushikpeesapati
 */

#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;

int main()
{
	int input = 0;
	int tree[19] = {50, 76, 21, 4, 32, 54, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80, 8, 7, 1};
	BST newTree;

	cout << "Printing the tree in order\n Before adding. "<<endl;
	newTree.PrintInOrder();

	for(int i = 0; i < 19; i++)
	{
		newTree.AddLeaf(tree[i]);
	}

	cout << "Printing the tree in order\n After adding. "<<endl;
	newTree.PrintInOrder();

	cout<<endl;

//	newTree.PrintChild(newTree.ReturnRootKey());

//	for(int i =0; i < 19; i++)
//	{
//		newTree.PrintChild(tree[i]);
//		cout<<endl;
//	}

	cout<<endl;
//
//	cout<<"The Smallest number in the Tree is " << newTree.FindSmallest()<<endl;
//	cout<<"The Largest number in the Tree is " << newTree.FindLargest()<<endl;

	cout<< "Enter the Key value to delete. Press -1 to exit "<<endl;
	while(input != -1)
	{
		cout << "Delete Node : ";
		cin >>input;
		{
			if(input != -1)
			{
				cout<<endl;
				newTree.RemoveNode(input);
				newTree.PrintInOrder();
				cout<<endl;
			}
		}
	}

	return 0;
}


