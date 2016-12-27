/*
 * lab1.cpp
 *
 * Matt Meyers
 * TA: Leighanne Hsu
 * Lab Section 040
 * Lab1
 *
 */

#include <stdlib.h>
#include<time.h>
#include <iostream>
using namespace std;

void helloWorld();
int collatz1(int n);
void collatz2();
bool orderNumbers(int *n1, int *n2, int *n3);
int sumDivisors(int i, int divisor);
bool isPerfect(int i);
bool orderNumbers2(int &n1, int &n2, int &n3);
void randomArrayFill(int *arr, int size);
void printArray(int *arr, int size);
void reverseArray(int *arr, int size);
int findMin(int *arr, int size);
int sumArray(int *arr, int n);
int * sortArray(int *arr, int size);
int * lowPassFilter(int *arr, int aSize, int wSize);
int *** createMatrix(int ***arr, int &x, int &y, int &z);
void print3DArray(int ***arr, int x, int y, int z);

int main(){
	cout << "Problem 1" << endl;
	helloWorld();
	cout << endl;

	cout << "Problem 2a" << endl;
	string response;
	cout << "Enter a Natural Number: " << endl;
	cin >> response;
	int n = atoi(response.c_str());
	int iterations = collatz1(n);
	cout << "It took " << iterations << " iteration to get to 1." << endl << endl;

	cout << "Problem 2b" << endl;
	collatz2();
	cout << endl;

	cout << "Problem 3" << endl;
	srand(time(NULL));
	int x1 = rand();
	int x2 = rand();
	int x3 = rand();
	cout << x1 << " " << x2 << " " << x3 << endl;
	if (orderNumbers(&x1,&x2,&x3) == false){
		cout << x1 << " " << x2 << " " << x3 << endl;
	}
	cout << endl;

	cout << "Problem 4" << endl;
	for(int i =3; i <= 30; i++){
		if (isPerfect(i) == true){
			cout << i << "  true" << endl;
		}else{
			cout << i << "  false" << endl;
		}
	}
	cout << endl;

	cout << "Problem 5" << endl;
	int y1 = rand();
	int y2 = rand();
	int y3 = rand();
	cout << y1 << " " << y2 << " " << y3 << endl;
	if (orderNumbers2(y1,y2,y3) == false){
		cout << y1 << " " << y2 << " " << y3 << endl;
	}
	cout << endl;

	cout << "Problem 6" << endl;
	int arraySize = rand()%30 + 20;
	int randArr[arraySize];
	randomArrayFill(randArr, arraySize);

	printArray(randArr, arraySize);
	cout << endl;

	cout << "Problem 7" << endl;
	reverseArray(randArr, arraySize);
	printArray(randArr, arraySize);
	cout << endl;

	cout << "Problem 8" << endl;
	cout << findMin(randArr, arraySize) << endl << endl;

	cout << "Problem 9" << endl;
	cout << sumArray(randArr, arraySize-1) << endl << endl;

	cout << "Problem 10" << endl;
	sortArray(&randArr[0],arraySize);
	printArray(randArr, arraySize);
	cout << endl;

	cout << "Problem 11" << endl;
	int arraySize2 = rand()%30 + 20;
	int randArr2[arraySize2];
	int wSize = rand()%5 + 3;
	cout << "Window size: " << wSize << endl;
	randomArrayFill(randArr2, arraySize2);
	printArray(randArr2, arraySize2);
	int *smoothArr = lowPassFilter(randArr2, arraySize2, wSize);
	printArray(smoothArr, arraySize2);
	delete [] smoothArr;
	cout << endl;

	cout << "Problem 12" << endl;
	int ***arr3D = NULL;
	int z1 = -1;
	int z2 = -1;
	int z3 = -1;
	arr3D = createMatrix(arr3D, z1, z2, z3);
	// Deleting 3D array
	for(int i = 0; i < z1; i++){
		for (int j = 0; j < z2; j++){
			delete [] arr3D[i][j];
		}
		delete [] arr3D[i];
	}
	delete [] arr3D;

	return 0;

}
/* Prints out Hello World
 * No parameters
 * No return
 */
void helloWorld(){
	cout << "Hello World!" << endl;
}

/*Performs the Collatz algorithm and counts the number of iterations
 * If the number is even, divide by 2, else triple and add 1.  Continue until number
 * equals 1.
 *
 * Parameters: int n
 * Returns iterations (int)
 */
int collatz1(int n){
	int iterations =  0;
	while (n != 1){
		((n%2) == 0) ? n /= 2 : n=3*n+1;
		iterations += 1;
	}
	return iterations;
}

/*Performs the Collatz Algorithm on the numbers in between the two numbers entered by the user
 * including the lower number and excluding the higher.
 *
 * No parameters
 * No return
 */
void collatz2(){
	string response1;
	string response2;
	cout << "Enter a Natural Number: " << endl;
	cin >> response1;
	int n1 = atoi(response1.c_str());
	cout << "Enter a different Natural Number: " << endl;
	cin >> response2;
	int n2 = atoi(response2.c_str());
	if (n2>n1){
		int y = n1;
		n1=n2;
		n2=y;
	}

	int iterations;
	for (int i = n2; i<n1; i++){
		iterations = collatz1(i);
		if (i != n1-1){
			cout << i << " took " << iterations << " iterations. Collatz Conjecture still working..." << endl;
		}else{
			cout << i << " took " << iterations << " iterations. Collatz Conjecture complete." << endl;
		}
	}
	return;
}

/*Orders three numbers in ascending order
 *
 * Parameters: int n1, int n2, int n3 all passed by pointer
 * Returns: True if numbers already in ascending order, false if not
 */
bool orderNumbers(int *n1, int *n2, int *n3){
	int min = 0;
	int mid = 0;
	int max = 0;
	if ((*n1<=*n2)&&(*n1<=*n3)){
		min = *n1;
		if (*n2<=*n3){
			return true;
		}else{
			mid = *n3;
			max = *n2;
		}
	}else if ((*n2<=*n1)&&(*n2<=*n3)){
		min = *n2;
		if (*n1<=*n3){
			mid = *n1;
			max = *n3;
		}else{
			mid = *n3;
			max = *n1;
		}
	}else if ((*n3<=*n1)&&(*n3<=*n2)){
		min = *n3;
		if (*n1<=*n2){
			mid = *n1;
			max = *n2;
		}else{
			mid = *n2;
			max = *n1;
		}
	}

	*n1 = min;
	*n2 = mid;
	*n3 = max;
	return false;
}
/*Determines if a number is perfect, ie if the sum of the divisors equals the number
 *
 * Parameters: int i
 * Returns: true if a perfect number, false if not
 *
 */
bool isPerfect(int i){
	if(i == sumDivisors(i, i-1)){
		return true;
	}else{
		return false;
	}
}

/*Recursively sums the divisors of a number
 *
 * Parameters: int i, int divisor
 * returns: int sum (sum of the divisors)
 */
int sumDivisors(int i, int divisor){
	if(divisor == 0){
		return 0;
	}else if (i%divisor == 0){
		return divisor + sumDivisors(i, divisor-1);
	}else{
		return sumDivisors(i, divisor-1);
	}
}

/*Orders three numbers in ascending order
 *
 * Parameters: int n1, int n2, int n3 all passed by ref
 * Returns: True if numbers already in ascending order, false if not
 */
bool orderNumbers2(int &n1, int &n2, int &n3){
	int min = 0;
	int mid = 0;
	int max = 0;
	if ((n1<=n2)&&(n1<=n3)){
		min = n1;
		if (n2<=n3){
			return true;
		}else{
			mid = n3;
			max = n2;
		}
	}else if ((n2<=n1)&&(n2<=n3)){
		min = n2;
		if (n1<=n3){
			mid = n1;
			max = n3;
		}else{
			mid = n3;
			max = n1;
		}
	}else if ((n3<=n1)&&(n3<=n2)){
		min = n3;
		if (n1<=n2){
			mid = n1;
			max = n2;
		}else{
			mid = n2;
			max = n1;
		}
	}

	n1 = min;
	n2 = mid;
	n3 = max;
	return false;
}

/*Fills an array with random numbers from -50 to 49
 *
 * Parameters: int *arr (Array of integers), int size (size of array)
 * No return
 */
void randomArrayFill(int *arr, int size){
	for (int i = 0; i < size; i++){
		arr[i] = rand()%100 -50;
	}
}

/*Prints one dimensional array on a single line
 *
 * Parameters: int *arr (array of integers), int size (size of array)
 * no return
 *
 */
void printArray(int *arr, int size){
	for (int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

/*Reverses the order  of a one dimensional array
 *
 * Parameters: int *arr (array of integers), int size
 * no return
 *
 */
void reverseArray(int *arr, int size){
	int y = 0;
	for(int i =0; i < size/2; i++){
		y = arr[i];
		arr[i] = arr[size-1-i];
		arr[size-1-i] = y;
	}
}

/*Finds the minimum value in an array
 *
 * Parameters: int *arr (array of integers), int size
 * Returns: int y (minimum value in the array)
 */
int findMin(int *arr, int size){
	int y = arr[0];
	for (int i = 1; i < size; i++){
		if (arr[i] < y){
			y = arr[i];
		}
	}
	return y;
}

/*Recursively sums the elements of an array
 *
 * Parameters: int *arr (array of integers), int size
 * Returns: Sum of the elements (integer)
 */
int sumArray(int *arr, int n){
	if (n == 0){
		return arr[0];
	}else{
		return arr[n] + sumArray(arr, n-1);
	}
}

/*Sorts the elements of an array in ascending order using an insertion sort
 *
 * Parameters: int *arr (array of integers), int size
 * Returns: int *arr (the sorted array of integers
 */
int * sortArray(int *arr, int size){
	int y = 0;
	int j = 0;
	int numComps = 0;
	for(int i = 1; i < size; i++){
		y = arr[i];
		for(j = i-1; (j >= 0)&&(arr[j]>y); j--){
			arr[j+1] = arr[j];
			numComps += 1;
		}
		arr[j+1] = y;
	}
	cout << numComps << " comparisons made." << endl;
	return arr;
}

/*Smooths a given array with a moving window average
 *
 * Parameters: int *arr (array of integers), int aSize (size of the array), int wSize (size of window)
 * Returns: int *smoothArr (the sorted array of integers
 */
int* lowPassFilter(int *arr, int aSize, int wSize){
	int *smoothArr = new int[aSize];
	if (wSize%2 == 0){
		wSize +=1;
	}
	// Sets the first and last wSize/2 elements equal to 0
	for(int i = 0; i < wSize/2; i++){
		smoothArr[i] = 0;
		smoothArr[aSize - 1 - i] = 0;
	}
	for(int i = wSize/2; i < (aSize - wSize/2); i++){
		int sum = 0;
		for(int j = -wSize/2; j <= wSize/2; j++){
			sum += arr[i-j];
		}
		smoothArr[i] = sum/wSize;
	}
	return smoothArr;
}

/*Creates a 3D array with random dimensions between 3 and 6
 *
 * Parameters: int ***arr(3D array of integers) int &x, &y, &z (integers passed by ref)
 * no return
 *
 */
int *** createMatrix(int ***arr, int &x, int &y, int &z){
	x = rand()%4+3;
	y = rand()%4+3;
	z = rand()%4+3;
	arr = new int**[x];
	for (int i = 0; i < x; i++){
		arr[i] = new int*[y];
		for(int j = 0; j < y; j++){
			arr[i][j] = new int[z];
		}
	}

	cout << "x dimension = " << x << endl;
	cout << "y dimension = " << y << endl;
	cout << "z dimension = " << z << endl;

	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			for(int k = 0; k < z; k++){
				arr[i][j][k] = i+j+k;
			}
		}

	}
	print3DArray(arr, x,y,z);
	return arr;
}

/*Prints the elements of a 3D array
 *
 * Parameters: int ***arr (3D array of ints), int x,y,z (dimensions of array)
 * no return
 *
 */
void print3DArray(int ***arr, int x, int y, int z){
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			for(int k = 0; k < z; k++){
				cout << arr[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << "----------------------" << endl;
	}
}
