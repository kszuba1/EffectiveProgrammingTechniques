#include "CNodeDynamic.h"
#include "CTreeDynamic.h"

CNodeDynamic::~CNodeDynamic() {
	for (int i = 0; i < v_children.size(); i++) {
		delete v_children[i];
	}
}
void CNodeDynamic::vAddNewChild() {
	CNodeDynamic* child = new CNodeDynamic();
	child->pc_parent_node = this;
	v_children.push_back(child);

}
CTreeDynamic* CNodeDynamic::pcGetChild(int iChildOffset) {
	if ((iChildOffset < 0) && (v_children.size() <= iChildOffset)) {
		return NULL;
	}
	CTreeDynamic* newTree = new CTreeDynamic(v_children.at(iChildOffset));
	return newTree;


}
void CNodeDynamic::vPrintAllBelow() {
	vPrint();
	for (int i = 0; i < v_children.size(); i++) {
		v_children.at(i)->vPrintAllBelow();
	}
}

bool CNodeDynamic::vPump(int value) {
	if (pc_parent_node == NULL) return false;
	else {
		if (v_children.size() != 0) {
			for (int i = 0;i < v_children.size();i++) {
				if (v_children[i]->i_val == value && v_children[i]->v_children.size() != 0) {
					for (int j = 0;j < v_children[i]->v_children.size();j++) {
						v_children.push_back(v_children[i]->v_children[j]);
						v_children[i]->v_children[j]->pc_parent_node = this;
					}
					vPump(value);
				}
				else {
					v_children.erase(v_children.begin() + i);
				}
			}


		}
		return true;
	}

}

