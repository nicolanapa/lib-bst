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

	cout << this->data << " of weight " << this->weight << endl;

	this->rchild = this->rchild;
	this->rchild->inOrder();
}

Node* Node::searchR(int k) {
	if (this == nullptr) {
		cout << k << " Not found" << endl;

		return this;
	}

	if (this->data == k) {
		cout << "Found " << this->data << endl;

		return this;
	}

	if (k < this->data) {
		this->lchild = lchild->searchR(k);
	}

	if (k > this->data) {
		this->rchild = rchild->searchR(k);
	}

	return this;
}

Node* Node::searchI(int k) {
	Node* tempStruct = this;

	while ((tempStruct->lchild != nullptr && k < tempStruct->data) ||
		   (tempStruct->rchild != nullptr && k > tempStruct->data)) {
		if (k < tempStruct->data) {
			tempStruct = tempStruct->lchild;
		} else if (k > tempStruct->data) {
			tempStruct = tempStruct->rchild;
		}
	}

	if (k == tempStruct->data) {
		cout << "Found " << k << endl;

		return tempStruct;
	} else {
		cout << k << " Not Found" << endl;

		return nullptr;
	}
}