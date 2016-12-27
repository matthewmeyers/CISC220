/*
 * lab3main.cpp
 * Matt Meyers
 * Eric Allen
 * Marisa Pugliese
 * John Pae
 *
 *  Created on: Feb 26, 2015
 *      Author: Debra
 */

//#include <iostream>
//#include <stdlib.h>
#include "SLL.hpp"
#include "SNode.hpp"
#include "DLL.hpp"
#include "DNode.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	/*
	 cout << "SLL" << endl;
	 // Testing SLL
	 SLL *list = new SLL;
	 list->addFirst(rand()%50);
	 list->printSLL();
	 for (int i = 0; i < 10; i++) {
	 if (i == 5) {
	 list->push(42);
	 i++;
	 }
	 else {
	 list->push(rand()%50);
	 }
	 list->printSLL();
	 }
	 SNode *s = list->findKth(6);
	 int y = s->getData();
	 cout << y << endl;
	 int x = list->findK(42);
	 cout << x << endl;
	 list->addAtK(55,4);
	 list->printSLL();
	 list->addAtK(60,0);
	 list->printSLL();
	 x = list->pop();
	 cout << x << endl;
	 list->printSLL();
	 x = list->pop();
	 cout << x << endl;
	 list->printSLL();
	 x = list->remFirst();
	 cout << x << endl;
	 list->printSLL();
	 x = list->remFirst();
	 cout << x << endl;
	 list->printSLL();
	 x = list->remKth(3);
	 cout << x << endl;
	 list->printSLL();
	 x = list->remKth(4);
	 cout << x << endl;
	 list->printSLL();

	 SLL *l2 = new SLL;
	 l2->addFirst(rand()%50);
	 for (int i = 0; i < 10; i++) {
	 l2->push(rand()%50);
	 }
	 l2->printSLL();
	 cout << endl;
	 list->join(l2);
	 list->printSLL();

	 //Testing DLL
	 cout << "DLL" << endl << endl;
	 DLL *listd = new DLL;
	 listd->addFirst(rand()%50);
	 listd->printDLL();
	 for (int i = 0; i < 8; i++) {
	 if (i == 4) {
	 listd->push(42);
	 i++;
	 }
	 else {
	 listd->push(rand()%50);
	 }
	 listd->printDLL();
	 }
	 DNode *s2 = listd->findKth(6);
	 int y2 = s2->getData();
	 cout << y2 << endl;
	 int x2 = listd->findK(42);
	 cout << x2 << endl;
	 listd->addAtK(55,4);
	 listd->printDLL();
	 listd->addAtK(60,0);
	 listd->printDLL();
	 x2 = listd->pop();
	 cout << x2 << endl;
	 listd->printDLL();
	 x2 = listd->pop();
	 cout << x2 << endl;
	 listd->printDLL();
	 x2 = listd->remFirst();
	 cout << x2 << endl;
	 listd->printDLL();
	 x2 = listd->remFirst();
	 cout << x2 << endl;
	 listd->printDLL();
	 x2 = listd->remKth(3);
	 cout << x2 << endl;
	 listd->printDLL();
	 x2 = listd->remKth(4);
	 cout << x2 << endl;
	 listd->printDLL();
	 DLL *ld2 = new DLL;
	 ld2->addFirst(rand()%50);
	 for (int i = 0; i < 8; i++) {
	 ld2->push(rand()%50);
	 }
	 ld2->printDLL();
	 cout << endl;
	 listd->join(ld2);
	 listd->printDLL();
	 listd->printRevDLL();

	 DLL *list1 = new DLL;
	 list1->addFirst(rand()%50);
	 list1->printDLL();
	 for (int i = 0; i < 8; i++) {
	 if (i == 4) {
	 list1->push(42);
	 i++;
	 }
	 else {
	 list1->push(rand()%50);
	 }
	 }
	 list1->printDLL();
	 list1->sortDLL();
	 list1->printDLL();

	 DLL *list2 = new DLL;
	 list2->addFirst(rand()%50);
	 list2->printDLL();
	 for (int i = 0; i < 8; i++) {
	 if (i == 4) {
	 list2->push(42);
	 i++;
	 }
	 else {
	 list2->push(rand()%50);
	 }
	 }
	 list2->printDLL();
	 list2->sortDLL();
	 list2->printDLL();
	 list1->Merge2(list2);
	 list1->printDLL();
	 */

// Testing SLL
	cout << "Testing SLL" << endl;
	// Testing adds and removes
	cout << "Testing Add/Remove functions" << endl;
	SLL *slist = new SLL;
	cout << "addFirst and a few pushes" << endl;
	slist->addFirst(5);
	slist->push(2);
	slist->push(7);
	slist->push(9);
	slist->push(1);
	slist->printSLL();
	cout << endl << "addAtFront and addAtK, k=1" << endl;
	slist->addAtFront(3);
	slist->addAtK(4, 1);
	slist->printSLL();
	cout << endl << "addAtK, k=0" << endl;
	slist->addAtK(5, 0);
	slist->printSLL();

	cout << endl << "remFirst, pop, remKth, k=1" << endl;
	int x = slist->remFirst();
	cout << "Removed Data = " << x << endl;
	slist->printSLL();
	x = slist->pop();
	cout << "Popped Data = " << x << endl;
	slist->printSLL();
	x = slist->remKth(1);
	cout << "Removed Data = " << x << endl;
	slist->printSLL();

	cout << endl << "Testing other functions" << endl;
	cout << "reverseList" << endl;
	slist->reverseList();
	slist->printSLL();
	SLL *slist2 = new SLL;
	slist2->addFirst(12);
	slist2->push(15);
	cout << endl << "Join with 12->15->" << endl;
	slist->join(slist2);
	slist->printSLL();
	cout << endl << "findK" << endl;
	cout << "Position of 7 is " << slist->findK(7) << endl;

// Testing DLL
	cout << endl << "Testing DLL" << endl;
	cout << "addFirst, addAtFront, pushes, addAtK=1" << endl;
	DLL *dlist = new DLL;
	dlist->addFirst(6);
	dlist->addAtFront(7);
	dlist->push(1);
	dlist->push(4);
	dlist->push(4);
	dlist->addAtK(3, 1);
	dlist->printDLL();
	cout<<endl<<"sortDLL"<<endl;
	dlist->sortDLL();
	dlist->printDLL();
	cout <<endl<< "Printing in reverse" << endl;
	dlist->printRevDLL();
	cout <<endl<< "Recursively reversing list" << endl;
	dlist->RecursiveReverse(dlist);
	dlist->printDLL();
	cout<<endl<<"RemoveDuplicates"<<endl;
	dlist->RemoveDuplicates();
	dlist->printDLL();

	DLL *dlist2 = new DLL;
	dlist2->addFirst(5);
	dlist2->push(2);
	dlist->join(dlist2);
	cout<<endl<<"join with 5->2->"<<endl;
	dlist->printDLL();
	cout<<endl<<"pop, remFirst, remKth=1"<<endl;
	int y = dlist->pop();
	cout << "Popped data: " << y << endl;
	dlist->printDLL();
	y = dlist->remFirst();
	cout << "First data removed: " << y << endl;
	dlist->printDLL();
	y = dlist->remKth(1);
	cout << "2nd data removed: " << y << endl;
	dlist->printDLL();
	y = dlist->findK(1);

	DLL *dlist3 = new DLL;
	dlist3->addFirst(4);
	dlist3->push(2);
	dlist3->push(7);
	cout<<endl<<"Merging with 4->2->7->"<<endl;
	dlist->Merge2(dlist3);
	dlist->printDLL();

}

