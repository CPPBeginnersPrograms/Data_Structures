/*
 * Hash.cpp
 *
 *  Created on: Oct 15, 2018
 *      Author: raswantkoushikpeesapati
 */

#include "Hash.h"

Hash::Hash() {
	// TODO Auto-generated constructor stub
	//defining hashtable and running through a for loop to make every element in tablesize to create a new item and setting the name and drink to empty.
	for(int i = 0; i < tableSize; i++)
	{
		hashTable[i] = new item;
		hashTable[i]->name = "empty";
		hashTable[i]->drink = "empty";
		hashTable[i]->next = NULL;
	}
}

Hash::~Hash() {
	// TODO Auto-generated destructor stub
}

void Hash::AddItem(string name, string drink)
{
//	cout<<"Enter the name"<<endl;
//	cin>>name;
//	cout<<"Enter the drink"<<endl;
//	cin>>drink;

	int index  = hash(name);

	if(hashTable[index]->name == "empty")
	{
		hashTable[index]->name = name;
		hashTable[index]->drink = drink;
	}
	else
	{
		item* ptr = hashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next  = n;
	}
}

int Hash::numberOfItemsInIndex(int index)
{
	int count = 0;

	if(hashTable[index]->name == "empty")
	{
		return count;
	}
	else
	{
		count++;
		item* ptr = hashTable[index];
		while(ptr->next != NULL)
		{
			count++;
			ptr = ptr->next;
		}
		return count;
	}
}

void Hash::printTable()
{
	int number;
	for(int i =0; i < tableSize; i++)
	{
		number = numberOfItemsInIndex(i);
		cout<<" ------------------------\n";
		cout<<" index = "<<i<<endl;
		cout<<" name = "<<hashTable[i]->name<<endl;
		cout<<" drink = "<<hashTable[i]->drink<<endl;
		cout<<" no of items = "<<number<<endl;
		cout<<" ------------------------\n";
	}
}

void Hash::printItemsInIndex(int index)
{
	item* ptr = hashTable[index];

	if(ptr->name == "empty")
	{
		cout<<" index = "<<index << " is empty ";
	}
	else
	{
		cout<< " index "<< index << " is containing the following items"<<endl;
		while(ptr != NULL)
		{
			cout<<" ------------------------\n";
			cout<<" name = "<<ptr->name<<endl;
			cout<<" drink = "<<ptr->drink<<endl;
			cout<<" ------------------------\n";
			ptr = ptr->next;
		}
	}
}

int Hash::hash(string key)
{
	int hash = 0;
	int index;
//	index = key.length();

	for(int i = 0; i < key.length(); i++)
	{
		hash = hash + (int)key[i];
		//cout<< "value "<< hash<<endl;
	}
//	cout<< " The total value of the name : "<<hash<<endl;
//	cout<< " Key[0] = "<< (int)key[0]<<endl;
//	cout<< " Key[1] = "<< (int)key[1]<<endl;
//	cout<< " Key[2] = "<< (int)key[2]<<endl;
//	cout<< " Key[3] = "<< (int)key[3]<<endl;
//	cout<< " Key[4] = "<< (int)key[4]<<endl;
//	cout<< " Key[5] = "<< (int)key[5]<<endl;
//	cout<< " Key[6] = "<< (int)key[6]<<endl;

	index = hash % tableSize; // index is now storing the remainder as a key, to put that specific name into the array.

	return index;
}
