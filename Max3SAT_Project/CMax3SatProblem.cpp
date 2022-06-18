#include "CMax3SatProblem.h"
#include <fstream>
#include <sstream>
using namespace std;
CMax3SatProblem::~CMax3SatProblem() {
	for (int i = 0;i < clausesVec.size();i++) {
		if (clausesVec[i] != NULL) {
			delete clausesVec[i];
		}
	}
	//clausesVec.clear();
}
void CMax3SatProblem::load(string pathName) {
	ifstream input_file;
	input_file.open(pathName);
	if (!input_file) {
		cout << "blad podczas otwierania pliku" << endl;
		return;		
	}
	int max = 0; 
	int first = 0;
	int second = 0;
	int third = 0;
	string line;
	string str;
	vector<std::string> strVec;
	while (!input_file.eof()) {
		getline(input_file, line);
		stringstream streamData(line);
		while (getline(streamData, str, ' ')) {
			strVec.push_back(str);
		}
		if (strVec[1] == "-0") first = NEGATIVE_ZERO;
		else first = stoi(strVec[1]);
		if (strVec[3] == "-0") second = NEGATIVE_ZERO;
		else second = stoi(strVec[3]);
		if (strVec[5] == "-0") third = NEGATIVE_ZERO;
		else third = stoi(strVec[5]);
		if (abs(first) > max && first!= NEGATIVE_ZERO) max = abs(first);
		if (abs(second) > max && second!= NEGATIVE_ZERO) max = abs(second);
		if (abs(third) > max && third!= NEGATIVE_ZERO) max = abs(third);
		Clause* newClause = new Clause(first, second, third);
		clausesVec.push_back(newClause);
		strVec.clear();
	}
	valQuantity = max + 1;
	strVec.clear();
	input_file.close();

	
}
int  CMax3SatProblem::compute(vector<bool> solutions) {
	int trueClauses = 0;
	int first = 0;
	int second = 0;
	int third = 0;
	for (int i = 0; i < clausesVec.size(); i++) {
		first = clausesVec[i]->getFirst();
		if (first == NEGATIVE_ZERO && !solutions[0]) {
			trueClauses++;
			continue;
		}
		 if (first >= 0 && first != NEGATIVE_ZERO && solutions[first]) {
			trueClauses++;
			continue;
		}
		
		 if (first < 0 && !solutions[abs(first)]) {
			 trueClauses++;
			 continue;
		 }
			
		

		second = clausesVec[i]->getSecond();
		if (second == NEGATIVE_ZERO && !solutions[0]) {
			trueClauses++;
			continue;
		}
		if (second >= 0 && second != NEGATIVE_ZERO && solutions[second]) {
			trueClauses++;
			continue;
		}
		
		if (second < 0 && !solutions[abs(second)]) {
			trueClauses++;
			continue;
		}
		


		third = clausesVec[i]->getThird();
		if (third == NEGATIVE_ZERO && !solutions[0]) {
			trueClauses++;
			continue;
		}
		 if (third >= 0 && third != NEGATIVE_ZERO && solutions[third]) {
			trueClauses++;
			continue;
		}
		
		if (third < 0 && !solutions[abs(third)]) {
			trueClauses++;
			continue;
		}
	}
		


	return trueClauses;
}

    


	
	



	


