// ====================================================

// HW3p2 slist.cpp
// Your name: Jupiter Whitworth
// Complier:  G++
// File type: Search Link List Functions

//=====================================================
#include "slist.h"
using namespace std;
Slist::Slist() :Llist()
{
  //Constructor, Calls LList constructor to fill in necessary values
}

Slist::Slist(const Slist& Copy)
{	
	this->front=NULL;	//Initialize values of this to NULL 
	this->rear=NULL;
	this->count=0;

	Node *p=Copy.front;	//Make P point to Copy's front
	while(p!=NULL)		//Does until end of P
	{
		this->addRear(p->elem);	//Adds element to end of this
		p=p->next;
	}

}

int Slist::search(el_t Key)
{
	if (isEmpty())      //Makes sure its not empty
	return 0;

	Node *p=front;      //Used to find Key
  	int count=0;
  	while (p!=NULL)     //Does until the it reaches NULL
  	{
   	 	count++;
    	if (p->elem==Key) //When the key matches
      	return count;   //Returns the location of where Key is
    	p=p->next;        
 	}
  	return 0;//Returns 0 when couldn't find the Key
}

void Slist::replace(el_t Elem,int I)
{
	if (I<0 || I>count)   //When I is not within the range
	throw OutOfRange(); //Throws an exception
	else
	{
 	Node *p=front;          //Used to replace value
	for (int k=1;k<=I-1;k++) // Have p point right to P
		p=p->next;
	p->elem=Elem;           //Replace P's old elem with Elem
	cout<<"Succesfully replaced"<<endl;
	}
}

Slist& Slist::operator=(const Slist& OtherOne)
{
	if (this != &OtherOne)
	{
		this->deleteAll();// Clear This
		Node *p;
		p=OtherOne.front;
		while(p!=NULL)	//Does while P is NULL
		{
			this->addRear(p->elem);	//Adds p's elem to rear of this
			p=p->next;
		}
	}
	return *this; 	//Return's this 
}

bool Slist::operator==(const Slist& OtherOne)
{
	Node *p=OtherOne.front;	//Creates p with Otherone's front
	Node *q=this->front;	//Creates q with This's front
	if (OtherOne.count!=this->count)	//If their count is not equal
		return false;					//Returns false

	while(p!=NULL)			//Does until end of P
	{			
		if (p->elem !=q->elem)	//If P and Q's elem are not equal, returns false
			return false;
		p=p->next;		//Goes to next 
		q=q->next;		//Goes to next
	}
	return true;
}
