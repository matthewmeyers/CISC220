/*
 * LLHuff.cpp

 *
 * Matt Meyers
 * Lab Section 040
 * TA: Leighanne Hsu
 */

#include "LLHuff.hpp"
#include "LLNode.hpp"
#include "LLPQ.hpp"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

LLHuff::LLHuff(string f) {
	file = f;
	root = NULL;
	size = 0;
	pq = new LLPQ();
	ascii = new LLPQ();
}

LLHuff::~LLHuff() {
	delete root;
}

/* Turns a priority queue into a tree based on character frequency
 *
 * No parameters
 * No return
 */
void LLHuff::makeHuff() {
	pq->sortLL();
	while (true) {
		if (pq->size == 2) {
			LLNode *node = new LLNode('*', "");
			node->left = pq->first;
			node->left->code = "0";
			node->right = pq->last;
			node->right->code = "1";
			node->freq = pq->first->freq + pq->last->freq;
			root = node;
			break;

		} //if
		LLNode *tmp1 = pq->remFirst();
		LLNode *tmp2 = pq->remFirst();
		LLNode *node = new LLNode('*', "");

		node->left = tmp1;
		node->left->code = "0";
		node->right = tmp2;
		node->right->code = "1";
		node->freq = tmp1->freq + tmp2->freq;

		pq->insertInOrder(node);

	} //while
	pq = new LLPQ();
	findCode(root, "");
	return;

}

/* Recursively traverses the tree to assign a code to each node.
 * 0 refers to moving left, 1 is moving right.  The codes are then
 * put into a linked list.
 *
 * Parameters:	LLNode rootNode-root of the subtree
 * 				string path-path taken to get to current node
 * No return
 */
void LLHuff::findCode(LLNode *rootNode, string path) {
	if (rootNode == NULL) {
		return;
	}//if

	rootNode->code = path + rootNode->code;
	if (rootNode->code == "") {
		pq->addFirst(rootNode->data, rootNode->code);
	} else {
		pq->addAtFirst(rootNode->data, rootNode->code);
	}//if
	findCode(rootNode->left, rootNode->code);
	findCode(rootNode->right, rootNode->code);
	return;
}

/* Reads a .txt file and creates a linked list of the characters
 *
 * No Parameters
 * No return
 */
void LLHuff::readFile() {
	ifstream infile(file.c_str(), ios::in);
	char k;
	while (infile.get(k)) {
		pq->insertUnique(k);
	}//while
	infile.close();
}

/* Reads the ascii file and prints the compressed version of a .txt
 * file to a .txt file.
 *
 * No Parameter
 * No Return
 */
void LLHuff::readAscii() {
	cout << file << endl;
	ifstream infile("asciitable.txt", ios::in); // open file
	char ch;
	string asciicode;
	if (!infile.is_open()) {
		return;
	}//if
	infile >> asciicode;
	ascii->addFirst(' ', asciicode);
	infile >> asciicode;
	while (infile >> ch) { // loop getting single characters
		cout << ch;
		infile >> asciicode; // gets entire word (code)
		cout << asciicode << endl;
		ascii->addAtFirst(ch, asciicode);
	}//while
	cout << endl;
	infile.close();
/////////////////////////////////////
	ifstream infile2(file.c_str(), ios::in); // open file for reading
	ofstream outfile("asciivsn.txt", ios::out);
	char k;
	string comp;
	while (infile2.get(k)) { // loop getting single characters
		cout << k;
		comp = ascii->findCode(k);
		if (comp == "") {
			cout << "ERROR WITH " << k << endl;
		} else {
			cout << k << ":" << comp << endl;
			outfile << comp << " ";
		}//if
	}//while
	cout << endl;
	infile2.close();
	outfile.close();
}

/* Reads a .txt file and prints the code for each character to a
 * .txt file
 *
 * No Parameters
 * No Return
 */
void LLHuff::compressFile() {
	ifstream infile(file.c_str(), ios::in);
	ofstream outfile("compressed.txt", ios::out);
	char k;
	while (infile.get(k)) {
		cout << "Printing code: " << pq->findCode(k) << endl;
		outfile << pq->findCode(k) << " ";
	}//while
	infile.close();
	outfile.close();
}
