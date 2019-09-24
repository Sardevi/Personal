/******************************************************************************

Linked List
=============

Problem 8 :
===========
Reverse a linked list – iteratively and recursively

Runtime Complexity : O(n)

Solution:
=========
Iteratively:
============
Runtime Complexity : O(n)
space Complexity : O(1)
 *       Have a parent pointer and current pointer(parent->next). 
 *       Iterate till the end of the list, 
 *        a)use a temp Variable to home the currentNodes->next and assign currentNodes-next as Parent=> reverse the pointers
 *        b)current becomes the parent and temp becomes current till the end of the loop
 *        c)if current is NULL => Parent pointer will hold the last element in the list, which will be my new head pointer
 *        d) return new head
Recursively 
===========
Runtime Complexity : O(n)
space Complexity : O(n) // call stack

 *       1)Have a parent pointer and current pointer(parent->next), Parent pointer initially pointed to head, current pointer = head->next;  
 *       2)return statement. if the currentNode pointer is NULL which implies => parentNode is the tail Node=> my new Head
 *       3)recursively call the Method moving parentNode pointer and currentNode pointer to its next
 *       4) after the call assign currentNode->next to its parentNode to reverse the list 
 *       5) newHead pointer is passed as an Arugument through out, so we wont loose the newHead pointer then return to main.
 
 
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
       node* reverseListRecursively(node* parentNode, node *currentNode);
       node* reverseListIteratively();
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

/*****************************
 * Method : reverseListIteratively
 * Runtime Complexity : O(n)
 * return : Node pointer - New headNode
 * Aruguments : void
 * functionality : given the head pointer of a singly linked list, will reverse the list and return new head pointer
 * Logic: 
 *       i will have a parent pointer and current pointer(parent->next). 
 *       Iterate till the end of the list, 
 *       a)use a temp Variable to home the currentNodes->next and assign currentNodes-next as Parent=> reverse the pointers
 *       b)current becomes the parent and temp becomes current till the end of the loop
 *       c)if current is NULL => Parent pointer will hold the last element in the list, which will be my new head pointer
 *       d) return new head
 * ****************************/
node* node::reverseListIteratively()
{
    node *parentNode=this, 
         *tempNode=NULL, 
         *currentNode=this->next;
    this->next=NULL; // Head becomes the tail
    while(currentNode!=NULL)
    {
        tempNode=currentNode->next;
        currentNode->next=parentNode;
        parentNode=currentNode;
        currentNode=tempNode;
    }
    return parentNode;
}

/*****************************
 * Method : reverseListRecursively
 * Runtime Complexity : O(n)
 * return : Node pointer - New headNode
 * Aruguments : parentNode => node pointer
 *              currentNode=> node pointer 
 * functionality : given the head pointer of a singly linked list, will reverse the list and return new head pointer
 * Logic: 
 *       1)Have a parent pointer and current pointer(parent->next), Parent pointer initially pointed to head, current pointer = head->next;  
 *       2)return statement. if the currentNode pointer is NULL which implies => parentNode is the tail Node=> my new Head
 *       3)recursively call the Method moving parentNode pointer and currentNode pointer to its next
 *       4) after the call assign currentNode->next to its parentNode to reverse the list 
 *       5) newHead pointer is passed as an Arugument through out, so we wont loose the newHead pointer then return to main.
 * ****************************/

node* node::reverseListRecursively(node *parentNode, node *currentNode)
{
    
    node *newHead=NULL;
    
    if(currentNode==NULL)
      {
          newHead=parentNode;
//          cout<<"\n New Head : "<<newHead->data;
          return newHead;
      }
    newHead=reverseListRecursively(currentNode, currentNode->next);
    
    currentNode->next=parentNode;
    this->next=NULL; // function called on old Head, which is our new tail   
    return newHead;
}

int main()
{
     int arr[]={1,2,4,5,0,7,6,4};
     int length=sizeof(arr)/sizeof(arr[0]);

     node *head=new node(arr,length);

     cout<<"\nGiven Singly linkedlist : \n";
     head->printList();
     
     cout<<"\nReverse List recursively : \n"; 
     head=head->reverseListRecursively(head,head->next);
     head->printList();
     
     
     cout<<"\nReverse List iteratively : \n"; 
     head=head->reverseListIteratively();
     head->printList();
    
}
