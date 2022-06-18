#include "CNodeStatic.h"
#include "CTreeStatic.h"
using namespace std;

CNodeStatic::~CNodeStatic() {
}

void CNodeStatic::vAddNewChild() {
	CNodeStatic child;
	child.pc_parent_node = this;
	v_children.push_back(child);
}
void CNodeStatic::vAddNewChild(CNodeStatic* newChild){
	v_children.push_back(*newChild);
	}
CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset) {
	if ((iChildOffset < 0) && (v_children.size() < iChildOffset)) {
		return NULL;
	}

	return &v_children.at(iChildOffset);
}
void CNodeStatic::vPrintAllBelow() {
	vPrint();
		for (int i = 0;i < v_children.size();i++) {
			v_children.at(i).vPrintAllBelow();
		}
}
void CNodeStatic::vPrintUp() {
	vPrint();
	if (pc_parent_node != NULL) {
		pc_parent_node->vPrintUp();
	}

}
bool CNodeStatic::moveSubtree(CNodeStatic *pcParentNode) {
	if (pc_parent_node != NULL) {
		for (int i = 0; i < pc_parent_node->v_children.size(); i++) {
			if (&(pc_parent_node->v_children[i])==this) {
				pc_parent_node->v_children.erase(pc_parent_node->v_children.begin() + i);
				break;
			}
		}
	}
	this->pc_parent_node = pcParentNode;
	pcParentNode->vAddNewChild(this);
	update();
	for(int i = 0;i < v_children.size();i++) {
		v_children[i].pc_parent_node = pcParentNode;
	}

	return true;
	
}
void CNodeStatic::update() {
	if (v_children.size() != 0) {
		for (int i = 0;i < v_children.size();i++) {
			v_children[i].pc_parent_node->update();
		}
	}
	pc_parent_node = this;


}

