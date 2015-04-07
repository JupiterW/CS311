
// =========================================================

//HW1P2 stack - vectors
//Your name: Jupiter Whitworth
//Complier:  g++
//File type: Implementation file for stack vStack.cpp

//================================================================
#include "vStack.h"
#include <iostream>
using namespace std;
//Constructor does not need to do anything because its a vector
stack::stack()
{ 
  //Nothing to do 
}
//Destructor has to get rid of contents
stack::~stack()
{ 
  clearIt();// Cleras the contents of the vector

}
// ** isEmpty checks top and returns true if empty, false otherwise.
//    In the comment, make sure you define "empty" in terms of top.
bool stack::isEmpty()
{ 
  if (el.size()==0) //If the size of vector is 0, then the stack is empty
    return true; //and returns true if it is the case and false when not
  else 
    return false; 
}
    
// ** isFull checks top and returns true if full, false otherwise.
// In the comment, make sure you define "full" in terms of top.
bool stack::isFull()
{ 
  return false; // returns false because its never going to be full
                // because its a vector
}
  
// ** push calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
void stack::push(el_t elem)
  { 
      // Removed Overflow, was not necessary in the vector stack
      // because the stack vector would never be full
      el.push_back(elem);
  }
  
// ** pop calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
void stack::pop(el_t& elem)
  { 
    if (isEmpty()) //When it is empty throws exception Underflow 
      throw Underflow();
    else 
    {
      elem=el[el.size()-1]; // uses size()-1 because that is the 
                            // "top" of the vector
      el.pop_back();        // deletes the last location of the 
                            // vector
    }
  }

// ** topElem calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
void stack::topElem(el_t& elem)
  { 
    if (isEmpty())  //When empty throws an Underflow error.
      throw Underflow();
    else 
      { elem = el[el.size()-1]; } //Elem holds the top value of the stack.
  }

//dislayAll calls isEmpty and if true, displays [ empty ].
//  Otherwise, diplays the elements vertically.

void stack::displayAll()
  {  
    if (isEmpty()) 
      cout << "[ empty ]" << endl;
    else 
      for (int i=el.size()-1; i>=0; i--)  // Displays until the end of
                                          // the vector
      { cout << el[i] << endl; }
    cout<<"--------------------"<<endl;
  }


//** clearIt pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt()
{
  el_t temp;
  while(!isEmpty())//while its not empty, in order to clear stack.
  {
    pop(temp);//Takes away value from stack
  }

}
