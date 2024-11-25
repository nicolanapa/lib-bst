#include "Node.h"

Node::Node(int data, int weight, Node* lchild, Node* rchild) {
	this->data = data;
	this->weight = weight;
	this->lchild = lchild;
	this->rchild = rchild;
};

Node* Node::insertR(int k) {
	if (this->data == k) {
		this->weight += 1;
		return this;
	}

	if (k < this->data) {
		if (this->lchild == nullptr) {
			this->lchild = new Node(k);

			return this;
		} else {
			this->lchild = lchild->insertR(k);
		}
	}

	if (k > this->data) {
		if (this->rchild == nullptr) {
			this->rchild = new Node(k);

			return this;
		} else {
			this->rchild = rchild->insertR(k);
		}
	}

	return this;
}

void Node::inOrder() {
	if (this == nullptr) {
		return;
	}

	this->lchild = this->lchild;
	this->lchild->inOrder();

	cout << this->data << " " << this->weight << endl;

	this->rchild = this->rchild;
	this->rchild->inOrder();
}
