/******************************************************************************

Linked List
=============

Problem 5 :
===========
Implement an algorithm to find the kth to the last element of a singly linked list

Runtime Complexity : O(n-k)

Solution:
=========
      1) Have 2 pointers kth pointer and tail pointer
      2) initially kth pointer will point to head node and tail pointer will be point to a node with kth distance
         => tailNode=tailNode->next k times
      3) move kthNode Pointer and tailNode pointer till tail pointer reaches tailNode [these 2 pointers will always maintain k distance]
      4) return kthNode pointer data 
                            
 
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
       int findKthElementfromLast(int k);
};

/*****
 * Method : node Class constructor 
 * Arugumnets : NULL
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


/********
 * Method:  findKthElementfromLast
   Return : int - value of the kth node
   Runtime : O(n)
   functionality : to find the value of kth node from the last(tail node) in the Singly link list
   Solution:
      1) Have 2 pointers kth pointer and tail pointer
      2) initially kth pointer will point to head node and tail pointer will be point to a node with kth distance
         => tailNode=tailNode->next k times
      3) move kthNode Pointer and tailNode pointer till tail pointer reaches tailNode [these 2 pointers will always maintain k distance]
      4) return kthNode pointer data 
 ********/

int node::findKthElementfromLast(int k)
{
    node *kthNode=this;
    node *tailNode=this;
    
    while(k>1)
    {
        tailNode=tailNode->next;
        k--;
    }
    while(tailNode->next!=NULL)
    {
        tailNode=tailNode->next;
        kthNode=kthNode->next;
    }
    return kthNode->data;
}

int main()
{
     int arr[]={1,2,4,5,0,7,6,4};
     int length=sizeof(arr)/sizeof(arr[0]);

     //int k=3;
     //int k=1; //tail 
     //int k=length-1;//2st
     int k=length;//1st
     if(k<1 || k>length) 
        {
          cout<<"K is out of range, expected range [ 1 - "<<length-1;
          return 1;
         } 
     node *head=new node(arr,length);

     cout<<"\nGiven Singly linkedlist : \n";
     head->printList();
    
     cout<<"\nKth element from last in the given list is : "<<head->findKthElementfromLast(k);     
     
}
