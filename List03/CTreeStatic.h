#pragma once
#include "CNodeStatic.h"

class CTreeStatic
{
public:
	CTreeStatic();
	~CTreeStatic();
	CNodeStatic *pcGetRoot() { return(&c_root); }
	void vPrintTree();
	bool moveSubtree(CNodeStatic * pcParentNode, CNodeStatic * pcNewChildNode);
private:
	CNodeStatic c_root;
};
