/*
 * LLPQ.hpp

 *
 * Matt Meyers
 * Lab Section 040
 * TA: Leighanne Hsu
 */

#ifndef LLPQ_HPP_
#define LLPQ_HPP_
#include "LLNode.hpp"
#include <stdlib.h>
#include <string>
using namespace std;

class LLPQ{
	friend class LLHuff;
	LLNode *first;
	LLNode *last;
	int size;
public:
	LLPQ();
	~LLPQ();
	void printLLPQ();
	void addFirst(char x, string co = "");
	void addAtFirst(char x, string co = "");
	LLNode *remFirst();
	string findCode(char k);
	void sortLL();
	void insertUnique(char c);
	void insertInOrder(LLNode *n);
};



#endif /* LLPQ_HPP_ */
