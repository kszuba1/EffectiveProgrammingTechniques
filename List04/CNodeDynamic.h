#pragma once
#include <iostream>
#include <vector>
using namespace std;

class CNodeDynamic
{
public:
	CNodeDynamic() { i_val = 0; pc_parent_node = NULL; };
	~CNodeDynamic();
	void vSetValue(int iNewVal) { 
		i_val = iNewVal; }
	int iGetChildrenNumber() {
		return(v_children.size); }
	void vAddNewChild();
	CTreeDynamic *pcGetChild(int &iChildOffset);
	void vPrint() { cout << " " << i_val; };
	void vPrintAllBelow();
	bool vPump(int value);


private:
	vector<CNodeDynamic *> v_children;
	CNodeDynamic *pc_parent_node;
	int i_val;
};//class CNodeDynamic
