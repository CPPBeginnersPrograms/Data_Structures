/*
 * main.cpp
 *
 *  Created on: Oct 15, 2018
 *      Author: raswantkoushikpeesapati
 */


#include <iostream>
#include <string>

#include "Hash.h"

using namespace std;

int main()
{
//	int index;
//	Hash hashObj;
//	index = hashObj.hash("Koushik");
//
//	cout<<" Index = "<<index << endl;

	Hash hashObj;
	hashObj.AddItem("koushik", "pepsi");
	hashObj.AddItem("koushika", "diet pepsi");
	hashObj.AddItem("Anusha", "coke");
	hashObj.AddItem("koushik", "diet coke");
	hashObj.AddItem("Kittu", "fanta");
	hashObj.printTable();
	hashObj.printItemsInIndex(0);
	return 0;
}

