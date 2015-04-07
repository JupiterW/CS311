// =======================================================

// HW1P2
// Your name: Jupiter Whitworth
// Compiler:  g++ 
// File type: Header file vStack.h

//=======================================================
#ifndef vStack_h
#define vStack_h
#include <vector>
using namespace std;
typedef int el_t;      // the el_t type is ** for now
                      // el_t is unknown to the client


class stack
  { 

   private: // to be hidden from the client

        vector <el_t>     el;      // el is the vector of el_t's
   public: // prototypes to be used by the client

        // exception handling classes  
        class Overflow{};
        class Underflow{};

      	stack();   // constructor
      	~stack();  // destructor  

        // HOW TO CALL: pass the element to be pushed
        // PURPOSE: if not full, enters an element at the top;
        //          otherwise throws an exception - Overflow
        void push(el_t);

        // HOW TO CALL: provide variable to receive the popped element
        // PURPOSE: if not empty, removes and gives back the top element;
        //          otherwise throws an exception - Underflow
        void pop(el_t&);

        // HOW TO CALL: provides variable to have value of the top element.
        // PURPOSE: if not empty, gives the top element without removing it;
        //          otherwise, throws an exception - Underflow
        void topElem(el_t&);

        // HOW TO CALL: provides bool value of whether its empty
        // PURPOSE: Returns true when it is empty
        //          and returns false when not empty
        //       
      	bool isEmpty();
      	// HOW TO CALL: provides bool value of whether its full
        // PURPOSE: Returns true when it is full 
        //          and returns false when not full
        //          
      	bool isFull();
      	// HOW TO CALL: When stack is needed to be cleared
        // PURPOSE: Clears all values within stack
        //        
        void clearIt();
        // HOW TO CALL: In client file to display anything in stack
        // PURPOSE: Displays the values within the stack 
        //        
        void displayAll();
  };  
#endif
// Note: semicolon is needed at the end of the header file
//
