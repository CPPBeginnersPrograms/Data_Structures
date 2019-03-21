/*
 * main.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: raswantkoushikpeesapati
 */
#include <iostream>
#include <cstdlib>
#include <memory>
#include "List.h"

using namespace std;

int main(){
//	List *l = new List;
	int num = 0;
	std::unique_ptr<List> l = std::make_unique<List>();
//add into list
	while(true)
	{
		cout<<"Enter Number: "<<endl;
		cin >> num;
		if(num != -1)
		{
		l->addNode(num);
		}
		else
		{
			break;
		}
	}
	l->printList();

	//delete from list
	while(true)
	{
		cout << "Enter a num to delete "<<endl;
		cin >> num;
		if(num == -1)
		{
			break;
		}
		else
		{
			l->delNode(num);
			cout<<endl;
			l->printList();
		}
	}
//searchValue code
//	while(true)
//	{
//		cout<<"Enter search val "<<endl;
//		cin >> num;
//		if(num != -1)
//		{
//			l->searchList(,num);
//		}
//		else
//		{
//			break;
//		}
//	}


	return 0;
}



