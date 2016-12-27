/*
 * Game.hpp

 * Matt Meyers
 * Lab Section 40
 * TA: Leighanne Hsu
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "BSTB.hpp"
#include <stdlib.h>
#include <string>
using namespace std;

class Game{
	friend class BSTB;
	BSTB *dict;
	int numLetters;
	char *currLetters;
	int totalWords;
	BSTB *wordList;
	int numRight;
public:
	Game();
	Game(string infile);
	void startGame();
	void readTreeFromFile(string dictFile);
	char * getLetters(int x);
	void getWords();
	bool checkWLetters(string s);
	void checkWordsForScore(NodeTB *n);
};



#endif /* GAME_HPP_ */
