/******************************************************************************

Linked List
=============

Problem 3 :
===========
Clone a linked list with a random pointer.
Node definition [data,*next,*random]


Solution 1:
===========
Runtime Complexity : O(2n)
space Complexity : O(n) [additional Hashmap is used]

1) Iterate the given linked list. 
   a) create a new list with data and *next
   b) in a Hashmap, add the *next as the key and the *newNode created for next Node as value.
   c) this step only data and *next will be populated in the new colned list
2) Iterate the given linkedList again
   a) find the corresponding value for *random from the firstlist in the Hashmap.
   b) that Value will be the coloned newNode pointer. Add this value to new coloned list random poiinter


Solution 2:
===========
Runtime Complexity : O(3n)
space Complexity : O(1) constant

each step takes o(n)
1)create a new node and store the coloned node to original list in its next ptr. 
   say node1's clone is clonedNode1. node1--->clonedNode1--->node2--->clonedNode2...and so on
2)assign random pointer, node1's random will be colonedNode1's random->next;
3) split the linked list original and cloned.

*******************************************************************************/

#include <iostream>
#include <map>
using namespace std;

class node 
{
    public:
       int data;
       node *next;
       node *random;
    public:
       node(int arr[],int length);
       node();
       void printList();
       void cloneListWithoutExtraMemory(node *originalListHead);
       void cloneList(node *originalListHead);
};

/*****
 * Method : node Class constructor 
 * Arugumnets : NULL
 * ****/
 
 node::node()
 {
     data=0;
     next=NULL;
     random=NULL;
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
     node *random=this;
     
     for(int i=1;i<length;i++)
     {
       node *newNode=new node();
     
       newNode->data=arr[i];
       parent->next=newNode;
       parent=newNode;
     
     //randomly connecting even nodes
       if(i%2==0)
        {
          newNode->random=random;
          random=newNode;
        }
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
    current=this;
    cout<<"\nRandom Ptr Link\n";
    while(current!=NULL)
    {
        if(current->random!=NULL)
        cout<<"\nNode :: "<< current->data<< " ====>  "<<current->random->data;
        
        current=current->next;
    }
}

/****
 Method : cloneList
 Aruguments : node *originalList : original List head pointer
 Return : void
 functionality : given a singly linkedlist, clone and list. 
 Solution : solution 1 explained above, using a Hashmap
 *****/

void node::cloneList(node* originalListHead)
{

   std::map<node*, node*>::iterator it;   
   std::map<node*, node*> randomPtrList;
   node *newClonedList=this;
   node *originalList=originalListHead->next;
   
   newClonedList->data=originalListHead->data;
   randomPtrList.insert(pair<node*, node*>(originalListHead,newClonedList));
   
   while(originalList!=NULL)
   {
       node *newNode= new node();
       
       //step 1,a
       newClonedList->next=newNode;
       newNode->data=originalList->data;
       
       //step 1,b
       randomPtrList.insert(pair<node*, node*>(originalList,newNode));

       originalList=originalList->next;
       newClonedList=newClonedList->next;

   }
   
   //step 2
   newClonedList=this;
   originalList=originalListHead;
   while(originalList->next!=NULL)
   {
       it=randomPtrList.find(originalList->random);
       if(it !=randomPtrList.end())
            newClonedList->random=it->second;
       
       newClonedList=newClonedList->next;
       originalList=originalList->next;
   }
   return;
}

/****
 Method : cloneListWithoutExtraMemory
 Aruguments : node *originalList : original List head pointer
 Return : void
 functionality : given a singly linkedlist, clone and list. 
 Solution : solution 1 explained above.store the cloned list to original list in next pointer
 *****/

void node::cloneListWithoutExtraMemory(node *originalListHead)
{
    node *newClonedList=this;

//Step 1
    // new head --- is 'this' node
    newClonedList->data=originalListHead->data;
    newClonedList->next=originalListHead->next;
    originalListHead->next=newClonedList;

    // rest of the nodes
    node *current=newClonedList->next;
    while(current!=NULL)
    {
        node *newNode=new node();
        newNode->data=current->data;
        newNode->next=current->next;
        current->next=newNode;
        current=current->next->next;
    }
//Step 2 - update the random pointer values
    current=originalListHead;
    node *newNode=current->next;
    while(current!=NULL && current->next!=NULL &&newNode->next!=NULL)
    {
        if(current->random!=NULL)
            newNode->random=current->random->next;
        current=current->next->next;
        newNode=newNode->next->next;
    }
    
// Step 3 - Split the list
    current=originalListHead;
    newNode=current->next;
    while(current!=NULL && newNode->next!=NULL)
    {
        current->next=newNode->next;
        newNode->next=newNode->next->next;
        current=current->next;
        newNode=newNode->next;
    }
    current->next=NULL; //original list tail pointer.
    return;
}

int main()
{
     int arr[]={1,2,4,5,0,7,6,4};
     int length=sizeof(arr)/sizeof(arr[0]);

     node *head=new node(arr,length);

     cout<<"\nGiven Singly linkedlist : \n";
     head->printList();
     
     node *newHead=new node();
     newHead->cloneList(head);

     cout<<"\nGiven cloned Singly linkedlist using HashMap: \n";
     newHead->printList();

     node *newHead2=new node();
     newHead2->cloneListWithoutExtraMemory(head);
     
     cout<<"\nGiven cloned Singly linkedlist without using extra space: \n";
     newHead2->printList();
     cout<<"\n Original List : \n";
     head->printList();
}
