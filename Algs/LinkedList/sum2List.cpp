/******************************************************************************

Linked List
=============
Problem 9:
==========
Given two numbers represented by two lists,write a function that returns sum list. 
The sum list is list representation of addition of two input numbers.
Suppose you have two linked list 5->4 ( 4 5 )and 5->4->3( 3 4 5) you have to return
a resultant linked list 0->9->3 (3 9 0).

Runtime Complexity :O(n+m)
Space Complexity : O(1)

Solution
=========
1. Have 2 variables sum value and carryOver. 
2. Create a new result linked list, as digits are stored reversed 
3. 2 pointers for one for each list, add sumvalue to the linked list node and use carryOver for next node
4. if one list is empty, copy the rest of the other list to result list with previous carryOver
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
       node* sumList(node*);
};

/*****
 * Method : sumList 
 * Aruguments : node* head pointer to list2, method called on list1
 * Returns : node* , head pointer to resultlist
 * functionality : sums up two list and create a new result linked list.
 * Logic :
 * 1. Have 2 variables sum value and carryOver. 
   2. Create a new result linked list, as digits are stored reversed 
   3. 2 pointers for one for each list, add sumvalue to the linked list node and use carryOver for next node
   4. if one list is empty, copy the rest of the other list to result list with previous carryOver
 * ****/
node* node::sumList(node* list2)
{
    node *resultList=NULL,
         *resultNode=NULL,
         *previous=NULL;
    node *list1=this;
    int sumvalue=0, carryOver=0;

    while(list1!=NULL && list2!=NULL)
    {
        resultNode=new node();
        
        if(resultList==NULL) resultList=resultNode;
        if(previous!=NULL) previous->next=resultNode;
        
        sumvalue=carryOver+list1->data+list2->data;    
        carryOver=sumvalue/10;
        sumvalue=sumvalue%10;
        resultNode->data=sumvalue;
        previous=resultNode;
        list1=list1->next;
        list2=list2->next;
    }
    
    if(list2!=NULL) list1=list2; 
    while(list1!=NULL) //handle one list and previous carryOver if any
    {
        resultNode=new node();
        previous->next=resultNode;

        sumvalue=carryOver+list1->data;    
        carryOver=sumvalue/10;
        sumvalue=sumvalue%10;
        resultNode->data=sumvalue;
        previous=resultNode;
        list1=list1->next;
    }
    return resultList;
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
     int arr[]={5,4};
     int arr2[]={5,4,3};
     int length=sizeof(arr)/sizeof(arr[0]);
     
     node *head=new node(arr,length);
     length=sizeof(arr2)/sizeof(arr2[0]);
     node *head2=new node(arr2,length);

     cout<<"\nGiven linkedlist 1 : \n";
     head->printList();
     cout<<"\nGiven linkedlist 2 : \n";
     head2->printList();
     
     node* resultList=head->sumList(head2);     
     cout<<"\nResult List : \n";
     resultList->printList();
}
