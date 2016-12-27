/*
 * BST.hpp
 *
 * Matt Meyers
 * Lab Section 40
 * TA: Leighanne Hsu
 */

#ifndef BST_HPP_
#define BST_HPP_

#include "Node.hpp"
#include <stdlib.h>

class BST {
	Node *root;
	int count;
public:
	BST();
	~BST();
	int getHeight(Node *n); //Returns height of a node
	int balFac(Node *n); // Returns Balance factor of a node
	void setHeight(Node *n); //Sets the height of a node based on children's heights
	Node *insert(int x); //Recursively inserts a node into the tree based on numerical rating
	Node *insert(int x, Node *n);
	Node *balance(Node *n); //Performs rotations to balance the tree
	Node *rotateRight(Node *n); //Performs a right rotation
	Node *rotateLeft(Node *n); //Performs left rotations
	bool search(string x); //Recursively searches a tree for a given movie title
	bool search(Node *n, string x);
	void printTreeio(); //Recursively prints tree in order
	void printTreeio(Node *n);
	void printTreePre(); //Recursively prints tree in pre order
	void printTreePre(Node *n);
	void printTreePost(); //Recursively prints tree in post order
	void printTreePost(Node *n);

};



#endif /* BST_HPP_ */
