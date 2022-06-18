#pragma once
#include <vector>t
#include "CMax3SatProblem.h";
using namespace std;
class CGAIndividual
{
public:
	CGAIndividual() {};
	//~CGAIndividual();
	CGAIndividual(vector<bool> genVec);
	CGAIndividual(const CGAIndividual& other);
	void crossover(CGAIndividual* child1, CGAIndividual* child2, CGAIndividual* parent2);
	void mutation(double mutProb);
	int fitness(CMax3SatProblem& SAT3);
	vector<bool> getGen() { return genotype; };
	void optimizeClause(CMax3SatProblem& problem);



private:
	vector<bool> genotype;

};

