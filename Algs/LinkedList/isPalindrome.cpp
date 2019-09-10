/******************************************************************************

Linked List
=============

Problem 1 :
===========
Write an algorithm to determine if a linkedlist is a palindrome

Approach 1
==========
Doubly Linked List
Logic : a) Traverse the list to find the last element. 
 *         b) check first(head pointer) and last element(tail pointer). 
 *         c) inc head pointer and dec tail pointer to compare the value. Till it reaches the middle point, If successful return true
 *         d) break the check and return false if (c) fails.

Approach 2:
===========
Singly Linked list
Logic: a) Traverse the list and add all the values to an array. 
 *         b) will find the size of the array 
 *         c) from middle point compare the values both sides, If successful return true
 *         d) break the check and return false if (b) fails.

*******************************************************************************/

#include <iostream>

using namespace std;

class dnode 
{
    public:
       int data;
       dnode *left;
       dnode *right;
    public:
       dnode(int arr[],int length);
       dnode();
       void printList();
       bool isPalindrome();
};

class snode 
{
    public:
       int data;
       snode *next;
    public:
       snode(int arr[],int length);
       snode();
       void printList();
       bool isPalindrome();
};

/*****
 * Method : snode Class constructor 
 * Arugumnets : NULL
 * ****/
 
 snode::snode()
 {
     data=0;
     next=NULL;
 }
 
 snode::snode(int arr[], int length)
 {
     data=arr[0];
     snode *parent=this;
     
     for(int i=1;i<length;i++)
     {
       snode *newNode=new snode();

       newNode->data=arr[i];
       parent->next=newNode;
       parent=newNode;
     }
 }

/*****
 * Method : snode Class constructor 
 * Arugumnets : NULL
 * ****/
 
 dnode::dnode()
 {
     data=0;
     left=NULL;
     right=NULL;
 }
 
 dnode::dnode(int arr[], int length)
 {
     data=arr[0];
     dnode *parent=this;
     
     for(int i=1;i<length;i++)
     {
       dnode *newNode=new dnode();

       newNode->data=arr[i];
       parent->right=newNode;
       newNode->left=parent;
       parent=newNode;
     }
 }
 

 
/********
 * Method:  print Doubly Linked List 
   Return : void
   functionality : display the values in the Doubly link list
 ********/

void dnode::printList()
{
    dnode *current=this;
    while(current!=NULL)
    {
        std::cout << current->data <<"  ";
        current=current->right;
    }
}
 
/********
 * Method:  print Singly Linked List 
   Return : void
   functionality : display the values in the Doubly link list
 ********/

void snode::printList()
{
    snode *current=this;
    while(current!=NULL)
    {
        std::cout << current->data <<"  ";
        current=current->next;
    }
}


/********************
 * Method : 
 * Return : bool
 * functionality : check whether the given doubly link list is a palindrome.
 * Logic : a) Traverse the list to find the last element. 
 *         b) check first(head pointer) and last element(tail pointer). 
 *         c) inc head pointer and dec tail pointer to compare the value. Till it reaches the middle point, If successful return true
 *         d) break the check and return false if (c) fails.
 * *****************/
bool dnode::isPalindrome()
{
    if(this == NULL) return 0;
    
    dnode *current=this;
    dnode *tail=NULL;
    while(current->right!=NULL)
    {
        current=current->right;
    }
    tail=current;
    current=this;

    while(current!=tail && tail->right!=current) // odd size palindrome will meet at the same address, even size palindrome cross over middle.
    {
        if(current->data!=tail->data)
              return 0;
        current=current->right;
        tail=tail->left;
    }
    return 1;
}

/********************
 * Method : 
 * Return : bool
 * functionality : check whether the given Singly link list is a palindrome.
 * Logic : a) Traverse the list and add all the values to an array. 
 *         b) will find the size of the array 
 *         c) from middle point compare the values both sides, If successful return true
 *         d) break the check and return false if (b) fails.
 * *****************/
bool snode::isPalindrome()
{
    if(this == NULL) return 0;
    
    snode *current=this;
    int length=0,arr[15];
    
    while(current!=NULL)
    {
        arr[length]=current->data;
        current=current->next;
        length++;
    }

    int leftIndex,rightIndex;
    if (length%2==0) 
     { 
           rightIndex=length/2;
           leftIndex=rightIndex-1;
     }
     else
     {
         rightIndex=(length/2)+1;
         leftIndex=rightIndex-2;
     }

    while(leftIndex>=0 && rightIndex<length)
    {
        if(arr[leftIndex]!=arr[rightIndex]) 
            return 0; // Not palindrome
        
        leftIndex--;
        rightIndex++;
    }
    
    return 1; //All values are checked- yes palindrome
}


int main()
{
//     int arr[]={4,6,7,2,3,1};
//     int arr[]={4,6,7,7,6,4};
     int arr[]={4,6,7,6,4};
     //int arr1[]={5,4,6,8,4,5};
     int arr1[]={5,4,6,6,4,5};
     
     int length=sizeof(arr)/sizeof(arr[0]);
     dnode *dhead=new dnode(arr,length);
     
     //dhead->printList();     
     bool palindromeFlag=dhead->isPalindrome();
     if(palindromeFlag) cout<<"Horray Doubly linkedlist It is a palindrome\n";
     else cout<<"Doubly linkedlist  NOT palindrome \n";
     
     length=sizeof(arr1)/sizeof(arr1[0]);
     snode *shead=new snode(arr1,length);
     
     //shead->printList();     
     palindromeFlag=shead->isPalindrome();
     if(palindromeFlag) cout<<"Horray Singly linkedlist It is a palindrome";
     else cout<<"Singly linkedlist NOT palindrome";
     
     
}
