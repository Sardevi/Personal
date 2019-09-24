/******************************************************************************

Linked List
=============

Problem 2 :
===========
Write an algorithm to determine if a linkedlist is circular. FOLLOW UP: Determine where the circle meets.

Runtime Complexity : O(n)

Solution:
=========

1) Creating a circular list if and where '0' is present in the input arguments
2) isCircular
 * Logic : Have two pointers Slow and a Fast Pointer 
 *      Iterate through the list,
 *            slowPtr will move one node at a time
 *            fastPtr will move two nodes at a time
 *            will check whether slowPtr and fastPtr pointing to the same node. If so its circular
 *       
3) find Meeting Point   
* Logic: 
 *    1) Create a HashMap where KEY will be the node. 
 *    2) Iterate through the list
 *    3) while visiting the node, 
 *           a) check whether node is present in the HashMap,
 *           b) If so return the node
 *           c) else add it to the map
 *    Iterate till end of the list
 *                               
 ****************************************************/
 
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
       node(int arr[],int length,bool buildCircular);
       node();
       void printList();
       bool isCircular();
       int findWhereCircleMeet();
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
 * Arugumnets : int arr - array, create a list with values from the array
 *              int length - number are elements to be added to the linkedlist
 *              bool buildCircular - True(1) create a circular list.. false(0) create a linear list 
 * ****/
 
 node::node(int arr[], int length,bool buildCircular)
 {
     data=arr[0];
     node *parent=this;
     node *circularNodeLink=NULL;
     for(int i=1;i<length;i++)
     {
       node *newNode=new node();
       
       if(arr[i]==0) circularNodeLink=newNode; // If the value is 0.. i am a circular link list
       
       newNode->data=arr[i];
       parent->next=newNode;
       parent=newNode;

       if(i==length-1 && buildCircular==1) // Add to the last node
           newNode->next=circularNodeLink;
     }
     
 }

/********
 * Method:  print Singly Linked List 
   Return : void
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


/********************
 * Method : findWhereCircleMeet
 * Runtime Complexity : O(n)
 * Space complexity :constant O(n)
 * Return : int - data of which node in the linked list the circle meets
 * functionality : check where the given Singly linked list meets.
 * Logic: 
 *    1) Create a HashMap where KEY will be the node. 
 *    2) Iterate through the list
 *    3) while visiting the node, 
 *           a) check whether node is present in the HashMap,
 *           b) If so return the node
 *           c) else add it to the map
 *    Iterate till end of the list
 *                               
 ****************************************************/
 
 int node::findWhereCircleMeet()
 {
    std::map<node*,int>::iterator it;   
    std::map<node*, int> singlyLinkedList;
    node *currentNode=this;
    
    while(currentNode!=NULL)
    {
       it=singlyLinkedList.find(currentNode);
       if(it !=singlyLinkedList.end())
           return currentNode->data;
    
        singlyLinkedList.insert(pair<node*, int>(currentNode,1));
        currentNode=currentNode->next;
    }
 }
 
/********************************
 * Method: isCircular
 * Runtime Complexity : O(n)
 * Space complexity :constant O(1)
 * Return :Bool (ture -if LL is circular or false -if LL is not circular)
 * functionality : check whether the given Singly linked list is circular.
 * Logic : Have two pointers Slow and a Fast Pointer 
 *      Iterate through the list,
 *            slowPtr will move one node at a time
 *            fastPtr will move two nodes at a time
 *            will check whether slowPtr and fastPtr pointing to the same node. If so its circular
 *       
 * ***********************************/
bool node::isCircular()
{
    
    node* slowPtr=this;
    node* fastPtr=this;
    while(fastPtr!=NULL && fastPtr->next!=NULL)
    {
        slowPtr=slowPtr->next;
        fastPtr=fastPtr->next->next;
        if(slowPtr==fastPtr)
             return 1; // circular
        
    }
    return 0;
}



int main()
{
     int arr[]={1,2,4,5,0,7,6,4};
     int length=sizeof(arr)/sizeof(arr[0]);

     node *head=new node(arr,length,1);
     
     //head->printList();     
     bool isCircularFlag=head->isCircular();
     if(isCircularFlag) cout<<"Singly linkedlist is circular";
     else cout<<"Singly linkedlist NOT circular";
     
     if(isCircularFlag)
       cout<<"\nPoint where linkedlist meets : "<<head->findWhereCircleMeet();
}
