/*
 * Node.hpp

 *Matt Meyers
 *Eric Allen
 *TA: Leighanne Hsu
 *Lab sections 40(MM) and 41(EA)
 */

#ifndef NODE_HPP_
#define NODE_HPP_

#include <iostream>
#include <string>
using namespace std;

class Node {
	friend class Document;
	friend class LLSE;
	Node *next;
	Node *prev;
	int count;
	string word;
public:
	Node(string w);
	Node();
};



#endif /* NODE_HPP_ */
