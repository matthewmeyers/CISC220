/*
 * lab2lottery.hpp
 *
 *  Created on: Sep 21, 2016
 *      Author: Matthew
 */

#ifndef LAB2LOTTERY_HPP_
#define LAB2LOTTERY_HPP_

struct Customer{
	int customerID;
	int numTickets;
	int ** lotteryNums;
};

struct Store{
	int storeID;
	int numCust;
	Customer * customerList;
	int numSold;
	int numWinners[3];
};

struct Owner{
	Store * stores;
	int numStores;
	int totalSold;
	int totalWinners[3];
};

Owner * makeOwner();
Store makeStore();
Customer makeCustomer();
void getWinners (int winners[]);
void findWinners(Owner *owner, int *ls);
int checkwin(int *nums, int *winners);

#endif /* LAB2LOTTERY_HPP_ */
