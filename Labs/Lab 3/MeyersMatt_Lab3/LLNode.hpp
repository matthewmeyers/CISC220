/*
 * LLNode.hpp

 *
 * Matt Meyers
 * Lab Section 040
 * TA: Leighanne Hsu
 */

#ifndef LLNODE_HPP_
#define LLNODE_HPP_
#include <stdlib.h>
#include <string>
using namespace std;

class LLNode{
	friend class LLPQ;
	friend class LLHuff;
	char data;
	int freq;
	string code;
	LLNode *next;
	LLNode *prev;
	LLNode *right;
	LLNode *left;
public:
	LLNode(char c, string co);
	~LLNode();
	char getData();
};



#endif /* LLNODE_HPP_ */
