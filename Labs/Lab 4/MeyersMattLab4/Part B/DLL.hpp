/*
 * DLL.hpp

 * Matt Meyers
 * Lab Section 40
 * TA: Leighanne Hsu
 */

#ifndef DLL_HPP_
#define DLL_HPP_

#include "Node.hpp"
#include <stdlib.h>
#include <string>
using namespace std;

class DLL {
	Node *first;
	Node *last;
	int size;
public:
	DLL();
	~DLL();
	void printDLL(); //Prints list
	void addFirst(string title, string genre, int rating); //Adds first node
	void addAtFront(string title, string genre, int rating); //Adds node to front of list
	void push(string title, string genre, int rating); //Adds node at end of list
	int pop(); //removes node from end of list
	Node *findKth(int k); //Gives nodes at kth position
	int remFirst(); // removes first node
	int remKth(int k); // removes kth node
	void sortDLL(); //sorts list based on rating
};

#endif /* DLL_HPP_ */
