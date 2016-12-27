/*
 * LLNode.cpp

 *
 * Matt Meyers
 * Lab Section 040
 * TA: Leighanne Hsu
 */

#include "LLNode.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;


LLNode::LLNode(char c, string co) {
	data = c;
	freq = 1;
	code = co;
	next = NULL;
	prev = NULL;
	right = NULL;
	left = NULL;
}

LLNode::~LLNode() {
	if (next != NULL) {
		cout << "deleting this LLNode may cause a memory leak" << endl;
	}
}

char LLNode::getData(){
	return data;
}

