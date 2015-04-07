// ====================================================

// HW3p3 slist.h
// Your name: Jupiter Whitworth
// Complier:  G++
// File type: Search Link List header 
//			  With Operator overloading and Copy constructor

//=====================================================
#ifndef slist_h
#define slist_h
#include "llist.h"
#include <iostream>

class Slist : public Llist
{

public:
	Slist();	//Constructor
	Slist(const Slist& Copy); // Copy Constructor
	int search(el_t Key);	//Search
	void replace(el_t Elem,int I);	//Replace Ith Node with Elem

	Slist& operator=(const Slist& OtherOne);
	bool operator==(const Slist& OtherOne);
};
#endif
