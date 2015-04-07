// ====================================================

// HW3p3 SlistClient.cpp
// Your name: Jupiter Whitworth
// Complier:  G++
// File type: Client Search Link List 
//
// Purpose: In order to create a search linked list
//			using Slist that inherits Llist and its
//			functions and values. Client file tests 
//			to see if the functions work.
//=====================================================
#include "slist.h"
using namespace std;
void CopyTest(Slist);

int main()
{
	int temp;
	Slist L1;
	L1.addRear(1);
	L1.addRear(2);
	L1.addRear(3);
	L1.addRear(4);
	L1.addRear(5);
	CopyTest(L1);
	L1.displayAll();
	L1=L1;
	L1.displayAll();
	Slist L2;
	L2.addRear(7);
	L2.addRear(8);
	L2.addRear(9);
	L2.addRear(10);
	L2.displayAll();
	L2=L1;
	L2.displayAll();
	L1.deleteRear(temp);
	L1.displayAll();
	L1.displayAll();
	L2.displayAll();
	return 0;
}


void CopyTest(Slist L)
{
	L.addRear(6);
	L.displayAll();
}
