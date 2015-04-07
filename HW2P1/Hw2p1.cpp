// =========================================================

//HW2P1 Binary Recursive search
//Your name: Jupiter Whitworth
//Complier:  G++
//File type: Main client for HW2P2

//Purpose: 	Using the binary search of an ordered list will 
//			return the location of the variable within an ordered array.
//			With 1 as the first location and n as the last location
//			With n being the number of elements within the array.
//
//================================================================

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int binarySearch(int [],int,int,int);

int main()
{
		int n=10;// n represents the number of elements within the array
		int findThis;//findThis is the number that is being searched for
		int myList[]={1,3,5,7,9,11,13,15,17,19};//Fill L with 10 array
		cout<<"Enter a number to look for: ";
		cin>>findThis;

   		int myfirst = 0; //The location of the first element within an array
   		int mylast = n-1; //The location of the last element within an array
  		int resultloc = binarySearch(myList, findThis, myfirst, mylast)+1;
  		//Call the recursive  
 		cout<<"The number was found in position "<<resultloc<<endl;
 		return 0;

 }
// Recursive function in-order to find the location of the value
int binarySearch(int L[],int x,int first,int last) 
{
	int middle = floor(first+last)/2;//Finds middle value and rounds down
	if (x == L[middle]) 
		return middle;// found x at location middle
	else if (x < L[middle]) 
		last  = middle - 1; // go to first half
	else if (x > L[middle]) 
		first = middle + 1; // go to second half
	return binarySearch(L, x, first, last); // recursive call
}
