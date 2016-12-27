/*
 * movieRecs.hpp

 * Matt Meyers
 * Lab Section 40
 * TA: Leighanne Hsu
 */

#ifndef MOVIERECS_HPP_
#define MOVIERECS_HPP_

#include "BST.hpp"
#include "DLL.hpp"
#include <stdlib.h>
#include <string>
using namespace std;

class movieRecs{
	BST *database;
	DLL *recommendations; //recommended movies based on ratings
	DLL *userRatings; //List of movies to be rated
public:
	movieRecs(string infile);
	~movieRecs();
	void loadDatabase(string movieFile); //Parses movie txt files and creates AVL tree
	void start(); //Controls program that recommends movies or lets user search database
	void searchOption(); //Searching part of program.  Users can search for movies based on different parameters
	void RecOption(); //Recommendation part of program.
	DLL *getStartMovies(); //pulls initial movies from database for user to rate
	DLL *getRecommendations(); //Gets recommendations based on ratings
};


#endif /* MOVIERECS_HPP_ */
