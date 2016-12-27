/*
 * Document.cpp

 *Matt Meyers
 *Eric Allen
 *TA: Leighanne Hsu
 *Lab sections 40(MM) and 41(EA)
 */

#include "Document.hpp"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
//#include <chrono>
using namespace std;

Document::Document(string f) {
	filename = f;
	wordlist = new LLSE();
}
string Document::strip(string w){
	int x = strlen(w.c_str());
	string neww="";
	//cout << w << ":" << x << endl;
	char punct[] = {'!', '.', ',',':', ';','\'','"','(',')'};
	for (int i = 0; i < x; i++) {
		bool flag = false;
		for (int j = 0; j < 9; j++) {
			if (w[i] == punct[j]) {
				flag = true;
				j = 9;
			}
		}
		if (!flag) {
			neww += tolower(w[i]);
		}
	}
	return neww;
}
bool Document::checkFunctionWords(string w) {
	int i = 0;
	while (i< fwlen && w != fw[i] ) {
		i++;
	}
	if (i != fwlen) {
		return true;
	}
	return false;
}
void Document::pickSort(int i) {  // 0 = insertionSort, 1 = QuickSort, 2= heapSort
    if (i == 0) {
    	wordlist->insertionSortLL();
    	wordlist->printLL();
    	cout << endl;
    }
    else if (i == 1) {
    	wordlist->wordarr= wordlist->convertToArray();
    	wordlist->quickSort(0,wordlist->size-1);
    	for(int i = 0; i < wordlist->size; i++){
    		cout << wordlist->wordarr[i].count << ": " << wordlist->wordarr[i].word << endl;
    	}
    	cout << endl;
    }
    else if (i == 2) {
    	wordlist->heapSort();
    	for(int i = 0; i < wordlist->size; i++){
   			cout << wordlist->wordarr[i].count << ": " << wordlist->wordarr[i].word << endl;
    	}
    	cout << endl;
    }

}
void Document::readFile() {
	//cout << filename << endl;
	ifstream infile(filename.c_str(),ios::in);     // open file
	if (!infile.is_open()) {
		return;
	}
	string word;
	while (infile>>word) {          // loop getting single characters
		word = strip(word);
		if (!checkFunctionWords(word)) {
			//cout << word << " is valid " << endl;
			wordlist->insertUnique(word);
		}
		else {
			//cout << word << " removed" << endl;
		}
	}
	//wordlist->printLL();
}



