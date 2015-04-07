//INSTRUCTION
//Look for **.

// =========================================================

//HW1P1 stack client
//Your name: Jupiter Whitworth
//Complier:  G++
//File type: Client for Stack client1.cpp

//Purpose: Client using stack inorder to evaulate post-fix expressison.
//
//================================================================

#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int main()
{
  stack postfixstack;  // integer stack
  string expression;
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;
  int number;
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int result;
  while (expression[i] != '\0')
    {
      try
	   {
    //1.  read an item.
      item=expression[i];
	  //2.  if it is an operand (number), 
      if (item>='0'&& item<='9')//making sure the char is a number
      {
        item=item-'0';
        postfixstack.push(item);
      }
	  //push it (you might get Overflow exception)

	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	  apply the operator to the two operands, and
	  //    push the result.
	  
         else if ( (item == '+') || (item == '-') || (item == '*'))
	   {
	     postfixstack.pop(box1);
	     postfixstack.pop(box2);
             // a whole bunch of cases
             if (item == '-') result = box2-box1;
             if (item == '+') result = box2+box1;
             if (item == '*') result = box2*box1;
             // also do the + and * cases 
        postfixstack.push(result);
	     // push the result
	   }
	 else throw "invalid item";
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      catch (stack::Overflow)
	{
    cerr<<"Too Many Operands: Stack Overflow"<<endl;exit(1);
  }
      catch (stack::Underflow)
	{
    cerr<<"Not Enough Operands: Stack Underflow"<<endl;exit(1);
  }
      catch (char const* errorcode) // for invalid item
	{
    cerr<<"Invalid item within expression "<<endl;exit(1);
  }
      // go back to the loop
      postfixstack.displayAll();
      i++;
  }// end of while
  
  //  After the loop successfully completes: 
  //  The result will be at the top of the stack. Pop it and show it.
  //  If anything is left on the stack, an incomplete expression was found
  // inform the user.
    
    postfixstack.pop(result);
    if (postfixstack.isEmpty())
      cout<<"Result: "<<result<<endl;
    else
      cerr<<"Incomplete expression"<<endl;exit(1);
  //**
    
    
}
