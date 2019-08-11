/*
 * List.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: raswantkoushikpeesapati
 */

#include "List.h"

List::List() {

	head = NULL;
	curr = NULL;
	temp = NULL;
}

List::~List() {

	std::cout << "Destroyed "<<std::endl;
}

void List::addNode(int addData)
{
//	int addData ;

//	std::cout<<"Enter the number you want to add or press -1 to exit."<<std::endl;
//	while(std::cin>>addData)
//	{
//		std::cout<<"Enter the number you want to add or press -1 to exit."<<std::endl;
//		if(addData == -1)
//		{
//			break;
//		}
//		else
//		{
			nodePtr n = new node;
			n->next = NULL;
			n->data = addData;

			if(head != NULL)
			{

				curr = head;
				while(curr->next != NULL)
				{
					curr = curr->next;
				}
				curr->next = n;
			}
			else
			{
				head = n;
			}
//		}
//	}

//	std::cout<<"Exited from Entering"<<std::endl;
}

void List::delNode(int delData)
{
	nodePtr delPtr = NULL;
	curr = head;
	temp = head;

	while(curr != NULL && curr->data != delData)
	{
		temp = curr;
		curr = curr->next;
	}
	if(curr == NULL)
	{
		std::cout << "the List is Empty "<<std::endl;
		delete delPtr;
	}
	else if(head->data == delData)
	{
		delPtr = head;
		head = curr->next;
		curr = head;
		temp = head;
		delete delPtr;
	}
	else
	{
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		delete delPtr;
	}


}

void List::searchList(nodePtr p,int searchVal)
{
	if(p == NULL)
	{
		std::cout<<searchVal << " was not found in the List"<<std::endl;
	}
	else if(p->data == searchVal)
	{
		std::cout << searchVal << " is found in the List "<<std::endl;
	}
	else
	{
		searchList(p->next,searchVal);
	}
}

void List::printList()
{
	std::cout<<"The List Contains "<<std::endl;
	curr = head;
	while(curr != NULL)
	{
		std::cout<< curr->data<<std::endl;
		curr = curr->next;
	}
}
