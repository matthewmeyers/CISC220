/*
 * BSTB.cpp

 * Matt Meyers
 * Lab Section 40
 * TA: Leighanne Hsu
 */

#include "BSTB.hpp"
#include "NodeTB.hpp"
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

BSTB::BSTB() {
	root = NULL;
	count = 0;
}
BSTB::~BSTB() {
}
/*Returns the height of a node, 0 if node is NULL
 *
 * Parameter:	NodeTB n
 * Returns height(int)
 */
int BSTB::getHeight(NodeTB *n) {
	if (n == NULL) {
		return 0;
	} else {
		return n->height;
	}//if
}

/*Calculates the balance factor for a node
 *
 * Parameter:	NodeTB n
 * Returns balance factor(int)
 */
int BSTB::balFac(NodeTB *n) {
	return (getHeight(n->left) - getHeight(n->right));
}
/*Sets the height of a node to be one greater than the max height of its children
 *
 * Parameter:	NodeTB n
 * no return
 */
void BSTB::setHeight(NodeTB *n) {
	int lHeight = getHeight(n->left);
	int rHeight = getHeight(n->right);
	if (lHeight > rHeight) {
		n->height = lHeight + 1;
	} else {
		n->height = rHeight + 1;
	}//if
}
/*Recursively inserts a unique string into an AVL tree
 *
 * Parameters:	string x
 * returns the root node
 */
NodeTB *BSTB::insert(string x) {
	if (root == NULL) {
		root = new NodeTB(x);
		count++;
		return root;
	}//if

	//cout << "PRINTING TREE" << endl;
	//printTreeio();
	//cout << "DONE PRINTING" << endl;

	if (search(x)) {
		return root;
	}//if
	if (x < root->word) {
		root->left = insert(x, root->left);
	} else {
		root->right = insert(x, root->right);
	}//if
	count++;
	root = balance(root);
	return root;
}
/*Continuation of previous function
 *
 * Parameters:	string x
 * 				NodeTB n (root of subtree)
 * returns the root node
 */
NodeTB *BSTB::insert(string x, NodeTB *n) {
	if (n == NULL) {
		//cout << "Inserting " << x << endl;
		return (new NodeTB(x));
	}//if
	if (x < n->word) {
		n->left = insert(x, n->left);
	} else {
		n->right = insert(x, n->right);
	}//if
	return balance(n);
}
/*Performs rotations to balance a tree
 *
 * Parameters: NodeTB n (root of tree)
 * returns root node
 */
NodeTB *BSTB::balance(NodeTB *n) {
	setHeight(n);
	NodeTB *tmp = n;
	if (balFac(n) <= -2) {
		if (balFac(n->right) > 0) {
			n->right = rotateRight(n->right);
		}//if >0
		tmp = rotateLeft(n);
	} else if (balFac(n) >= 2) {
		if (balFac(n->left) < 0) {
			n->left = rotateLeft(n->left);
		}//if <0
		tmp = rotateRight(n);
	}//if 2/-2
	return tmp;
}
/*Performs a right rotation around the root node n
 *
 * Parameters:	NodeTB n (root of tree being rotated)
 * Returns root of new tree
 */
NodeTB *BSTB::rotateRight(NodeTB *n) {
	NodeTB *x = n->left;
	NodeTB *tmp = x->right;

	x->right = n;
	n->left = tmp;
	setHeight(n);
	setHeight(x);
	return x;
}
/*Performs a left rotation around the root node n
 *
 * Parameters:	NodeTB n (root of tree being rotated)
 * Returns root of new tree
 */
NodeTB *BSTB::rotateLeft(NodeTB *n) {
	NodeTB *x = n->right;
	NodeTB *tmp = x->left;

	x->left = n;
	n->right = tmp;
	setHeight(n);
	setHeight(x);
	return x;
}
/*Recursively prints a tree in order
 *
 * no parameters or return
 */
void BSTB::printTreeio() {
	if (root == NULL) {
		return;
	}
	printTreeio(root->left);
	cout << root->word << endl;
	printTreeio(root->right);
	return;
}
/*Recursively prints a tree in order
 *
 * Parameters:	NodeTB n (root of subtree)
 * no return
 */
void BSTB::printTreeio(NodeTB *n) {
	if (n == NULL) {
		return;
	}
	printTreeio(n->left);
	cout << n->word << endl;
	printTreeio(n->right);
	return;
}
/*Recursively prints a tree in pre order
 *
 * no parameters or return
 */
void BSTB::printTreePre() {
	if (root == NULL) {
		return;
	}
	cout << root->word << endl;
	printTreePre(root->left);
	printTreePre(root->right);
	return;
}
/*Recursively prints a tree in pre order
 *
 * Parameters:	NodeTB n (root of subtree)
 * no return
 */
void BSTB::printTreePre(NodeTB *n) {
	if (n == NULL) {
		return;
	}
	cout << n->word << endl;
	printTreePre(n->left);
	printTreePre(n->right);
	return;
}
/*Recursively prints a tree in post order
 *
 * no parameters or return
 */
void BSTB::printTreePost() {
	if (root == NULL) {
		return;
	}
	printTreePost(root->left);
	printTreePost(root->right);
	cout << root->word << endl;
	return;
}
/*Recursively prints a tree in post order
 *
 * Parameters:	NodeTB n (root of subtree)
 * no return
 */
void BSTB::printTreePost(NodeTB *n) {
	if (n == NULL) {
		return;
	}
	printTreePost(n->left);
	printTreePost(n->right);
	cout << n->word << endl;
	return;
}
/*Recursively searches a tree for a given string
 *
 * Parameters:	string x (string in question)
 * returns true if string is in tree, false otherwise
 */
bool BSTB::search(string x) {
	if (root->word == x) {
		return true;
	}//if
	if (x > root->word) {
		return search(root->right, x);
	} else {
		return search(root->left, x);
	}//if
}
/*Recursively searches a tree for a given string
 *
 * Parameters:	string x (string in question)
 * 				NodeTB n (root of subtree)
 * returns true if string is in tree, false otherwise
 */
bool BSTB::search(NodeTB *n, string x) {
	if (n == NULL) {
		return false;
	}//if
	if (n->word == x) {
		return true;
	}//if
	if (x > n->word) {
		return search(n->right, x);
	} else {
		return search(n->left, x);
	}//if
}
