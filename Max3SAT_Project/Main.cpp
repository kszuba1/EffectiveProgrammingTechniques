#include <iostream>
#include <string>
#include "CGAOptimizer.h"
#include <fstream>
#include <sstream>
#include "CMax3SatProblem.h"
using namespace std;


int main() {
	
	CGAOptimizer otp(100,0.3,0.3);
	otp.initialize("50_44.txt");
	otp.runIteration();
	otp.bestResult();
	otp.runIteration();
	otp.bestResult();
	
	

	
}