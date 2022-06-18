#pragma once
#include <vector>
#include "CGAIndividual.h"
#include "CMax3SatProblem.h"
#include <ctime>
using namespace std;
class CGAOptimizer
{
public:
	~CGAOptimizer();
	CGAOptimizer(int population, double crossingProb, double mutationProb );
	void initialize(string pathName);
	void runIteration();
	void bestResult();


private:
	int popAmount;
	double crossProb;
	double mutProb;
	CMax3SatProblem* SATproblem;
	vector<CGAIndividual*> population;
	CGAIndividual* findParent();





};

