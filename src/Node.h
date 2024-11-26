#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node {
	private:
	int data;
	int weight;
	Node* lchild;
	Node* rchild;

	public:
	Node(int data = 0, int weight = 0, Node* lchild = nullptr,
		 Node* rchild = nullptr);

	Node* insertI(int k);

	Node* insertR(int k);

	void preOrder();

	void inOrder();

	void postOrder();

	bool searchI(int k);

	bool searchR(int k);

	Node* deleteNode(int k);

	bool isBst();
};
