/*
 * NodeTB.hpp

 * Matt Meyers
 * Lab Section 40
 * TA: Leighanne Hsu
 */

#ifndef NODETB_HPP_
#define NODETB_HPP_
#include <stdlib.h>
#include <string>
using namespace std;

class NodeTB{
	friend class BSTB;
	friend class Game;
	NodeTB *left;
	NodeTB *right;
	string word;
	int height;
public:
	NodeTB(string x);
	~NodeTB();
};



#endif /* NODETB_HPP_ */
