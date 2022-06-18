#include "CTreeStatic.h"

CTreeStatic::CTreeStatic() {
	c_root = CNodeStatic();
}

CTreeStatic::~CTreeStatic() {
}
void CTreeStatic::vPrintTree() {
	c_root.vPrintAllBelow();
}
bool CTreeStatic::moveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode) {
	if (pcParentNode != NULL || pcNewChildNode != NULL) {
		return pcNewChildNode->moveSubtree(pcParentNode);

	}
	return false;
}