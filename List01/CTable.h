#pragma once
#include <string>
using namespace std;

class CTable
{
public:
	static const string DEFAULT_NAME;
	static const int DEFAULT_LENGTH;
	CTable();
	CTable(string sName, int iTableLen);
	CTable(CTable &pcOther);
	CTable(CTable&& pcOther);
	~CTable();
	bool vSetValueAt(int iOffset, int iNewVal);
	CTable operator=(CTable &pcOther);
	bool bSetNewSize(int iTableLen);
	int getSize();
	CTable operator+(CTable &pcOther);
	CTable *operator/(int value);
	void vSetName(string sName);
	void delTable();
	string getName();
	void vPrint();
	CTable *pcClone();
	
private:
	std::string s_name;
	int* piTable;
	int tableLength;
};


