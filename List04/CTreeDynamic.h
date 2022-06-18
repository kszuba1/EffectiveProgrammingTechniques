#pragma once
#include "CNodeDynamic.h"
class CTreeDynamic
{
public:
	CTreeDynamic();
	CTreeDynamic(CNodeDynamic* newRoot);
	~CTreeDynamic();
	CNodeDynamic *pcGetRoot() { return(pc_root); }
	void vPrintTree();
	bool vPump(int val);
private:
	CNodeDynamic *pc_root;
};//class CTreeDynamic
