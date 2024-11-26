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

	Node* insertR(int k);

	void inOrder();

	bool searchR(int k);

	bool searchI(int k);


};
