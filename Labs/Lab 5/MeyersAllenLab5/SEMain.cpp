/*
 * SEMain.cpp

 *Matt Meyers
 *Eric Allen
 *TA: Leighanne Hsu
 *Lab sections 40(MM) and 41(EA)
 */

#include "Document.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	cout << "hi" << endl;
	// Testing Insertion Sort
	cout << "TESTING INSERTION SORT" << endl;
	Document doc1("Monet.txt");
	doc1.readFile();
	doc1.pickSort(0);

	// Testing Quicksort
	cout << "TESTING QUICKSORT" << endl;
	Document doc2("Monet.txt");
	doc2.readFile();
	doc2.pickSort(1);


	// Testing Heapsort
	cout << "TESTING HEAPSORT" << endl;
	Document doc3("Monet.txt");
	doc3.readFile();
	doc3.pickSort(2);

	return 0;
}

