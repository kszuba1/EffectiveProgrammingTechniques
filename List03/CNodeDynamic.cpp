/*
#include "CNodeDynamic.h"
#include "CTreeDynamic.h"

CNodeDynamic::~CNodeDynamic() {
	for (int i = 0; i < v_children.size(); i++) {
		if (v_children[i]->v_children.size() != 0) {
			v_children[i]->~CNodeDynamic();

		}
		delete v_children[i];
	}
}

void CNodeDynamic::vAddNewChild() {
	CNodeDynamic* child = new CNodeDynamic();
	child->pc_parent_node = this;
	v_children.push_back(child);

}
void CNodeDynamic::vAddNewChild(CNodeDynamic* newChild) {
	v_children.push_back(newChild);

}

void CNodeDynamic::vPrintAllBelow() {
	vPrint();
	for (int i = 0; i < v_children.size(); i++) {
		v_children.at(i)->vPrintAllBelow();
	}
}

bool CNodeDynamic::moveSubtree(CNodeDynamic *pcParentNode) {

	if (pc_parent_node != NULL) {
		for (int i = 0; i < pc_parent_node->v_children.size(); i++) {
			if (pc_parent_node->v_children[i] == this) {
				pc_parent_node->v_children.erase(pc_parent_node->v_children.begin() + i);
				break;
			}
		}
	}

	pc_parent_node = pcParentNode;
	pcParentNode->vAddNewChild(this);
	return true;

}
bool CNodeDynamic::vPrune(int value) {
	if (pc_parent_node == NULL) return false;
	for (int i = 0;i < v_children.size();i++) {
		if (v_children[i]->i_val == value && v_children[i]->v_children.size() != 0) {
			for (int j = 0;j < v_children[i]->v_children.size();j++) {
				v_children.push_back(v_children[i]->v_children[j]);
				v_children[i]->v_children[j]->pc_parent_node = this;
			}
			delete v_children[i];
			v_children.erase(v_children.begin() + i);
			vPrune(value);
		}
	}
	for (int i = 0;i < v_children.size();i++) {
		v_children[i]->vPrune(value);
	}
	return true;
}


*/
