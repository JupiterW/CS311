// =========================================================

//HW2P2 Merge Sort’s Combine
//Your name: Jupiter Whitworth
//Complier:  G++
//File type: Main client for HW2P2

//Purpose:  Combines two lists that are in increasing order
//          to another list that is in increasing order that contains
//          elements from L1 and L2. 
//      
//
//================================================================


#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
const int SIZE = 3;// Size of the vectors
void Combine(vector <int>, vector <int>, vector <int>&);
//Combines First and Seconds vectors into the Third. First and Seconds vectors
//have to be inorder for the Combine function to succeed.

int main()
{
  vector <int> L1,L2,L3;
  int temp=0;//Used temporarily to push values into Vectors L1 and L2
  cout<<"Input "<<SIZE<<" integers from increasing order into L1"<<endl;
  for (int i=0;i<SIZE;i++)//Inputs L1
  {
    cout<<"Element "<<setw(2)<<i+1<<" :";
    cin>>temp;
    L1.push_back(temp);
  }

  cout<<"Input "<<SIZE<<" integers from increasing order into L2"<<endl;
  for (int i=0;i<SIZE;i++)//Inputs L2
  {
    cout<<"Element "<<setw(2)<<i+1<<" :";
    cin>>temp;
    L2.push_back(temp);
  }

  Combine(L1,L2,L3);// Calls Combine to combine L1 and L2 into L3.


  cout<<"L3: ";
  for (int i=0;i<L3.size();i++) // Displays L3
    cout<<L3[i]<<" ";
  cout<<endl;
  return 0;
}
 


void Combine(vector <int> A, vector <int> B, vector <int>& R)
//Combines A and B and merges them in order in R.
{
  int ia=0;// Use Ia, Ib, Ir for the location to A,B, and R<
  int ib=0;// Initialize them to 0
  int ir=0;

  while(ia < SIZE && ib < SIZE) // Does until A or B runs out of elements
  {// Makes sure ia is less than size and ib is less then size
    if (A[ia]<B[ib]) // If A is less than B 
    {
      R.push_back(A[ia]);//Increases size of R and pushes value
      ia++;
    }
    else //When B is less than or equal to A 
    {  
      R.push_back(B[ib]);//Increases size of R and pushes value
      ib++;
    }
    ir++;//Increase size of Index R at end of loop
    cout<<"Comparison"<<endl;
  }

  if (ia !=SIZE) // When A has elements left
  {
    for (int i=ia;i<SIZE;i++) // Copies remainder of A to R
     R.push_back(A[i]);//Pushes rest of values back into R
    cout<<"Rest of 1st goes down"<<endl;
  }

  else
  {
    for (int i=ib;i<SIZE;i++) //Copies remainder of B to R
      R.push_back(B[i]);//Pushes rest of values back into R
     cout<<"Rest of 2nd goes down"<<endl;
  }
}




