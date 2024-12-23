#include "Node.h"

Node::Node(int data, int weight, Node* lchild, Node* rchild) {
	this->data = data;
	this->weight = weight;
	this->lchild = lchild;
	this->rchild = rchild;
};

Node* Node::insertI(int k) {
	Node* tempStruct = this;
	Node* tempStruct2 = this;

	while (tempStruct != nullptr) {
		tempStruct2 = tempStruct;

		if (k == tempStruct->data) {
			tempStruct->weight += 1;

			return this;
		}
		if (k < tempStruct->data) {
			tempStruct = tempStruct->lchild;
		} else if (k > tempStruct->data) {
			tempStruct = tempStruct->rchild;
		}
	}

	if (k < tempStruct2->data) {
		tempStruct2->lchild = new Node(k);
	} else {
		tempStruct2->rchild = new Node(k);
	}

	return this;
}

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

void Node::preOrder() {
	if (this == nullptr) {
		return;
	}

	cout << this->data << " of weight " << this->weight << endl;

	this->lchild = this->lchild;
	this->lchild->preOrder();

	this->rchild = this->rchild;
	this->rchild->preOrder();
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

void Node::postOrder() {
	if (this == nullptr) {
		return;
	}

	this->lchild = this->lchild;
	this->lchild->postOrder();

	this->rchild = this->rchild;
	this->rchild->postOrder();

	cout << this->data << " of weight " << this->weight << endl;
}

bool Node::searchI(int k) {
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

		return true;
	} else {
		cout << k << " Not Found" << endl;

		return false;
	}
}

bool Node::searchR(int k) {
	if (this->data == k) {
		cout << "Found " << k << endl;

		return true;
	}

	if (k < this->data) {
		this->lchild = this->lchild;

		if (this->lchild == nullptr) {
			cout << k << " Not found" << endl;

			return false;
		} else {
			this->lchild->searchR(k);
		}
	}

	if (k > this->data) {
		this->rchild = this->rchild;

		if (this->rchild == nullptr) {
			cout << k << " Not found" << endl;

			return false;
		} else {
			this->rchild->searchR(k);
		}
	}
}

Node* Node::deleteNode(int k) {
	return nullptr;
}

bool Node::isBst() {
	bool check = true;

	if (this == nullptr) {
		return check;
	}

	if (this->lchild != nullptr) {
		cout << "LCHILD " << this->data << " < " << this->lchild->data << endl;

		if (this->data < this->lchild->data) {
			return false;
		} else {
			this->lchild = this->lchild;
			check = this->lchild->isBst();
		}
	}

	if (this->rchild != nullptr) {
		cout << "RCHILD " << this->data << " > " << this->rchild->data << endl;

		if (this->data > this->rchild->data) {
			return false;
		} else {
			this->rchild = this->rchild;
			check = this->rchild->isBst();
		}
	}

	return check;
}
