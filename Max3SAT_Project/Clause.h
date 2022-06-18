#pragma once
class Clause
{
public:
	Clause(int fst, int scnd, int trd);
	int getFirst() { return first; };
	int getSecond() { return second; };
	int getThird() { return third; };

private:
	int first;
	int second;
	int third;


};

