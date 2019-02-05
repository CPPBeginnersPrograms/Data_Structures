/*
 * Hash.h
 *
 *  Created on: Oct 15, 2018
 *      Author: raswantkoushikpeesapati
 */

#ifndef SRC_HASH_H_
#define SRC_HASH_H_

#include <iostream>
#include <string>

using namespace std;

class Hash {
private:
//	int tableSize ;
	static const int tableSize = 10;// this allows us to define the size of table inside of the class definition.

	//core of the hash table
	struct item
	{
		string name;
		string drink;
		item* next;
	};

	item* hashTable[tableSize];	//to create a table

public:
	Hash();
	virtual ~Hash();
	int hash(string key);
	void AddItem(string name, string drink);
	int numberOfItemsInIndex(int index);
	void printTable();
	void printItemsInIndex(int index);
};

#endif /* SRC_HASH_H_ */
