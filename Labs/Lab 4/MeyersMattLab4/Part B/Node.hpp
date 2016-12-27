/*
 * Node.hpp

 * Matt Meyers
 * Lab Section 40
 * TA: Leighanne Hsu
 */

#ifndef NODE_HPP_
#define NODE_HPP_

#include <stdlib.h>
#include <string>
using namespace std;

/*Nodes that can be used for linked lists or AVL trees
 *
 */
class Node{
	friend class BST;
	Node *left;
	Node *right;
	int height;
	int rating;
	int year;
	string title;
	string genre;
	string *actors;
public:
	Node(string title, string genre, int rating);
	~Node();
};


#endif /* NODE_HPP_ */
