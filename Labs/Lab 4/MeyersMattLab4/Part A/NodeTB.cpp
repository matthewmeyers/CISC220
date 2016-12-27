/*
 * NodeTB.cpp

 * Matt Meyers
 * Lab Section 40
 * TA: Leighanne Hsu
 */

#include "NodeTB.hpp"
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

NodeTB::NodeTB(string x){
	left = NULL;
	right = NULL;
	word = x;
	height = 1;
}

NodeTB::~NodeTB(){
	if (left != NULL || right != NULL) {
			cout << "deleting this LLNode may cause a memory leak" << endl;
	}
}
