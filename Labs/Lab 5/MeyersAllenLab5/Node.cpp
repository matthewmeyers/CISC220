/*
 * Node.cpp

 *Matt Meyers
 *Eric Allen
 *TA: Leighanne Hsu
 *Lab sections 40(MM) and 41(EA)
 */

#include "Node.hpp"
#include <iostream>
#include <string>
using namespace std;

Node::Node(string s) {
	count = 1;
	next = NULL;
	prev = NULL;
	word = s;
}
Node::Node() {
	count = 1;
	next = NULL;
	prev = NULL;
	word = "";
}


