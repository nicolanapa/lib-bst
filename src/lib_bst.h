#pragma once

#include <iostream>
#include <string>

using namespace std;

// Default Node Struct

struct Node {
	int data;
	int duplicati;
	Node* left;
	Node* right;
	Node(int data1 = 0, Node* left1 = nullptr, Node* right1 = nullptr) {
		data = data1;
		duplicati = 0;
		left = left1;
		right = right1;
	};
};

// Search if a Data is already in a BST
// One version returns true/false
// The other returns the pointer to the found Node (or nullptr if it doesn't
// exists)

bool searchForSameDataLoop(int datoFinale, Node* strutturaIniziale) {
	Node* strutturaTemp = strutturaIniziale;

	int datoFinaleTrovato = NULL;
	bool trovato = false;

	while (
		(strutturaTemp->left != nullptr && datoFinale < strutturaTemp->data) ||
		(strutturaTemp->right != nullptr && datoFinale > strutturaTemp->data)) {
		if (datoFinale < strutturaTemp->data) {
			strutturaTemp = strutturaTemp->left;
		} else if (datoFinale > strutturaTemp->data) {
			strutturaTemp = strutturaTemp->right;
		}
	}

	if (datoFinale == strutturaTemp->data) {
		datoFinaleTrovato = strutturaTemp->data;
		trovato = true;
	}

	return trovato;
}

Node* searchForSameDataNodeLoop(int datoFinale, Node* strutturaIniziale) {
	Node* strutturaTemp = strutturaIniziale;

	int datoFinaleTrovato = NULL;
	bool trovato = false;

	while (
		(strutturaTemp->left != nullptr && datoFinale < strutturaTemp->data) ||
		(strutturaTemp->right != nullptr && datoFinale > strutturaTemp->data)) {
		if (datoFinale < strutturaTemp->data) {
			strutturaTemp = strutturaTemp->left;
		} else if (datoFinale > strutturaTemp->data) {
			strutturaTemp = strutturaTemp->right;
		}
	}

	if (datoFinale == strutturaTemp->data) {
		datoFinaleTrovato = strutturaTemp->data;
		trovato = true;
	}

	return (trovato == true ? strutturaTemp : nullptr);
}

// Recursive version of searchForSameDataX

bool searchForSameDataRecursive(int datoFinale, Node* strutturaIniziale,
								bool result = false) {
	if (strutturaIniziale == nullptr) {
		return false;
	} else if (strutturaIniziale->data == datoFinale) {
		return true;
	}

	if (datoFinale < strutturaIniziale->data) {
		result = searchForSameDataRecursive(datoFinale, strutturaIniziale->left,
											result);
	}

	if (datoFinale > strutturaIniziale->data) {
		result = searchForSameDataRecursive(datoFinale,
											strutturaIniziale->right, result);
	}

	return result;
}

Node* searchForSameDataNodeRecursive(int datoFinale, Node* strutturaIniziale,
									 Node* result = nullptr) {
	if (strutturaIniziale == nullptr) {
		return nullptr;
	} else if (strutturaIniziale->data == datoFinale) {
		return strutturaIniziale;
	}

	if (datoFinale < strutturaIniziale->data) {
		*result = searchForSameDataRecursive(datoFinale,
											 strutturaIniziale->left, result);
	}

	if (datoFinale > strutturaIniziale->data) {
		*result = searchForSameDataRecursive(datoFinale,
											 strutturaIniziale->right, result);
	}

	return result;
}

// Normal loop (iterate) and recursive Insert Function
// Inserts a Node to a BST

void setTreeLoop(int datoFinale, Node& strutturaIniziale, Node nodoFinale) {
	Node* strutturaTemp = &strutturaIniziale;
	Node* strutturaTemp2 = nullptr;

	while (strutturaTemp != nullptr) {
		strutturaTemp2 = strutturaTemp;

		if (datoFinale < strutturaTemp->data) {
			strutturaTemp = strutturaTemp->left;
		} else if (datoFinale > strutturaTemp->data) {
			strutturaTemp = strutturaTemp->right;
		}
	}

	if (datoFinale < strutturaTemp2->data) {
		strutturaTemp2->left = new Node(nodoFinale);
	} else {
		strutturaTemp2->right = new Node(nodoFinale);
	}
}

Node* setTreeRecursive(int datoFinale, Node* strutturaIniziale,
					   Node nodoFinale) {
	if (strutturaIniziale == nullptr) {
		return new Node(nodoFinale);
	}

	if (datoFinale < strutturaIniziale->data) {
		strutturaIniziale->left =
			setTreeRecursive(datoFinale, strutturaIniziale->left, nodoFinale);
	}

	if (datoFinale > strutturaIniziale->data) {
		strutturaIniziale->right =
			setTreeRecursive(datoFinale, strutturaIniziale->right, nodoFinale);
	}

	return strutturaIniziale;
}

// Updates the "duplicati" value
// Used mostly after checking if a value already exists in a BST ->
// searchForSameData Functions

void updateDuplicateTree(int datoFinale, Node& strutturaIniziale) {
	Node* strutturaTemp = &strutturaIniziale;

	while (
		(strutturaTemp->left != nullptr && datoFinale < strutturaTemp->data) ||
		(strutturaTemp->right != nullptr && datoFinale > strutturaTemp->data)) {
		if (datoFinale < strutturaTemp->data) {
			strutturaTemp = strutturaTemp->left;
		} else if (datoFinale > strutturaTemp->data) {
			strutturaTemp = strutturaTemp->right;
		}
	}

	if (datoFinale == strutturaTemp->data) {
		strutturaTemp->duplicati += 1;
	}
}

// Checks if a given BT is actually a BST

bool checkIfBst(Node* root, bool check = true) {
	if (root == nullptr) {
		return check;
	}

	if (root->left != nullptr) {
		check = checkIfBst(root->left, check);

		if (root->data < root->left->data) {
			// cout << root->data << " < " << root->left->data << endl;
			check = false;
		}
	}

	if (root->right != nullptr) {
		check = checkIfBst(root->right, check);

		if (root->data > root->right->data) {
			// cout << root->data << " < " << root->right->data << endl;
			check = false;
		}
	}

	return check;
}

// Deletes a given Node
// You can either use a pointer and dinamic memory -> Node* x = new Node(); and
// deleteNodeLoop(datoFinale, x) or a normal Node -> Node x(); and
// deleteNodeLoop(datoFinale, &x);

void deleteNodeLoop(int datoFinale, Node* strutturaIniziale) {
	Node* strutturaTemp = strutturaIniziale;
	Node* strutturaTemp2 = nullptr;
	Node* strutturaTemp3 = nullptr;

	while (strutturaTemp != nullptr) {
		strutturaTemp2 = strutturaTemp;

		if (datoFinale == strutturaTemp->data) {
			break;
		} else if (datoFinale < strutturaTemp->data) {
			strutturaTemp = strutturaTemp->left;
		} else if (datoFinale > strutturaTemp->data) {
			strutturaTemp = strutturaTemp->right;
		} else {
			strutturaTemp = nullptr;
			strutturaTemp2 = nullptr;
			strutturaTemp3 = nullptr;

			break;
		}

		strutturaTemp3 = strutturaTemp2;
	}

	if (strutturaTemp3 == nullptr) {
		return;
	}

	if (strutturaTemp3->left != nullptr) {
		if (strutturaTemp3->left->data == datoFinale) {
			if (strutturaTemp3->left->left == nullptr &&
				strutturaTemp3->left->right == nullptr) {
				strutturaTemp3->left = nullptr;
			} else if (strutturaTemp3->left->left != nullptr &&
					   strutturaTemp3->left->right == nullptr) {
				strutturaTemp3->left = strutturaTemp3->left->left;
			} else if (strutturaTemp3->left->left == nullptr &&
					   strutturaTemp3->left->right != nullptr) {
				strutturaTemp3->left = strutturaTemp3->left->right;
			} else if (strutturaTemp3->left->left != nullptr &&
					   strutturaTemp3->left->right != nullptr) {
				Node* strutturaTemp4 = strutturaTemp3->left;
				Node* strutturaTemp5 = new Node;

				while (strutturaTemp4 != nullptr) {
					strutturaTemp5 = strutturaTemp4;

					strutturaTemp4 = strutturaTemp4->left;
				}

				// cout << "The lowest value found from the Parent: " <<
				// strutturaTemp5->data << endl;

				int valueToChange = strutturaTemp5->data;

				delete strutturaTemp5;
				strutturaTemp5 = nullptr;
				strutturaTemp3->left = new Node(valueToChange);
			}

			return;
		}
	}

	if (strutturaTemp3->right != nullptr) {
		if (strutturaTemp3->right->data == datoFinale) {
			if (strutturaTemp3->right->left == nullptr &&
				strutturaTemp3->right->right == nullptr) {
				strutturaTemp3->right = nullptr;
			} else if (strutturaTemp3->right->left != nullptr &&
					   strutturaTemp3->right->right == nullptr) {
				strutturaTemp3->right = strutturaTemp3->right->left;
			} else if (strutturaTemp3->right->left == nullptr &&
					   strutturaTemp3->right->right != nullptr) {
				strutturaTemp3->right = strutturaTemp3->right->right;
			} else if (strutturaTemp3->right->left != nullptr &&
					   strutturaTemp3->right->right != nullptr) {
				Node* strutturaTemp4 = strutturaTemp3->right;
				Node* strutturaTemp5 = new Node;

				while (strutturaTemp4 != nullptr) {
					strutturaTemp5 = strutturaTemp4;

					strutturaTemp4 = strutturaTemp4->right;
				}

				// cout << "The lowest value found from the Parent: " <<
				// strutturaTemp5->data << endl;

				int valueToChange = strutturaTemp5->data;

				delete strutturaTemp5;
				strutturaTemp5 = nullptr;
				strutturaTemp3->right = new Node(valueToChange);
			}

			return;
		}
	}
}

/*void deleteNodeRecursive(int datoFinale, Node* strutturaIniziale) {
	Node* strutturaTemp = strutturaIniziale;
	Node* strutturaTemp2 = nullptr;
	Node* strutturaTemp3 = nullptr;

	while (strutturaTemp != nullptr) {
		strutturaTemp2 = strutturaTemp;

		if (datoFinale == strutturaTemp->data) {
			break;
		} else if (datoFinale < strutturaTemp->data) {
			strutturaTemp = strutturaTemp->left;
		} else if (datoFinale > strutturaTemp->data) {
			strutturaTemp = strutturaTemp->right;
		} else {
			strutturaTemp = nullptr;
			strutturaTemp2 = nullptr;
			strutturaTemp3 = nullptr;

			break;
		}

		strutturaTemp3 = strutturaTemp2;
	}

	if (strutturaTemp3 == nullptr) {
		return;
	}

	if (strutturaTemp3->left != nullptr) {
		if (strutturaTemp3->left->data == datoFinale) {
			if (strutturaTemp3->left->left == nullptr &&
strutturaTemp3->left->right == nullptr) { strutturaTemp3->left = nullptr; } else
if (strutturaTemp3->left->left != nullptr && strutturaTemp3->left->right ==
nullptr) { strutturaTemp3->left = strutturaTemp3->left->left; } else if
(strutturaTemp3->left->left == nullptr && strutturaTemp3->left->right !=
nullptr) { strutturaTemp3->left = strutturaTemp3->left->right; } else if
(strutturaTemp3->left->left != nullptr && strutturaTemp3->left->right !=
nullptr) { Node* strutturaTemp4 = strutturaTemp3->left; Node* strutturaTemp5 =
new Node;

				while (strutturaTemp4 != nullptr) {
					strutturaTemp5 = strutturaTemp4;

					strutturaTemp4 = strutturaTemp4->left;
				}

				//cout << "The lowest value found from the Parent: " <<
strutturaTemp5->data << endl;

				int valueToChange = strutturaTemp5->data;

				delete strutturaTemp5;
				strutturaTemp5 = nullptr;
				strutturaTemp3->left = new Node(valueToChange);
			}

			return;
		}
	}

	if (strutturaTemp3->right != nullptr) {
		if (strutturaTemp3->right->data == datoFinale) {
			if (strutturaTemp3->right->left == nullptr &&
strutturaTemp3->right->right == nullptr) { strutturaTemp3->right = nullptr; }
else if (strutturaTemp3->right->left != nullptr && strutturaTemp3->right->right
== nullptr) { strutturaTemp3->right = strutturaTemp3->right->left; } else if
(strutturaTemp3->right->left == nullptr && strutturaTemp3->right->right !=
nullptr) { strutturaTemp3->right = strutturaTemp3->right->right; } else if
(strutturaTemp3->right->left != nullptr && strutturaTemp3->right->right !=
nullptr) { Node* strutturaTemp4 = strutturaTemp3->right; Node* strutturaTemp5 =
new Node;

				while (strutturaTemp4 != nullptr) {
					strutturaTemp5 = strutturaTemp4;

					strutturaTemp4 = strutturaTemp4->right;
				}

				//cout << "The lowest value found from the Parent: " <<
strutturaTemp5->data << endl;

				int valueToChange = strutturaTemp5->data;

				delete strutturaTemp5;
				strutturaTemp5 = nullptr;
				strutturaTemp3->right = new Node(valueToChange);
			}

			return;
		}
	}
}*/

//

// Pre-order, In-order and Post-order Traversal Recursive Functions
// Used to display BSTs

void preOrderTraversal(Node* root) {
	if (root == nullptr) {
		return;
	}

	cout << root->data << " ";

	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {
	if (root == nullptr) {
		return;
	}

	inOrderTraversal(root->left);

	cout << root->data << " ";

	inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
	if (root == nullptr) {
		return;
	}

	postOrderTraversal(root->left);
	postOrderTraversal(root->right);

	cout << root->data << " ";
}

//

// Check max height / node height of a given BST

int checkHeightOfWholeBst(Node* strutturaIniziale, int height = 0) {
	if (strutturaIniziale == nullptr) {
		return 0;
	}

	int height1 = checkHeightOfWholeBst(strutturaIniziale->left, height + 1);
	int height2 = checkHeightOfWholeBst(strutturaIniziale->right, height + 1);

	return (height1 >= height2 ? height1 : height2) + 1;
}

int checkHeightOfNodeBst(Node* strutturaIniziale, int datoFinale) {
	Node* strutturaTemp = strutturaIniziale;
	Node* strutturaTemp2 = nullptr;
	int height = 0;

	while (strutturaTemp != nullptr) {
		strutturaTemp2 = strutturaTemp;

		if (datoFinale == strutturaTemp->data) {
			break;
		} else if (datoFinale < strutturaTemp->data) {
			strutturaTemp = strutturaTemp->left;
		} else if (datoFinale > strutturaTemp->data) {
			strutturaTemp = strutturaTemp->right;
		}

		height += 1;
	}

	return height;
}

//

// Creates a BST based on user's input and lenght

void createBst(Node* root, int lengthArray = 1) {
	srand(time(NULL));

	bool randomValues;
	cout << "Do you want all Data be random? (1/0) ";
	cin >> randomValues;
	cout << endl;
	bool recursiveLoop;
	cout << "BST to be created with loops? (1/0 for recursion)";
	cin >> recursiveLoop;
	cout << endl;

	int* nodi = new int[lengthArray];
	if (randomValues == false) {
		for (int i = 0; i < lengthArray; i++) {
			cin >> nodi[i];
		}
	} else {
		for (int i = 0; i < lengthArray; i++) {
			nodi[i] = rand() % 100;
		}
	}

	for (int i = 0; i < lengthArray; i++) {
		int tempData = nodi[i];

		if (recursiveLoop == true) {
			if (searchForSameDataLoop(nodi[i], root)) {
				updateDuplicateTree(nodi[i], *root);
			} else {
				Node* nuovo = new Node(nodi[i]);

				setTreeLoop(nodi[i], *root, *nuovo);
			}
		} else if (recursiveLoop == false) {
			if (searchForSameDataRecursive(
					nodi[i],
					root) /*searchForSameDataNodeRecursive(nodi[i], root)*/) {
				updateDuplicateTree(nodi[i], *root);
			} else {
				Node* nuovo = new Node(nodi[i]);

				setTreeRecursive(nodi[i], root, *nuovo);
			}
		}
	}

	if (checkIfBst(root) == 0) {
		cout << "An Error has happened, it's not a BST" << endl;
	}

	delete[] nodi;
	nodi = nullptr;
}

// Functions in the Library:
//
// Insert Node, Loop and Recursion -> setTreeLoop and setTreeRecursive
// Search Node, Loop and Recursion -> searchForSameDataLoop,
// searchForSameDataNodeLoop, searchForSameDataRecursive,
// searchForSameDataNodeRecursive Update "duplicati" value, Loop ->
// updateDuplicateTree Delete a node, Loop -> deleteNodeLoop
//
// Check if a BT is a BST, Recursion -> checkIfBst
// Check max height of a BST, Recursion -> checkHeightOfWholeBst
// Check height of a BST at a given Node, Loop -> checkHeightOfNodeBst
// Traversal (pre-order, in-order, post-order), Recursion