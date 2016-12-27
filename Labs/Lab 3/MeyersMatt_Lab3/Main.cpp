/*
 * Main.cpp

 *
 * Matt Meyers
 * Lab Section 040
 * TA: Leighanne Hsu
 */

#include <stdio.h>
#include <iostream>
#include "LLNode.hpp"
#include "LLHuff.hpp"
using namespace std;
int main() {
	cout << "reading file" << endl;
	LLHuff code("test.txt");
	code.readFile();
	code.pq->printLLPQ();
	code.pq->sortLL();
	code.pq->printLLPQ();
	code.makeHuff();
	code.compressFile();
	code.readAscii();
	return 0;
}
