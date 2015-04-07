// =========================================================

//HW1P1 queue
//Your name: Jupiter Whitworth
//Complier:  G++
//File type: client of queue, client2.cpp
//Purpose: 	To display in a particular order using queues.
//			In the order like A, B ,C AA,AB,Ac....
//
//================================================================

#include "queue.h"
#include <iostream>
using namespace std;

int main()
{
	try
	{
		string temp; 	// Temp value used as the place holder.
		queue ABC; 		// the name of the queue used to display in particular order
		ABC.add("A");	//Adds A, B, C to the Queue name ABC
		ABC.add("B");
		ABC.add("C");

		ABC.displayAll();//Displays all the Queues

		while(!ABC.isFull())//Repeats until the queue is full
		{
		ABC.remove(temp); 	// Removes the front value and uses temp as place holder
		cout<<temp<<endl; 	// Displays value taken out
		ABC.add(temp+"A");	// Adds the string of the previously taken value
							// With the string of the letter A, B, C
							// in order to create the necessary pattern
		ABC.add(temp+"B");
		ABC.add(temp+"C");
		ABC.displayAll();	// Displays whats in the queue along with
							// Important information within in the queue
							// like count,rear location,front location
		}	

	}
	//Exceptions of various errors that may occur while running program
	catch(queue::Overflow) 
	{
		cerr<<"Queue Overflow"<<endl;exit(1);
	}
	catch(queue::Underflow)
	{
		cerr<<"Queue Underflow"<<endl;exit(1);
	}
	catch(queue::EmergencyExit)
	{
		cerr<<"Error: Emergency Exit"<<endl;exit(1);
	}

	return 0;
}
