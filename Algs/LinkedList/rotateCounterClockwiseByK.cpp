/******************************************************************************

Linked List
=============

Problem 2:
===========
Given a singly linked list, rotate the linked list counter-clockwise by k nodes. 
Where k is a given positive integer smaller than or equal to length of the linked list.
For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list 
should be modified to 50->60->10->20->30->40.


Runtime Complexity : O(n)
=======
space Complexity : O(1)
=======
Solution:
=========
     1) iterate through the list till kth node, mark the kth Node as head
     2) update tailNodes->next to old head and kth-1 Node-> Next null (which will be our new tail) 
*******************************************************************************/

#include <iostream>
#include <map>
using namespace std;

class node 
{
    public:
       int data;
       node *next;
    public:
       node(int arr[],int length);
       node();
       void printList();
       node* rotateLinkedListK(int k);
       
};


/********
 * Method:  rotateLinkedListK
 * Arguments: k (type int) always be less than or equal to length of the list
   Return : new head (Type node*)
   Runtime : O(n)
   functionality : rotate the list, kth node will be the new head and tail will be connected to old head.
   logic:
     1) iterate through the list till kth node, mark the kth Node as head
     2) update tailNodes->next to old head and kth-1 Node-> Next null (which will be our new tail)
 ********/
node* node::rotateLinkedListK(int k)
{
    
    node *current=this,*newHead=NULL;
    int ctr=1;
    while(ctr<k && current!=NULL)
    {
        ctr++;
        current=current->next;
    }
    newHead=current->next; // kth-1node will be pointing to kth node , new head
    current->next=NULL; // kth-1 node , new tail
    current=newHead;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=this; //old tail node connected to old head to form the anti counter-clockwise rotation
                        //function is called on old head

    return newHead;
}

/*****
 * Method : node Class constructor 
 * Aruguments : NULL
 * ****/
 
 node::node()
 {
     data=0;
     next=NULL;
 }
 
/*****
 * Method : node Class constructor 
 * Arugumnets : int arr[] integer array each value will be used to create the linkedlist
 *              int length - length of the giving array
 * ****/
 
 node::node(int arr[], int length)
 {
     data=arr[0];
     node *parent=this;
    
     for(int i=1;i<length;i++)
     {
       node *newNode=new node();
     
       newNode->data=arr[i];
       parent->next=newNode;
       parent=newNode;
     }
     
 }

/********
 * Method:  print Singly Linked List iteratively 
   Return : void
   Runtime : O(n)
   functionality : display the values in the Singly link list
 ********/

void node::printList()
{
    node *current=this;
    while(current!=NULL)
    {
        std::cout << current->data <<"  ";
        current=current->next;
    }
}


int main()
{
     int arr[]={10,20,30,40,50,60};
    // int arr[]={1,2,3,4,5};
     int k=4;
     int length=sizeof(arr)/sizeof(arr[0]);

     node *head=new node(arr,length);

     cout<<"\nGiven Singly linkedlist : \n";
     head->printList();
     
     head=head->rotateLinkedListK(k);
    
     cout<<"\n anticlockwise rotated "<<k <<" times Singly linkedlist : \n";
     head->printList();
}
