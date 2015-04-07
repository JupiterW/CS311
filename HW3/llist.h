// ====================================================

// HW3p1 llist.h
// Your name: Jupiter Whitworth
// Complier:  G++
// File type: Link List header 

//=====================================================
#ifndef llist_h
#define llist_h

typedef int el_t;


struct Node
{
	el_t elem;
	Node *next;
};

class Llist
{
protected:
	Node *front;
	Node *rear;
	int count;
public:
	class OverFlow{};
	class UnderFlow{};
	class OutOfRange{};


	Llist(); 	// Constructor
	~Llist();	// Destructor 
	bool isEmpty();	
	//Returns true or false on whether its empty
	void displayAll(); 
	// Display all the elements within the LL
	void addRear(el_t NewNum); 
	//Creates a new Node containing NewNum and adds to rear
	void deleteFront(el_t& OldNum);
	//Deletes the front node while retaining element in OldNum
	void addFront(el_t NewNum); 
	//Adds to the front of LL with Node with NewNum
	void deleteRear(el_t& OldNum);
	//Deletes the last node while retaining the element in OldNum
	void deleteIth(int I,el_t& OldNum); 
	// Deletes Ith Node and retains the element in OldNum
	void addbeforeIth(int I,el_t newNum);
	// Adds newNode before the Ith Number

	void deleteAll();
	//Removes all the values from LL

};
#endif
