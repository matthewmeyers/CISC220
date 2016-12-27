/*
 * Game.cpp

 * Matt Meyers
 * Lab Section 40
 * TA: Leighanne Hsu
 */

#include "Game.hpp"
#include "BSTB.hpp"
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Game::Game() {
}
/*Constructor
 *
 * Parameters:	string infile (dictionary file)
 */
Game::Game(string infile) {
	dict = new BSTB();
	readTreeFromFile(infile);
	numLetters = 0;
	totalWords = 0;
	wordList = new BSTB();
	numRight = 0;
}
/* Controls the game, continues until user chooses to not continue
 *
 * No parameters or return
 */
void Game::startGame() {
	while (true) {
		cout << "Enter the number of letters you want to play with: ";
		cin >> numLetters;
		currLetters = getLetters(numLetters);
		cout << "Your available letters are:" << endl << endl;
		for (int i = 0; i < numLetters; i++) {
			cout << currLetters[i] << " ";
		}//for
		cout << endl << endl;
		getWords();
		cout << endl << "Eligible words: " << endl;
		wordList->printTreeio();
		checkWordsForScore(wordList->root);
		cout << endl << "Player Score: " << 3 * numRight - 6 * (totalWords - numRight)<< endl;
		cout << "Continue playing? (y/n)" << endl;
		string uInput;
		cin >> uInput;
		if(uInput == "n"){
			break;
		}else{
			totalWords = 0;
			numLetters = 0;
			wordList = new BSTB();
			numRight = 0;

		}//if ==n
	}
}
/* Reads a .txt files and puts the words into an AVL tree
 *
 * Parameters:	string dictfile (.txt filename)
 * no return
 */
void Game::readTreeFromFile(string dictfile) {
	dict = new BSTB();
	ifstream file(dictfile.c_str());
	string word;
	while (!file.eof()) {
		file >> word;
		if (!file.eof()) {
			dict->insert(word);
			//dict->printTreeio();
		}
	}
	/*
	 cout << "Print io" << endl;
	 dict->printTreeio();
	 cout << endl << "Print pre" << endl;
	 dict->printTreePre();
	 cout << endl << "Print post" << endl;
	 dict->printTreePost();
	 */

}
/*Generates an array of random letters based on a number given by the user.
 * 1 to numLetters-floor(numLetters/2) guarenteed vowels.
 *
 * Parameters:	int x (number of letters)
 * returns array of characters
 */
char * Game::getLetters(int x) {
	char cons[26] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k',
			'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x',
			'y', 'z' };
	char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
	char *letters = new char[x];
	int y = rand()%(x-x/2) +1;
	for(int i = 0; i < y; i++){
		letters[i] = vowels[rand()%5];
	}//for vowels
	for (int i = y; i < x; i++) {
		letters[i] = cons[rand() % 21];
	}//for consonants
	return letters;
}
/*Lets the user input words and continues until -1 is entered.
 * Words checked to guarantee letters used are in the random list.
 *
 * no parameters or return
 */
void Game::getWords() {
	string uInput;
	cout << "Enter a word using the above letters or enter -1 when finished."<< endl;
	while (true) {
		cin >> uInput;
		if (uInput == "-1") {
			break;
		} else {
			if (checkWLetters(uInput)) {
				wordList->insert(uInput);
				totalWords++;
			}//if checkWLetters
		}//if uInput
	}//while
	return;
}
/*Ensures letters in given string are in generated array of letters
 *
 * parameters:	string s (string in question)
 * returns true if string is acceptable, false otherwise
 */
bool Game::checkWLetters(string s) {
	int size = s.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < numLetters; j++) {
			if (s[i] == currLetters[j]) {
				break;
			}//if
			if (j == numLetters - 1) {
				return false;
			}//if
		}//for j
	}//for i
	return true;
}
/*Recursively checks if words are in the dictionary
 *
 * Parameters:	NodeTB n (root of subtree)
 * no return
 */
void Game::checkWordsForScore(NodeTB *n) {
	if (n == NULL) {
		return;
	}
	checkWordsForScore(n->left);
	if (dict->search(n->word)) {
		numRight++;
	}
	checkWordsForScore(n->right);
	return;
}

