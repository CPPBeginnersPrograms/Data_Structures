/*
 * List.h
 *
 *  Created on: Mar 20, 2019
 *      Author: raswantkoushikpeesapati
 */

#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <cstdlib>

class List {
private:
	typedef struct node
	{
		int data;
		node* next;
	}* nodePtr;

	nodePtr curr;
	nodePtr temp;
	nodePtr head;

public:
	List();
	void addNode(int addData);
	void delNode(int delData);
	void searchList(nodePtr p,int searchVal);
	void printList();
	virtual ~List();
};

#endif /* LIST_H_ */
