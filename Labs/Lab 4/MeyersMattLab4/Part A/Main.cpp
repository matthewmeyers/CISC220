/*
 * Main.cpp

 * Matt Meyers
 * Lab Section 40
 * TA: Leighanne Hsu
 */

#include "Game.hpp"
#include "BSTB.hpp"
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

int main(){
	srand(time(NULL));
	cout << "Loading Dictionary..." << endl;
	Game *g1 = new Game("dict.txt");
	g1->startGame();
	return 0;
}


