/*
 * lab2main.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: Matthew
 */

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "lab2lottery.hpp"

int main(){
	srand(time(NULL));
	Owner *me = makeOwner();
	int winners[3] = {0,0,0};
	getWinners(winners);
	for(int i = 0; i < 3; i++){
		std::cout << winners[i] << std::endl;
	}
	findWinners(me, winners);
	std::cout << "Won with 1 number: " << me->totalWinners[0] << std::endl;
	std::cout << "Won with 2 number: " << me->totalWinners[1] << std::endl;
	std::cout << "Won with 3 number: " << me->totalWinners[2] << std::endl;
	return 0;
}


