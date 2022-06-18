#pragma once
#include <iostream>
#include <vector>

using namespace std;



template<typename T> class CNodeDynamic {
public:
	CNodeDynamic() { i_val = new T; pc_parent_node = NULL; };
	~CNodeDynamic();

	void vSetValue(T iNewVal) { *i_val = iNewVal; };
	void vAddNewChild();
	void vAddNewChild(T newChildValue);
	void vPrint() { cout << " " << *i_val; };
	void vPrintAllBelow();
	bool moveSubtree(CNodeDynamic<T>* pcParentNode);
	bool vPrune(T value);
private:
	vector<CNodeDynamic<T>*> v_children;
	CNodeDynamic<T>* pc_parent_node;
	T* i_val;

};

template<typename T> class CTreeDynamic {
public:
	CTreeDynamic();
	~CTreeDynamic();

	CNodeDynamic<T>* pcGetRoot() { return(pc_root); }
	void vPrintTree();
	bool bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode);
private:
	CNodeDynamic<T>* pc_root;
};



template <typename T>
CTreeDynamic<T>::CTreeDynamic() {
	pc_root = new CNodeDynamic<T>();
}

template <typename T>
CTreeDynamic<T>::~CTreeDynamic() {
	delete pc_root;
}

template <typename T>
void CTreeDynamic<T>::vPrintTree() {
	pc_root->vPrintAllBelow();
}

template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode)
{
	if (pcParentNode == NULL && pcNewChildNode == NULL) return false;
	return pcParentNode->moveSubtree(pcParentNode);
}

template <typename T>
CNodeDynamic<T>::~CNodeDynamic() {
	for (int i = 0; i < v_children.size(); i++) {
		delete v_children[i];
	}
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild() {
	CNodeDynamic<T>* child = new CNodeDynamic();
	child->pc_parent_node = this;
	v_children.push_back(child);
}
template <typename T>
void CNodeDynamic<T>::vAddNewChild(T newChildValue) {
	CNodeDynamic<T>* child = new CNodeDynamic();
	child->pc_parent_node = this;
	child->vSetValue(newChildValue);
	v_children.push_back(child);
}
template <typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
	vPrint();
	for (int i = 0; i < v_children.size(); i++) {
		v_children.at(i)->vPrintAllBelow();
	}
}
template <typename T>
bool CNodeDynamic<T>::moveSubtree(CNodeDynamic<T> *pcParentNode) {

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
template <typename T>
bool CNodeDynamic<T>::vPrune(T value) {
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



