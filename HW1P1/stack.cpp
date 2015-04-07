

//INSTRUCTION
//Look for **.
//Update comments, complete exception handling and finish ClearIt to make this complete - Yoshii (CS311)

// =========================================================

//HW1P1 stack
//Your name: Jupiter Whitworth
//Complier:  g++
//File type: Implementation file for stack stack.cpp

//================================================================
#include "stack.h"
#include <iostream>
using namespace std;
//** Constructor must initialize top to be -1 to begin with.
stack::stack()
{ 
  top = -1; // indicate an empty stack 
}
// ** Destructor does not have to do anything since this is a static array.
stack::~stack()
{ // nothing to do 
  
}
// ** isEmpty checks top and returns true if empty, false otherwise.
//    In the comment, make sure you define "empty" in terms of top.
bool stack::isEmpty()
{ 
  if (top == -1) //If the top was -1, then the stack is empty
    return true; //and returns true if it is the case and false when not
  else 
    return false; 
}
    
// ** isFull checks top and returns true if full, false otherwise.
// In the comment, make sure you define "full" in terms of top.
bool stack::isFull()
{ 
  if (top == MAX-1 )  //When top is MAX-1 it indicates its full and returns true
                      //and returns false if top is MAX-1
    return true; 
  else 
    return false; 
}
  
// ** push calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
void stack::push(el_t elem)
  { 
    if (isFull()) 
      throw Overflow();
    //Exception handle
    else 
      { top++; el[top] = elem; }  // Top is increased and place elem within the 
                                  // the top of the stack
  }
  
// ** pop calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
void stack::pop(el_t& elem)
  { 
    if (isEmpty()) //When it is empty throws exception Underflow 
      throw Underflow();
    else 
      { elem = el[top]; top--;} // Elem is the placeholder and reduces
                                // the size of the stack by top--
  }

// ** topElem calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
void stack::topElem(el_t& elem)
  { 
    if (isEmpty())  //When empty throws an Underflow error.
      throw Underflow();
    else 
      { elem = el[top]; } //Elem holds the top value of the stack.
  }

//dislayAll calls isEmpty and if true, displays [ empty ].
//  Otherwise, diplays the elements vertically.

void stack::displayAll()
  {  
    if (isEmpty()) 
      cout << "[ empty ]" << endl;
    else 
      for (int i=top; i>=0; i--)
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
