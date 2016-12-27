/*
 * lab2lottery.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: Matthew
 */

#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
#include "lab2lottery.hpp"

/*Creates a new owner object with a random number of stores.
 * Stores are contained in a one dimensional array.
 *
 * No parameters
 * Returns the address of the owner object
 */
Owner * makeOwner(){
	Owner * owner = new Owner();
	//Initializing attributes
	owner->numStores = rand()%10+1;
	owner->stores = new Store[owner->numStores];
	owner->totalSold = 0;
	for(int i = 0;i<3;i++){
		owner->totalWinners[i] = 0;
	}

	for(int i = 0; i < owner->numStores; i++){
		owner->stores[i] = makeStore();
		owner->totalSold += owner->stores[i].numSold;
	}
	return owner;
}

/*Creates a store object with a random storeID and  number of customers.
 * Customers are held in a one dimensional array.
 *
 * no parameters
 * returns the store object
 */
Store makeStore(){
	Store store;
	store.storeID = rand()%100 + 1;
	store.numCust = rand()%10 + 1;
	store.numSold = 0;
	for(int i=0;i<3;i++){
		store.numWinners[i]=0;
	}
	store.customerList = new Customer[store.numCust];
	for(int i = 0; i < store.numCust; i++){
		store.customerList[i] = makeCustomer();
		store.numSold += store.customerList[i].numTickets;
	}
	return store;
}

/* creates a customer object with a random ID and number of tickets.
 * Lottery numbers are three unique integers.  All lottery tickets
 * held in an array.
 *
 * no parameters
 * returns the customer object
 */
Customer makeCustomer(){
	Customer customer;
	customer.customerID = rand()%1000+1;
	customer.numTickets = rand()%20+1;
	customer.lotteryNums = new int*[customer.numTickets];
	for (int i = 0; i < customer.numTickets; i++){
		customer.lotteryNums[i] = new int[3];
		int a, b, c;
		do{
			a = rand()%10;
			b = rand()%10;
			c = rand()%10;
		}while((a==b)||(a==c)||(b==c));
		customer.lotteryNums[i][0] = a;
		customer.lotteryNums[i][1] = b;
		customer.lotteryNums[i][2] = c;
	}
	return customer;
}

/*Generates three unique integers that are the winning numbers.
 *
 * Parameters: winners-array of winning numbers
 * no return
 */
void getWinners(int winners[]) {
	for (int i = 0; i < 3; i++) {
		int a, b, c;
		do {
			a = rand() % 10;
			b = rand() % 10;
			c = rand() % 10;
		} while ((a == b) || (a == c) || (b == c));
		winners[0] = a;
		winners[1] = b;
		winners[2] = c;
	}
}
 /* Finds which lottery tickets have winning numbers and prints the number
  * along with how many matches there are.  Also prints the total number of matches for
  * each store and the total for the owner.
  *
  * Parameters: owner-owner object
  * 			ls-list of winning numbers
  * no return
  */
void findWinners(Owner *owner, int *ls){
	cout << "Total lottery tickets sold: " << owner->totalSold << endl;
	cout << "Winning numbers: " << ls[0] << ls[1] << ls[2] << endl;
	for(int i = 0; i < owner->numStores; i++){
		cout << "Store: " << owner->stores[i].storeID << endl;
		for (int j = 0; j < owner->stores[i].numCust; j++){
			cout << "\t Customer: " << owner->stores[i].customerList[j].customerID << endl;
			for(int k = 0; k < owner->stores[i].customerList[j].numTickets; k++){
				int matches = checkwin(owner->stores[i].customerList[j].lotteryNums[k], ls);
				if (matches == 1){
					owner->totalWinners[0] += 1;
					owner->stores[i].numWinners[0] += 1;
				}else if(matches == 2){
					owner->totalWinners[1] += 1;
					owner->stores[i].numWinners[1] += 1;
				}else if (matches == 3){
					owner->totalWinners[2] += 1;
					owner->stores[i].numWinners[2] += 1;
				}
				cout << "\t \t ticket: " << owner->stores[i].customerList[j].lotteryNums[k][0]<<owner->stores[i].customerList[j].lotteryNums[k][1]<<owner->stores[i].customerList[j].lotteryNums[k][2]<< "\t Matched: " << matches << endl;
			}

		}
		cout << "\t Total winners for store " << owner->stores[i].storeID <<": "<<owner->stores[i].numWinners[0]<<" "<<owner->stores[i].numWinners[1]<<" "<<owner->stores[i].numWinners[2]<<endl;
	}
}

/*Compares a given list of numbers to the winning numbers and finds how many match.
 *
 * Parameters: nums-list of integers, customer's numbers
 * 			   winners-list of winning numbers
 * Returns the number of matches
 */
int checkwin(int *nums, int *winners){
	int num = 0;
	for(int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if(nums[i] == winners[j]){
				num +=1;
			}
		}
	}
	return num;
}



