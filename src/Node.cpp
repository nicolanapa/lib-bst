#include "Node.h"

Node::Node(int data = 0, Node* lchild = nullptr, Node* rchild = nullptr) {
	this->data = data;
	this->weight = 0;
	this->lchild = lchild;
	this->rchild = rchild;
};

Node* Node::insertR(int k) {
	return nullptr;
}

void Node::inOrder() {}
