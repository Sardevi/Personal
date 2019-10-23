/******************************************************************************

Linked List
=============

Problem 1:
===========
Given a singly linked list, find middle of the linked list. For example, if given linked list is 1->2->3->4->5 then output should be 3. 
If there are even nodes, then there would be two middle nodes, we need to print second middle element. 
For example, if given linked list is 1->2->3->4->5->6 then output should be 4.

Runtime Complexity : O(n)
space Complexity : O(1)

Solution:
=========
 1) will have 2 pointers, slow and fast pointer
 2) iterate through the list slow pointer by 1 node at a time and fast pointer 2 nodes at a time.
 3) when fast pointer reachs the last node, slow pointer will be pointing the middle node                        
 
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
       void findMiddleElement();
       
};


/********
 * Method:  findMiddleElement
   Return : void
   Runtime : O(n/2) ~= O(n)
   functionality : 
     1) will have 2 pointers, slow and fast pointer
     2) iterate through the list slow pointer by 1 node at a time and fast pointer 2 nodes at a time.
     3) when fast pointer reachs the last node, slow pointer will be pointing the middle node                        

 ********/
void node::findMiddleElement()
{
    
    node *slowPtr=this,*fastPtr=this;
    while(fastPtr!=NULL && fastPtr->next!=NULL)
    {
        slowPtr=slowPtr->next;
        fastPtr=fastPtr->next->next;
    }
    cout<<"\n middle element is : "<<slowPtr->data;
}

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


int main()
{
     int arr[]={1,2,3,4,5,6};
    // int arr[]={1,2,3,4,5};
    
     int length=sizeof(arr)/sizeof(arr[0]);

     node *head=new node(arr,length);

     cout<<"\nGiven Singly linkedlist : \n";
     head->printList();
     
     head->findMiddleElement();
}
