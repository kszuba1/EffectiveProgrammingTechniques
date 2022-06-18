#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T> class CVector {
public:
	CVector() {};
	~CVector();
	CVector(const CVector<T> &otherVec);
	CVector(CVector<T> &&otherVec);
	void add(T val);
	int getSize() { return vector.size(); }
	void vPrint();


private:
	vector<T*> vector;
};

template <typename T>
CVector<T>::~CVector() {
	for (int ii = 0; ii < vector.size(); ii++) {
		delete vector[ii];
	}
}


template <typename T>
CVector<T>::CVector(const CVector<T> &otherVector) {
	vector.insert(vector.begin(),otherVector.vector.begin(), otherVector.vector.end());
}

template <typename T>
CVector<T>::CVector(CVector<T> &&otherVector) {
	vector = otherVector.vector;
	otherVector.vector.clear();
}



template <typename T>
void CVector<T>::add(T val) {
	T* newVal = new T(val);
	vector.push_back(newVal);
}
template <typename T>
void CVector<T>::vPrint() {
	for (int i = 0; i < vector.size(); i++) {
		std::cout << *vector[i] << ' ';
	}
	std::cout << endl;
}





