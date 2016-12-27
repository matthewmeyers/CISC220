/*
 * LLSE.cpp

 *
 *Matt Meyers
 *Eric Allen
 *TA: Leighanne Hsu
 *Lab sections 40(MM) and 41(EA)
 */

#include "Node.hpp"
#include "LLSE.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

LLSE::LLSE() {
	first = NULL;
	last = NULL;
	size = 0;
}
LLSE::~LLSE() {
	Node *tmp = first;
	for (int i = 0; i < size; i++) {
		tmp = first->next;
		delete first;
		first = tmp;
	}
}

void LLSE::printLL() {
	Node *tmp = first;
	while (tmp != NULL) {
		cout << tmp->count << ":" << tmp->word << endl;
		tmp = tmp->next;
	}
}

void LLSE::addFirst(string w) {
	first = new Node(w);
	last = first;
	size = 1;
}

void LLSE::insertUnique(string w) {
	Node *tmp = first;
	if (tmp == NULL) {
		addFirst(w);
	} else {
		while (tmp != NULL && tmp->word < w) {
			tmp = tmp->next;
		}
		if ((tmp != NULL) && (tmp->word == w)) {
			tmp->count++;
		} else {
			Node *tmp2 = new Node(w);
			if (tmp != NULL) {
				if (tmp->prev != NULL) {
					tmp->prev->next = tmp2;
					tmp2->prev = tmp->prev;
				} else {
					first = tmp2;
				}
				tmp2->next = tmp;
				tmp->prev = tmp2;
			} else {
				last->next = tmp2;
				tmp2->prev = last;
				last = tmp2;
			}
			size++;

		}
	}
}

// Write an insertion Sort on the linked list (not an array, 
// a linked list!
/*Performs an insertion sort on a linked list sorting in increasing order
 *
 * no parameters or return
 */
void LLSE::insertionSortLL() {
	int i, j, currCount;
	string currWord;
	Node *curr = first;
	Node *tmp;
	for (j = 1; j < size; j++) {
		bool atFirst = false;
		curr = curr->next;
		currCount = curr->count;
		currWord = curr->word;
		tmp = curr->prev;
		for (i = j-1; (i >= 0) && (tmp->count > currCount); i--) {
			tmp->next->count = tmp->count;
			tmp->next->word = tmp->word;

			if (tmp->prev != NULL) {
				tmp = tmp->prev;
			}else{
				atFirst = true;
			}//if/else-changing tmp
		}//for-move up smaller values
		if(atFirst == true){
			tmp->count = currCount;
			tmp->word = currWord;
		}else{
			tmp->next->count = currCount;
			tmp->next->word = currWord;
		}//if/else -placing current word/count
	}
	return;
}

// Convert the linked list to an array of nodes and return that array
/*Converts a linked list to an array of nodes
 *
 * returns the array of node objects
 */
Node *LLSE::convertToArray() {
	Node *arr = new Node[size];
	Node *tmp = first;
	for (int i = 0; i < size; i++) {
		arr[i] = *tmp;
		tmp = tmp->next;
	}//for
	return arr;
}

// For the quicksort - the partition
/*Partitioning function for quicksort
 *
 * Parameters:	int beg-beginning of subarray
 * 				int end-end of subarray
 * Returns integer value of the middle of the subarray
 */
int LLSE::partition(int beg, int end) {
	int x = beg;
	int y = end;
	string tmpWord;
	int tmpCount;
	int pivot = wordarr[x].count;
	string pivotWord = wordarr[x++].word;
	while (x <= y) {
		while (wordarr[x].count < pivot)
			x++;
		while (wordarr[y].count > pivot)
			y--;
		if (x <= y) {
			tmpWord = wordarr[x].word;
			tmpCount = wordarr[x].count;
			wordarr[x].word = wordarr[y].word;
			wordarr[x++].count = wordarr[y].count;
			wordarr[y].word = tmpWord;
			wordarr[y--].count = tmpCount;
		}//if
	}//while x<=y
	wordarr[beg].word = wordarr[y].word;
	wordarr[beg].count = wordarr[y].count;
	wordarr[y].count = pivot;
	wordarr[y].word = pivotWord;
	return y;

}

// your recursive quicksort
/*Recursive quicksort, sorts in increasing order
 *
 * Parameters:	int beg-beginning of subarray
 * 				int end-end of subarray
 * No return
 */
void LLSE::quickSort(int beg, int end) {
	int middle = partition(beg, end);
	if (middle - 1 > beg) {
		quickSort(beg, middle - 1);
	}//if
	if (middle + 1 < end) {
		quickSort(middle + 1, end);
	}//if

}

//Take the linked list and create a binary heap
/*Create a heap array from a linked list.
 *
 * No parameters, returns array of nodes (the heap)
 */
Node *LLSE::makeHeap() {
	Node *arr = new Node[size];
	Node *tmp = first;
	for (int i = 0; i < size; i++) {
		arr[i] = *tmp;
		int j = i;

		while (((j+1)/2-1)>=0 && arr[((j + 1) / 2) - 1].count < arr[j].count) {
			int parent = ((j + 1) / 2) - 1; //parent index = ceil(j/2)-1

			string tmpWord = arr[j].word;
			arr[j].word = arr[parent].word;
			arr[parent].word = tmpWord;

			int tmpCount = arr[j].count;
			arr[j].count = arr[parent].count;
			arr[parent].count = tmpCount;

			j = parent;

		}//while
		tmp = tmp->next;
	}//for
	return arr;
}

//Sort the heap array using heapsort
/*Heapsort, sorts heap array in increasing order.
 *
 * no parameters or return
 */
void LLSE::heapSort() {
	wordarr = makeHeap();
	int hSize = size - 1;
	while (hSize > 0) {

		string tmpWord = wordarr[hSize].word;
		int tmpCount = wordarr[hSize].count;

		wordarr[hSize].word = wordarr[0].word;
		wordarr[hSize].count = wordarr[0].count;

		wordarr[0].word = tmpWord;
		wordarr[0].count = tmpCount;

		int j = 0;
		while ((2 * j + 1 < hSize && wordarr[2 * j + 1].count > wordarr[j].count)
				|| (2 * j + 2 < hSize
						&& wordarr[2 * j + 2].count > wordarr[j].count)) {
			int child =
					(wordarr[2 * j + 1].count > wordarr[2 * j + 2].count) ?
							2 * j + 1 : 2 * j + 2; //child to be swapped is max count of two children
			int tmpCount = wordarr[child].count;
			wordarr[child].count = wordarr[j].count;
			wordarr[j].count = tmpCount;

			string tmpWord = wordarr[child].word;
			wordarr[child].word = wordarr[j].word;
			wordarr[j].word = tmpWord;

			j = child;

		}//while child is bigger

		hSize--;
	}//while heap still has elements

}

