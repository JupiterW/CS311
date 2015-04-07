
//INSTRUCTION:
//Stack class - header file template (by Yoshii) based on Notes-1
//You must complete the ** parts and then complete stack.cpp

// =======================================================

// HW1P1
// Your name: Jupiter Whitworth
// Compiler:  g++ 
// File type: Header file stack.h

//=======================================================
#ifndef stack_h
#define stack_h
const int MAX = 10;   // The MAX number of elements for the stack
                       // MAX is unknown to the client

typedef int el_t;      // the el_t type is ** for now
                      // el_t is unknown to the client


class stack
  { 

   private: // to be hidden from the client

        el_t     el[MAX];       // el is  an array of el_t's
        int      top;           // top is index to the top of stack

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
