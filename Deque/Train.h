/*
 * Train.h
 *
 *  Created on: Mar 21, 2019
 *      Author: raswantkoushikpeesapati
 */

#ifndef TRAIN_H_
#define TRAIN_H_
#include <iostream>
#include <deque>

using namespace std;

class Train {
public:
	Train();
	void attachWagonFromLeft(int wagonId);
	void attachWagonFromRight(int wagonId);
	int detachWagonFromLeft();
	int DetachWagonFromRight();

	virtual ~Train();
private:
	deque<int>train;
};

#endif /* TRAIN_H_ */
