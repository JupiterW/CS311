// ====================================================

// HW3p3 hw3ec.cpp
// Your name: Jupiter Whitworth
// Complier:  G++
// File type: Client Search Link List 
//
// Purpose: Extra credit portion of HW3P3, where 
//			the == operator is testesd to make sure it
//			is operating properly
//=====================================================
#include "slist.h"
using namespace std;
void CopyTest(Slist);

int main()
{
	int temp;
	Slist L1;
	Slist L2;

	cout<<"L1 is empty and L2 is empty"<<endl;
	if (L1==L2)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
	L2.addFront(0);
	L2.addFront(0);
	
	cout<<"L1 is empty and L2 has 2 elements"<<endl;
	if (L1==L2)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;


	L2.deleteAll();
	L1.addFront(1);
	L1.addRear(2);

	cout<<"L1 has 2 elements and L2 is empty"<<endl;
	if (L1==L2)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;

	L1.addRear(3);
	L2.addRear(1);
	L2.addRear(2);
	L2.addRear(3);

	cout<<"L1 has 1,2,3 and L2 has 1,2,3"<<endl;
	if (L1==L2)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;

	L2.deleteRear(temp);

	cout<<"L1 has 1,2,3 and L2 has 1,2"<<endl;
	if (L1==L2)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;


	L2.addRear(3);
	L2.addRear(4);

	cout<<"L1 has 1,2,3 and L2 has 1,2,3,4"<<endl;
	if (L1==L2)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;

	L2.deleteIth(3,temp);

	cout<<"L1 has 1,2,3 and L2 has 1,2,4"<<endl;
	if (L1==L2)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;

}



void CopyTest(Slist L)
{
	L.addRear(6);
	L.displayAll();
}