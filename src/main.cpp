#include "Node.h"
// #include "lib_bst.h"

using namespace std;

/*bool testCheckIfBst() {
	bool everythingWorks = true;

	cout << "It's a BST: "
		 << checkIfBst(new Node(20, new Node(25), new Node(26)))
		 << ", expected value: 0" << endl; // === 0
	if (checkIfBst(new Node(20, new Node(25), new Node(26))) != 0) {
		everythingWorks = false;
	}

	cout << "It's a BST: "
		 << checkIfBst(new Node(20, new Node(18), new Node(26)))
		 << ", expected value: 1" << endl; // === 1
	if (checkIfBst(new Node(20, new Node(18), new Node(26))) != 1) {
		everythingWorks = false;
	}

	cout << "It's a BST: "
		 << checkIfBst(new Node(20, new Node(25, new Node(18), new Node(27)),
								new Node(26, new Node(25), new Node(36))))
		 << ", expected value: 0" << endl; // === 0
	if (checkIfBst(new Node(20, new Node(25, new Node(18), new Node(27)),
							new Node(26, new Node(25), new Node(36)))) != 0) {
		everythingWorks = false;
	}

	cout << "It's a BST: "
		 << checkIfBst(new Node(
				40, new Node(25, new Node(18, new Node(19)), new Node(27)),
				new Node(45, new Node(46), new Node(44))))
		 << ", expected value: 0" << endl; // === 0
	if (checkIfBst(
			new Node(40, new Node(25, new Node(18, new Node(19)), new Node(27)),
					 new Node(45, new Node(46), new Node(44)))) != 0) {
		everythingWorks = false;
	}

	// Checking if deleteNodeLoop() still keeps a BST being a BST

	Node *leafNode = new Node(20, new Node(10, new Node(5)), new Node(25));
	deleteNodeLoop(5, leafNode);
	cout << "Deleted leaf Node, it's a BST: " << checkIfBst(leafNode)
		 << ", expected value: 1" << endl; // === 1
	if (checkIfBst(leafNode) != 1) {
		everythingWorks = false;
	}

	Node *leftChildNode =
		new Node(20, new Node(10, new Node(5, new Node(2))), new Node(25));
	deleteNodeLoop(5, leftChildNode);
	cout << "Deleted left child only Node, it's a BST: "
		 << checkIfBst(leftChildNode) << ", expected value: 1" << endl; // === 1
	if (checkIfBst(leftChildNode) != 1) {
		everythingWorks = false;
	}

	Node *rightChildNode = new Node(
		20, new Node(10, new Node(5, nullptr, new Node(7))), new Node(25));
	deleteNodeLoop(5, rightChildNode);
	cout << "Deleted right child only Node, it's a BST: "
		 << checkIfBst(rightChildNode) << ", expected value: 1"
		 << endl; // === 1
	if (checkIfBst(rightChildNode) != 1) {
		everythingWorks = false;
	}

	Node *bothNode = new Node(
		20, new Node(10, new Node(5, new Node(2), new Node(7))), new Node(25));
	deleteNodeLoop(5, bothNode);
	cout << "Deleted Node with both children, it's a BST: "
		 << checkIfBst(bothNode) << ", expected value: 1" << endl; // === 1
	if (checkIfBst(bothNode) != 1) {
		everythingWorks = false;
	}

	return everythingWorks;
}*/

int main() {
	/*Node root(20);

	createBst(&root, 20);*/

	/*Node root(20,
			  new Node(10, new Node(5, new Node(2)),
					   new Node(13, nullptr, new Node(16))),
			  new Node(40));

	cout << "Pre-order: ";
	preOrderTraversal(&root);
	cout << endl;

	cout << "In-order: ";
	inOrderTraversal(&root);
	cout << endl;

	cout << "Post-order: ";
	postOrderTraversal(&root);
	cout << endl;

	cout << "Height of BST " << checkHeightOfWholeBst(&root) << endl;
	cout << "Height at 20 " << checkHeightOfNodeBst(&root, 20) << endl;
	cout << "Height at 10 " << checkHeightOfNodeBst(&root, 10) << endl;
	cout << "Height at 5 " << checkHeightOfNodeBst(&root, 5) << endl;
	cout << "Height at 2 " << checkHeightOfNodeBst(&root, 2) << endl;
	cout << "Height at 16 " << checkHeightOfNodeBst(&root, 16) << endl;
	cout << "Height at 40 " << checkHeightOfNodeBst(&root, 40) << endl;*/
	/*deleteNodeLoop(-100, &root);

	cout << "After deletion of -100" << endl << endl;

	cout << "Pre-order: ";
	preOrderTraversal(&root);
	cout << endl;

	cout << "In-order: ";
	inOrderTraversal(&root);
	cout << endl;

	cout << "Post-order: ";
	postOrderTraversal(&root);
	cout << endl;*/

	// cout << "Everything is working correctly: " << (testCheckIfBst() ? "true"
	// : "false") << endl;

	Node newClass(10);

	newClass.insertR(2);
	newClass.insertR(2);
	newClass.insertR(4);
	newClass.insertR(14);
	newClass.insertR(16);

	cout << "preOrder" << endl;

	newClass.preOrder();

	cout << "inOrder" << endl;

	newClass.inOrder();

	cout << "postOrder" << endl;

	newClass.postOrder();

	cout << endl;

	cout << newClass.searchI(10) << endl;
	cout << newClass.searchI(2) << endl;
	cout << newClass.searchI(4) << endl;
	cout << newClass.searchI(14) << endl;
	cout << newClass.searchI(16) << endl;
	newClass.searchI(18);

	cout << newClass.searchR(10) << endl;
	cout << newClass.searchR(2) << endl;
	cout << newClass.searchR(4) << endl;
	cout << newClass.searchR(14) << endl;
	cout << newClass.searchR(16) << endl;
	newClass.searchR(18);

	newClass.inOrder();

	cout << endl << endl;

	Node newClass2(10);

	newClass2.insertI(2);
	newClass2.insertI(2);
	newClass2.insertI(4);
	newClass2.insertI(14);
	newClass2.insertI(16);

	newClass2.inOrder();

	cout << newClass2.isBst() << endl;

	Node newClass3 = (10, Node(12), Node(9));

	newClass3.insertI(2);
	newClass3.insertI(2);
	newClass3.insertI(4);
	newClass3.insertI(14);
	newClass3.insertI(16);

	newClass3.inOrder();

	cout << newClass3.isBst() << endl;

	return 0;
}
