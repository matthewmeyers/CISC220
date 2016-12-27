/*
 * BSTB.hpp
 *
 * Matt Meyers
 * Lab Section 40
 * TA: Leighanne Hsu
 */

#ifndef BSTB_HPP_
#define BSTB_HPP_

#include "NodeTB.hpp"
#include <stdlib.h>
#include <string>
using namespace std;

class BSTB {
	friend class Game;
	NodeTB *root;
	int count;
public:
	BSTB();
	~BSTB();
	int getHeight(NodeTB *n);
	int balFac(NodeTB *n);
	void setHeight(NodeTB *n);
	NodeTB *insert(string x);
	NodeTB *insert(string x, NodeTB *n);
	NodeTB *balance(NodeTB *n);
	NodeTB *rotateRight(NodeTB *n);
	NodeTB *rotateLeft(NodeTB *n);
	void printTreeio();
	void printTreeio(NodeTB *n);
	void printTreePre();
	void printTreePre(NodeTB *n);
	void printTreePost();
	void printTreePost(NodeTB *n);
	bool search(string x);
	bool search(NodeTB *n, string x);
};

#endif /* BSTB_HPP_ */
