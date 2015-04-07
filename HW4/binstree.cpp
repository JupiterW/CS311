// =========================================================

//HW4 BST
//Your name: Jupiter Whitworth
//Complier:  g++
//File type: Binstree.cpp functions

//================================================================


#include <iostream>
using namespace std;

#include "binstree.h"

// constructor  initializes Root
BST::BST()
{
   Root = NULL;   // This is an empty tree
}

// destructor must completely destroy the tree
BST::~BST()
{
   dtraverse(Root); // traverse to delete all vertices in post order
   Root = NULL;    
}


// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:  pointer to the vertex to be deleted
void BST::dtraverse(Vertex *V)  // post order traversal
{   
  if (V != NULL) 
    {
      dtraverse(V->Left);         // visit Left sub tree of V
      dtraverse(V->Right);       // visit Right sub tree of V
      delete V;                  // deletes V
    }
}


// PURPOSE: Show elements in IN order traversal from the Root
void BST::ShowInOrder()
{
  cout << "Elements in the IN order: " << endl;
  INorderTraversal(Root);  // start in-order traversal from the root
}

// PURPOSE: Does IN order traversal from V recursively
// PARAM: pointer to the vertex to visit Right now
void BST::INorderTraversal(Vertex *V)
{
    if (V != NULL)
      {
      	INorderTraversal(V->Left);	//Traverse Left of V
      	cout<<V->Elem<<endl;		//Displays V's Elem
      	INorderTraversal(V->Right); //Traverse Right of V
      }
}

// PURPOSE:  Show elements in PRE order traversal from the Root
// This is the same as Depth First Traversal
void BST::ShowPreOrder()
{
  	cout << "Elements in the PRE order:" << endl;
  	PREorderTraversal(Root);  // start pre-order traversal from the root
}

// PURPOSE: Does PRE order traversal from V recursively
// PARAM: pointer to the vertex to be visited now
void BST::PREorderTraversal(Vertex *V)
{
    if (V != NULL)
    {
      	cout<<V->Elem<<endl;				//Display's V's Elem
       	PREorderTraversal(V->Left);	//Traverse Left of V
       	PREorderTraversal(V->Right);	//Traverse Right of V
    } 
}


// PURPOSE: Adds a vertex to the binary search tree for new element 
// PARAM: the new element E
// ALGORITHM: We will do this iteratively (not recursively)
//     - smaller than the current -> go to the Left
//     - bigger than the current  -> go to the Right
//    - cannot go any further    -> add it there
void BST::Insertvertex(elem_t E)
{

   Vertex *N;       // N will point to the new vertex to be inserted
   N = new Vertex;        // a new vertex is created
   N->Left  = NULL;     // make sure it does not
   N->Right = NULL;    // point to anything
   N->Elem  = E;            // put element E in it

   cout << "Trying to insert " << E << endl;

	if (Root == NULL)  // Special case: we have a brand new empty tree
     {
       Root = N;      // the new vertex is added as the root
       cout << "...adding " << E << " as the root" << endl; 
     }

  else  // the tree is not empty
  	{
        Vertex *V;       // V will point to the current vertex
        Vertex *Parent;  // Parent will point to V's parent

        V = Root;        // start with the root as V
        
 	 while (V != NULL)  // go down the tree until you cannot go any further
  		{
			if (N->Elem == V->Elem) // special case
			{ 	
				cout << "...error: the element already exists" << endl;
				return;  
			}
			else if (N->Elem < V->Elem)  // what I have is smaller than V
			{  
				cout << "...going to the Left" << endl; 
	       		Parent=V;		// ** change Parent to be V to go down 
               	V=V->Left;		// ** change V to be V's Left 
			}
			else // what I have is bigger than V
			{  
				cout << "...going to the Right" << endl;
				Parent=V;		// ** change Parent to be V to go down
				V=V->Right;		// ** change V to be V's Right 
			}

		}//end of while
        
        // reached NULL -- Must add N as the Parent's child

		if (N->Elem < Parent->Elem)  
		{  
			Parent->Left=N;				// ** Parent's Left should point to the same place as N 
			cout << "...adding " << E << " as the Left child of " 
			<< Parent->Elem << endl;
		}
		else 
		{
			Parent->Right=N;	// ** Parent's Right should point to the same place as N 
			cout << "...adding " << E << " as the Right child of " 
			<< Parent->Elem << endl;	
		}

	}// end of normal case




}

// PURPOSE: Deletes a vertex that has E as its element.
// PARAM: element E to be removed
// ALGORITHM: First we must find the vertex then call Remove
void BST::DeleteVertex(elem_t E)
{

  cout << "Trying to delete " << E << endl;

  Vertex *V;              // the current vertex
  Vertex *Parent = NULL;  // its parent

	if ((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL))
	{ 
		cout << "...deleting the lonely root" << endl;
		delete Root; 
		Root = NULL;
		return; 
	}  // only the Root was there and deleted it

	if (E == Root->Elem && !(Root->Right!=NULL && Root->Left!=NULL)) 
	{  
   		if (Root->Left!=NULL)	//When Left is only child
   		{
   			V=Root;				//V Holds old root
   			Root=Root->Left;	//Changes Root
   			delete V;			//Deletes old Root
   		}

   		else 					//When Right is only child
   		{
   			V=Root;				//V holds old root
   			Root=Root->Right;	//Changes Root
   			delete V;			//Delete old Root
   		}
   		return;
	}


// Otherwise deleting something else

   V = Root;  // start with the root to look for E

   while (V != NULL)		//Do until V is NULL
   { 
        if ( E == V->Elem)   // found it
        {  
        	cout << "...removing " << V->Elem << endl;
            remove(V,Parent);
            return; 
        }

	    else if (E < V->Elem)
        {  
        	cout << "...going to the Left" << endl;
            // ** update Parent and V here to go down 
        	Parent=V;
            V=V->Left;
        }
        else
        {  
        	cout << "...going to the Right" << endl;
           	Parent=V;
           	V=V->Right;
           	// ** update Parent and V here to go down
        }

	}// end of while

        // reached NULL  -- did not find it
   	cout << "Did not find the key in the tree." << endl;
   	return;
}// end of DeleteVertex


// PURPOSE: Removes vertex pointed to by V
// PARAM: V and its parent  pointer P
// Case 1: it is a leaf – delete it
// Case 2: it has just one child – bypass it
// Case 3: it has two children – replace it with the max of the Left //subtree

void BST::remove(Vertex *V, Vertex *P)
{
  	//	if V is a leaf (case 1)
	if (V->Left==NULL && V->Right==NULL)
    {
    	cout << ".. removing a leaf" << endl;
      	// 	 if V is a Left child of P
   		if (P->Left==V)	//When parent's Left is V
      	{
      		delete V;
      		P->Left=NULL;// ** delete V and also make Parent's Left NULL 
      	}
      	else // V is a Right child of the Parent
      	{ 
      		delete V;
      		P->Right=NULL;
           // ** delete V and also make Parent's Right NULL 
      	}
  	}

    
  // ** else if V has just the Left child (case 2)
  	else if (V->Left!=NULL && V->Right==NULL) 	//When V only has Left
  	{
  		cout << "removing a vertex with just the Left child" << endl;
  		if (P->Left==V)	//When Parent's Left is V
  			P->Left=V->Left;
  		else 
  			P->Right=V->Left;
  		delete V;
        // ** Make Parent’s Left or Right point to the Left child and       delete V (You need if then else to determine Left or Right)
  	}   
    

    else if (V->Left==NULL && V->Right!=NULL) 	//When V only has Right
  	{
  		cout << "removing a vertex with just the Right child" << endl;
  		if (P->Left==V)	//When Parent's Left is V
  			P->Left=V->Right;	//Make P's Left point to V's Right
  		else 
  			P->Right=V->Right;	//Makes P'S Right point to V's Right
  		delete V;
       // ** Make Parent’s Left or Right point to the Right child and delete V (need if then else to determine Left or Right)
  	}

   else // V has two children (case 3)
     {  cout << "...removing an internal vertex with children" << endl;
        cout << ".....find the MAX of its Left sub-tree" << endl;
        elem_t Melem;
        Melem = findMax(V); // find MAX element in the Left sub-tree of V
        cout << ".....replacing " << V->Elem << " with " << Melem << endl;
        V->Elem= Melem;		//Replaces V's Elem with Melem's
        // ** Replace V's element with Melem here
     }
 }// end of remove

// PURPOSE: Finds the Maximum element in the Left sub-tree of V
elem_t BST::findMax(Vertex *V)
{
     Vertex *Parent = V;
     V = V->Left;          // start with the Left child of V

       // ** while the Right child of V is still available
     	while (V->Right !=NULL)	//Do Until V's Right is NULL
          {
          		Parent=V;
          		V=V->Right;
				// ** update Parent and V to go to the Right
          }
      // reached NULL Right  -- V now has the MAX element
        elem_t X = V->Elem;
        cout << ".....Max is " << X << endl;
        remove(V, Parent);    // remove the MAX vertex 
        return X;             // return the MAX element

}// end of FindMax

