/*
 * LLHuff.hpp

 *
 * Matt Meyers
 * Lab Section 040
 * TA: Leighanne Hsu
 */

#ifndef LLHUFF_HPP_
#define LLHUFF_HPP_

#include "LLNode.hpp"
#include "LLPQ.hpp"
#include <stdlib.h>
#include <string>
using namespace std;

class LLHuff{
	string file;
	LLNode *root;
	int size;
public:
	LLPQ *pq;
	LLPQ *ascii;
	LLHuff(string f);
	~LLHuff();
	void makeHuff();
	void findCode(LLNode *root, string path);
	void readFile();
	void compressFile();
	void readAscii();

};



#endif /* LLHUFF_HPP_ */
