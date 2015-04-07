//=====================================================
//INSTRUCTION
//Update comments
//Fill in the function body

// =========================================================

//HW1P1 queue
//Your name: Jupiter Whitworth
//Complier:  G++
//File type: Implementation file for Queue queue.cpp
//================================================================

#include "queue.h"   // constructor 
using namespace std;
queue::queue()
{
	rear=-1; //Rear starts from -1
	front=0;
	count=0;
}

//destructor 
queue::~queue()
{
	//Does nothing
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
	if (getSize()==0)//Checks the count if it is 0
    	return true;
	else 
    	return false;//Else returns false indicating it is not empty
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
	if (getSize()==MAX_SIZE)//Checks if full by looking at count
  		return true;
  	else
    	return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// HOW TO CALL: provide the element to be added
void queue::add(el_t elem)
{
	if(isFull())
		throw Overflow();//Throws overflow when full
	else
	{
		rear=(rear+1)%MAX_SIZE;//Rear changed to be able to add elem to el
		el[rear]=elem;//Adding elem to queue
		count++;
	}
}

// PURPOSE: if empty, calls an emergency exit routine
// if not empty, removes the front element to give it back 
// HOW TO CALL: provide a holder for the element removed (pass by ref)
void queue::remove(el_t& elem)
{
	if (isEmpty())
		throw EmergencyExit();
	else
	{	
		frontElem(elem);//calls to have elem hold onto the front element

		front=(front+1)%MAX_SIZE;
		//el[front]=front;
		count--;
	}


}
// PURPOSE: if empty, throws an exception Underflow
   // if not empty, give back the front element (but does not remove it)
   // TO CALL: provide a holder for the element (pass by ref)
void queue::frontElem(el_t& elem)
{
	if (isEmpty())//Checks if empty and if so throws underflow
		throw Underflow();
	else
		elem=el[front];//Passed by reference value holds the element at front
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
	return count;//Returns the size
}


// PURPOSE: display everything in the queue from front to rear
//  enclosed in []
// if empty, displays [ empty ]
// also displays the count,location of front, and location of rear as well

void queue::displayAll()
{
	cout<<"count:"<<getSize()<<" front:"<<front<<" rear:"<<rear<<endl;
	//Displaying important values
	if (isEmpty())//Checks if queue is empty
		cout<<"[empty]"<<endl;
	else//If not empty
	{
		cout<<"[ ";
		for(int i=0;i<count;i++)
			{
				cout<<el[(front+i)%MAX_SIZE]<<" ";
				//Displays all the values starting from front until i reaches count
				//The % is used to account for the wrap around of front
			}
		cout<<"]"<<endl;
	}

}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear
void queue::goToBack()
{
	if (isEmpty())//Checks to makes sure it is empty before continuing
		throw Underflow();
	else if (count==1)
		return;//Does nothing
	else 
		{
			el_t elem;//elem used for place holder
			remove(elem);
			//elem holds front elem. and removed from queue
			add(elem);
			//adds elem to queue but adds it to the rear
		}
}



