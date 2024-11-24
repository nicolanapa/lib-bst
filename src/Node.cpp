#include "Node.h"

Node::Node(int data, Node* lchild, Node* rchild) {
	this->data = data;
	this->weight = 0;
	this->lchild = lchild;
	this->rchild = rchild;
};

Node* Node::insertR(int k) {
	Node* newNode = new Node(this->data, this->lchild, this->rchild);

	if (newNode == nullptr) {
		return new Node(k);
	}

	if (newNode->data == k) {
		newNode->weight++;

		return newNode;
	}

	if (k < newNode->data) {
		newNode->lchild = insertR(k);
	}

	if (k > newNode->data) {
		newNode->rchild = insertR(k);
	}

	return newNode;
}

void Node::inOrder(Node *root) {
	if (root == nullptr) {
		return;
	}

	inOrder(root->lchild);

	cout << root->data << endl;

	inOrder(root->rchild);
}
