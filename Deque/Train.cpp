/*
 * Train.cpp
 *
 *  Created on: Mar 21, 2019
 *      Author: raswantkoushikpeesapati
 */

#include "Train.h"

Train::Train() {
	// TODO Auto-generated constructor stub

}

Train::~Train() {
	// TODO Auto-generated destructor stub
}

void Train::attachWagonFromLeft(int wagonId)
{
	train.push_front(wagonId);
}
void Train::attachWagonFromRight(int wagonId)
{
	train.push_back(wagonId);
}

int Train::detachWagonFromLeft()
{
	int result = train.front();
	train.pop_front();
	return result;
}

int Train::DetachWagonFromRight()
{
	int result = train.back();
	train.pop_back();
	return result;
}
