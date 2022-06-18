#include "CGAIndividual.h"
#include <ctime>

CGAIndividual::CGAIndividual(vector<bool> genVec) {
	genotype = genVec;

}
/*CGAIndividual::~CGAIndividual() {
	genotype.clear();
}
*/
CGAIndividual::CGAIndividual(const CGAIndividual& other) {
	if (genotype.size() < 0) genotype.clear();

	vector<bool> tempGen;
	for (int i = 0; i < other.genotype.size();i++) {
		tempGen.push_back(other.genotype[i]);
	}
	genotype = tempGen;
}
void CGAIndividual::crossover(CGAIndividual* child1, CGAIndividual* child2, CGAIndividual* parent2) {
	
	srand(time(NULL));
	for (int i = 0;i < genotype.size(); i++) {
		if (rand() % 2 == 0) {
			child1->genotype.push_back(genotype[i]);
			child2->genotype.push_back(parent2->genotype[i]);
		}
		else {
			child1->genotype.push_back(parent2->genotype[i]);
			child2->genotype.push_back(genotype[i]);
		}
	}

}
void CGAIndividual::mutation(double mutProb) {
	int prob = mutProb * 100;
	for (int i = 0; i < genotype.size(); i++) {
		if (rand() % 100 < prob) {
			genotype[i] = !genotype[i];
		}
	}
}
int CGAIndividual::fitness(CMax3SatProblem& problem) {
	return problem.compute(genotype);
}

//modyfikacja
void CGAIndividual::optimizeClause(CMax3SatProblem& SATproblem) {
	srand(time(NULL));

	int rIndex = rand() % SATproblem.getClausesVec().size();
	int first = SATproblem.getClausesVec().at(rIndex)->getFirst();
	int second = SATproblem.getClausesVec().at(rIndex)->getSecond();
	int third = SATproblem.getClausesVec().at(rIndex)->getThird();

    
	//1
	if (first == NEGATIVE_ZERO && !genotype[0]) {
		return;

	}
	if (first >= 0 && first != NEGATIVE_ZERO && genotype[first]) {
		return;
	}
	if (first < 0 && !genotype[abs(first)]) {
		return;
	}
	//2
	if (second == NEGATIVE_ZERO && !genotype[0]) {
		return;

	}
	if (second >= 0 && second != NEGATIVE_ZERO && genotype[second]) {
		return;
	}
	if (second < 0 && !genotype[abs(second)]) {
		return;
	}
	//3
	if (third == NEGATIVE_ZERO && !genotype[0]) {
		return;

	}
	if (third >= 0 && first != NEGATIVE_ZERO && genotype[third]) {
		return;
	}
	if (third < 0 && !genotype[abs(third)]) {
		return;
	}
	//zmien 1 
	if (first == NEGATIVE_ZERO) {
		genotype[0] = !genotype[0];
	}
	else {
		genotype[abs(first)] = !genotype[abs(first)];
	}
	//zmien 2 
	if (second == NEGATIVE_ZERO) {
		genotype[0] = !genotype[0];
	}
	else {
		genotype[abs(second)] = !genotype[abs(second)];
	}

	//zmien 3
	if (third == NEGATIVE_ZERO) {
		genotype[0] = !genotype[0];
	}
	else {
		genotype[abs(third)] = !genotype[abs(third)];
	}


}