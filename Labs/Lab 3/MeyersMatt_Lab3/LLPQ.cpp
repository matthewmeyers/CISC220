/*
 * LLPQ.cpp

 *
 * Matt Meyers
 * Lab Section 040
 * TA: Leighanne Hsu
 */

#include "LLPQ.hpp"
#include "LLNode.hpp"
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

/*LLPQ Constructor*/
LLPQ::LLPQ() {
	first = NULL;
	last = NULL;
	size = 0;
}

/*LLPQ Destructor*/
LLPQ::~LLPQ() {
	LLNode *tmp = first;
	while (first != NULL) {
		tmp = first->next;
		delete first;
		first = tmp;
		size--;
	}
	first = NULL;
}

/* Prints the data held in the nodes of a linked list
 *
 * No Parameters
 * No Return
 */
void LLPQ::printLLPQ() {
	LLNode *tmp = first;
	while (tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp->next;
	}//while
	cout << endl;
	return;
}

/* Adds the first node to a NULL linked list
 *
 * No Parameters
 * No Return
 */
void LLPQ::addFirst(char x, string co) {
	LLNode *node = new LLNode(x, co);
	first = node;
	last = node;
	size++;
	return;
}

/* Adds a new node to the front of a linked list
 *
 * No Parameters
 * No Return
 */
void LLPQ::addAtFirst(char x, string co) {
	LLNode *node = new LLNode(x, co);
	node->next = first;
	first->prev = node;
	first = node;
	size++;
	return;
}

/* Removes the first node of a linked list
 *
 * No Parameters
 * Returns a pointer to the removed node
 */
LLNode *LLPQ::remFirst() {
	LLNode *tmp = first;
	tmp->next->prev = NULL;
	first = tmp->next;
	size--;
	return tmp;
}

/* Finds the Huffman code of a given character
 *
 * Parameter: char k-character in question
 * Returns the huffman code of the character
 */
string LLPQ::findCode(char k) {
	LLNode *tmp = first;
	while (tmp != NULL) {
		if (tmp->data == k) {
			return tmp->code;
		}//if
		tmp = tmp->next;
	}//while
	return "";
}

/* Sorts a linked list by the frequency using a bubble sort
 *
 * No Parameters
 * No Return
 */
void LLPQ::sortLL() {
	if (size == 0) {
		return;
	}//if
	bool swap = true;
	while (swap) {
		swap = false;
		LLNode *tmp = first;
		for (int i = 0; i < size - 1; i++) {
			tmp = tmp->next;
			if (tmp->freq < tmp->prev->freq) {
				int tmpNum = tmp->freq;
				char tmpData = tmp->data;
				string tmpCode = tmp->code;

				tmp->freq = tmp->prev->freq;
				tmp->data = tmp->prev->data;
				tmp->code = tmp->prev->code;

				tmp->prev->freq = tmpNum;
				tmp->prev->data = tmpData;
				tmp->prev->code = tmpCode;
				swap = true;
			}//if
		}//for
	}//while
	return;
}

/* Increases the frequency of a node if the passed character is
 * already in the linked list. Creates a new node if the character
 * is not in the list.
 *
 * Parameters: char c-character in question
 * No Return
 */
void LLPQ::insertUnique(char c) {
	if(size == 0){
		addFirst(c,"");
		return;
	}//if
	LLNode *tmp = first;
	while(tmp != NULL){
		if (tmp->data == c){
			tmp->freq ++;
			return;
		}//if
		tmp = tmp->next;
	}//while
	addAtFirst(c);
	return;
}

/* Inserts a node so that the linked list remains sorted
 *
 * Parameters: LLNode *n-node being inserted
 * No Return
 */
void LLPQ::insertInOrder(LLNode *n) {
	sortLL();
	LLNode *tmp = first;
	while(tmp != NULL){
		if(n->freq < tmp->freq){
			n->prev = tmp->prev;
			n->next = tmp;
			tmp->prev->next = n;
			tmp->prev = n;
			size++;
			return;
		}//if
		tmp=tmp->next;
	}//while
	n->prev = last;
	n->next = NULL;
	last->next = n;
	last = n;
	size++;
	return;
}

