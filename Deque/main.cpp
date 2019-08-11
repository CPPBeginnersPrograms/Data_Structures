/*
 * main.cpp
 *
 *  Created on: Mar 21, 2019
 *      Author: raswantkoushikpeesapati
 */

#include <iostream>
#include <deque>
#include "Train.h"

using namespace std;

int main()
{
	Train train;
	train.attachWagonFromLeft(7);
	train.attachWagonFromRight(13);
	cout<<train.detachWagonFromLeft()<<endl;
	cout<<train.DetachWagonFromRight()<<endl;
}




