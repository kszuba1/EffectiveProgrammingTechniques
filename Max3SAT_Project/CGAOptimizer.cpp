#include "CGAOptimizer.h"

CGAOptimizer::~CGAOptimizer() {
	for (int i = 0;i < population.size();i++) {
		if (population[i] != NULL) {
			delete population[i];
		}
	}
	if (SATproblem != NULL) delete SATproblem;
	//population.clear();

}

CGAOptimizer::CGAOptimizer(int populationAmount, double crossingProb, double mutationProb) {
	popAmount = populationAmount;
	crossProb = crossingProb;
	mutProb = mutationProb;
	SATproblem = NULL;
	
}
CGAIndividual* CGAOptimizer::findParent() {
	int member1_index = rand() % popAmount;
	int member2_index = rand() % popAmount;
	while (member1_index == member2_index) {
		member2_index = rand() % popAmount;
	}
	CGAIndividual* member1 = population.at(member1_index);
	CGAIndividual* member2 = population.at(member2_index);
	if (member1->fitness(*SATproblem) > member2->fitness(*SATproblem)) {
		return member1;
	}
	else return member2;
}
void CGAOptimizer::initialize(string pathName) {
	srand(time(NULL));
	SATproblem = new CMax3SatProblem();
	SATproblem->load(pathName);
	int size = SATproblem->getValQuantity();
	for (int i = 0; i < popAmount; i++) {
		vector<bool> genotype;
		for (int j = 0; j < size; j++) {
			genotype.push_back(rand() % 2);
		}
		population.push_back(new CGAIndividual(genotype));
	}
	

}
void CGAOptimizer::runIteration() {
	srand(time(NULL));

	vector<CGAIndividual*> new_population;
	CGAIndividual* child1 = NULL;
	CGAIndividual* child2 = NULL;
	CGAIndividual* parent1 = NULL;
	CGAIndividual* parent2 = NULL;

	
	while (new_population.size() < population.size()) {
		
		
		parent1 = findParent();
		parent2 = findParent();
		
		while (parent1 == parent2) {
			parent2 = findParent();
		}
		
		if (rand() % 100 < (crossProb * 100)) {

			child1 = new CGAIndividual();
			child2 = new CGAIndividual();
	
			parent1->crossover(child1, child2, parent2);;
			

			child1->mutation(mutProb);
			child2->mutation(mutProb);

			child1->optimizeClause(*SATproblem);
			child2->optimizeClause(*SATproblem);


		}
		else {
			
			child1 = new CGAIndividual(*parent1);
			child2 = new CGAIndividual(*parent2);
			//child1->optimizeClause(*SATproblem);
			//child2->optimizeClause(*SATproblem);
			

		}

		new_population.push_back(child1);
		new_population.push_back(child2);
		
	}
	
	population.clear();
	population = new_population;


}

void CGAOptimizer::bestResult() {

	int bestFitness = population[0]->fitness(*SATproblem);
	int x = bestFitness;
	for (int i = 1; i < popAmount; i++) {
		x = population[i]->fitness(*SATproblem);
		if (x > bestFitness) {
			bestFitness = x;
		}

	}

	cout << "Best result is: "<<bestFitness<<endl;
}



