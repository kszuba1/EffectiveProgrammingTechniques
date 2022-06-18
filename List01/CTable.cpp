#include "CTable.h"
#include <iostream>


const string CTable::DEFAULT_NAME = "table";
const int CTable::DEFAULT_LENGTH = 3;

CTable::CTable() {
	s_name = DEFAULT_NAME;
	cout << "bezp: '" << s_name << "'" << endl;
	tableLength = DEFAULT_LENGTH;
	piTable = new int[tableLength];
}
CTable::CTable(string sName, int iTableLength) {
	tableLength = iTableLength;
	piTable = new int[iTableLength];
	s_name = sName;
	cout << "parametr: '" << s_name << "'" << endl;
}

CTable::CTable(CTable &pcOther) {
	tableLength = pcOther.tableLength;
	piTable = new int[tableLength];
	memcpy(piTable, pcOther.piTable, tableLength * sizeof(int));
	s_name = pcOther.s_name + "_copy";
	cout << "kopiuj: '" << s_name << "'" << endl;
}
CTable::~CTable() {
	cout << "usuwam: "<<s_name << endl;
	delete[] piTable;
	
}



CTable* CTable::operator/(int divValue) {
	if (divValue <= 0 || divValue > tableLength) {
		CTable* newTable = new CTable("pustaTablica", 0);
		return newTable;
	}
	else {
		int newTabLength=tableLength - (tableLength / divValue);
		CTable* newTable = new CTable("podzielonyStolik",newTabLength);
		int j = 0;
		for (int i = 0;i < tableLength;i++) {
			if ((i + 1) % divValue != 0) {
				newTable->piTable[j] = piTable[i];
				j++;
			}
		}
		return newTable;
	}
}
void CTable::vSetName(string sName) {
	s_name = sName;
}
bool CTable::vSetValueAt(int iOffset, int iNewVal) {
	if (iOffset < 0 || iOffset >= tableLength) return false;
	else {
		piTable[iOffset] = iNewVal;

	}
	return true;
}
string CTable::getName() {
	return s_name;
}
void CTable::vPrint() {
	for (int i = 0;i < tableLength;i++) {
		cout << piTable[i] << " ";
	}
	cout << endl;;
}
void CTable::delTable() {
	delete[] piTable;
}
CTable CTable::operator+(CTable &pcOther) {
	CTable tableTemp(s_name + "+" + pcOther.s_name, tableLength + pcOther.tableLength);
	memcpy(tableTemp.piTable, piTable, tableLength * sizeof(int));
	memcpy(tableTemp.piTable + tableLength, pcOther.piTable, pcOther.tableLength * sizeof(int));
	return tableTemp;
}
bool CTable::bSetNewSize(int iTableLen) {
	if (iTableLen < 0) return false;
	else {
		tableLength = iTableLen;
		int* piTableTemp = new int[tableLength];
		memcpy(piTableTemp, piTable, tableLength * 4);
		delete[] piTable;
		piTable = piTableTemp;
		return true;
	}
}
int CTable::getSize(){
	return tableLength;
}

CTable* CTable::pcClone() {
	CTable* tableTemp = new CTable(s_name,tableLength);
	tableTemp->piTable = new int[tableLength];
	memcpy(tableTemp->piTable, piTable, tableLength * 4);
	return tableTemp;
}

CTable::CTable(CTable&& pcOther){
	piTable = pcOther.piTable;
	tableLength = pcOther.tableLength;
	s_name = pcOther.s_name;

	pcOther.piTable = NULL;

	std::cout << "MOVE ";
}
CTable CTable::operator=(CTable &pcOther) {
	if (piTable != NULL) delete piTable;
	piTable = pcOther.piTable;
	tableLength = pcOther.tableLength;
	pcOther.piTable = NULL;
	return *this;
}





		
	
