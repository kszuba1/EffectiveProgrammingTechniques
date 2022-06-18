#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Clause.h"
using namespace std;

#define  NEGATIVE_ZERO 9999

class CMax3SatProblem
{
public:
	~CMax3SatProblem();
	void load(string pathName);
	int compute(vector<bool> solutions);
	int getValQuantity() { return valQuantity; };
	vector<Clause*> getClausesVec() { return clausesVec; };

private:
	vector<Clause*> clausesVec;
	int valQuantity;
};

