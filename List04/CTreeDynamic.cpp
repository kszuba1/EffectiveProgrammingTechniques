#include "CTreeDynamic.h"
#include  "CNodeDynamic.h"

CTreeDynamic::CTreeDynamic() {
	pc_root = new CNodeDynamic();
}

CTreeDynamic::CTreeDynamic(CNodeDynamic* newRoot) {
	pc_root = newRoot;
}
CTreeDynamic::~CTreeDynamic() {
	delete pc_root;
}
void CTreeDynamic::vPrintTree() {
	pc_root->vPrintAllBelow();
}
bool CTreeDynamic::vPump(int value) {
	return pc_root->vPump(value);
}
