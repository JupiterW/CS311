// ====================================================

// HW3p1 llist
// Your name: Jupiter Whitworth
// Complier:  G++
// File type: Link List functions

//=====================================================

#include"llist.h" 
#include <iostream>
#include <cstdlib>
using namespace std;

Llist::Llist() //Constructor
{//Sets values to necessary values
	count=0;
	front=NULL;
	rear =NULL;
}


Llist::~Llist()
{
	cout<<"Calling the llist destructor"<<endl;
	deleteAll();//Deletes all the values
}

bool Llist::isEmpty()
{
	if ((front == NULL && rear == NULL)||(count==0))
		return true;
	else 
		return false;
}

void Llist::displayAll()
{
	if (isEmpty())
		cout<< "[ empty ]"<<endl;
	else
	{	
		cout<< "[ ";
		Node *p=front;
		while (p != NULL)
		{
			cout<<p->elem<<" ";
			p=p->next;
		}
		cout<< "]"<<endl;
	}
}

void Llist::addRear(el_t NewNum) 
{
	if (isEmpty())	//Check to make sure empty
	{
		front= new Node;
		front->elem=NewNum;
		front->next=NULL;
		rear=front;
		count++;
	}
	else
	{
		rear->next=new Node; 	// creates new Node after rear
		rear=rear->next;		// Make rear point to the actual rear
		rear->elem= NewNum;		// Has rear hold newNum
		rear->next=NULL;		// Has next to NULL
		count++;
	}
	return;
}

void Llist::deleteFront(el_t& OldNum)
{
	if (isEmpty())
		throw UnderFlow();
	else
	{
		OldNum= front->elem;// pass front elem to OldNum
		Node *p=front->next; // p points to after front
		delete front;
		front=p;
		count--;
		if (isEmpty())
		{
			front=NULL;
			rear=NULL;
		}
	}
	return;
}

void Llist::addFront(el_t NewNum)
{
	if (isEmpty()) // When the LL is empty adds a New Node
	{
		front=new Node;
		front->elem=NewNum;
		front->next=NULL;
		rear=front;
	}
	else // If there are values within it:
	{
		Node *p = new Node;
		p->next=front;
		p->elem=NewNum;
		front=p;
		front->elem = NewNum;
	}
	count++;
}

void Llist::deleteRear(el_t& OldNum)
{
	if (isEmpty())		// Throws Underflow when empty
		throw UnderFlow();
	else
	{
		OldNum=rear->elem;
		Node *p =front;
		Node *q =front->next;
	//	while(q->next!=NULL) // Makes p point right before NULL
	//	{
	//		p=p->next;
	//		q=q->next;
	//	}

		for (int k=1;k<=count-2;k++) // Have p point right before I
		{
			p=p->next;
		}

		delete rear;		//Deletes the rear
		rear=p;				//New Rear is P
		rear->next=NULL; 	//Rear points to NULL
		count--;
		if (isEmpty())		//When its empty, sets necessary values							
		{
			front=NULL;
			rear=NULL;
		}
	}

}

void Llist::deleteIth(int I, el_t& OldNum)
{
	
	if ( I>count || I<=0)
		throw OutOfRange();
	else if (isEmpty())		// When its empty throws UnderFlow
		throw UnderFlow();
	else if (I==1)
		deleteFront(OldNum);
	else if (I==count)
		deleteRear(OldNum);
	else
	{
		Node *p=front;
		for (int k=1;k<=I-2;k++) // Have p point right before I
			p=p->next;

		Node *q=p->next; // temp node that will delete I
		p->next=p->next->next; // p points after Ith
		delete q; 		//delets q
		count--;
	}

}

void Llist::addbeforeIth(int I, el_t newNum)
{
	if ( I>count+1|| I<0)		//If its not within 1 to count+1
		throw OutOfRange();		//Throws exception
	else if (I==1)				//When its at the first location
		addFront(newNum);		//Does Addfront
	else if (I==count+1)		//When its at the rear+1
		addRear(newNum);		//Does addrear
	else
	{
		Node *p=front;				// P will point before I
		for (int k=1;k<=I-2;k++)	// Have p point right before I
			p=p->next;				
		Node *q=new Node;			//q will be the new node adding before Ith
		q->elem=newNum;				//adding newNum to elem of q
		q->next=p->next;			//have q point before Ith
		p->next=q;					//have Ith-1 point after the new node
		count++;

	}

	cout<<"REAR IS "<<rear->elem<<endl;
}


void Llist::deleteAll()
{
	el_t temp;
	while (front!=NULL) //Deletes all the values within LL
	{
		deleteFront(temp); //Deletes the front until end
	}
}
