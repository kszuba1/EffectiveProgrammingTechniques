#pragma once 
#include <iostream>
#include <vector>
using namespace std;

class CNodeStatic
{
public:
	CNodeStatic() { i_val = 0; pc_parent_node = NULL; };
	~CNodeStatic();
	void vSetValue(int iNewVal) { i_val = iNewVal; };
	int iGetChildrenNumber() { return(v_children.size()); };
	void vAddNewChild();
	void vAddNewChild(CNodeStatic* newChild);
	CNodeStatic *pcGetChild(int iChildOffset);
	void vPrint() { cout << " " << i_val<<endl; };
	void vPrintAllBelow();
	void vPrintUp();
	bool moveSubtree(CNodeStatic * pcParentNode);
	void update();
private:
	vector<CNodeStatic> v_children;
	CNodeStatic *pc_parent_node;
	int i_val;
};