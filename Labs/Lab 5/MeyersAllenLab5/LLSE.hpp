/*
 * LLSE.hpp

 *Matt Meyers
 *Eric Allen
 *TA: Leighanne Hsu
 *Lab sections 40(MM) and 41(EA)
 */

#ifndef LLSE_HPP_
#define LLSE_HPP_


#include "Node.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class LLSE {
	friend class Document;
	Node *first;
	Node *last;
	int size;
	Node *wordarr;

public:
	LLSE();
	~LLSE();
	void printLL();
	void addFirst(string x);
	void addAtFirst(string x);
	void insertUnique(string w);
	void quickSort(int x, int y);
	int partition(int beg,int end);
	Node *convertToArray();
	void insertionSortLL();
	Node *makeHeap();
	void heapSort();
};

#endif /* LLSE_HPP_ */
