
#include <stdio.h>
#include <iostream>
using namespace std;
class linkedListNode
{

   char value;
   linkedListNode *next;

 public:
   linkedListNode()
   {
       value=' ';
       next=NULL;
   }
   
   linkedListNode(char val){
       value=val;
       next=NULL;
   }
   
   linkedListNode(char valueArray[],int size)
   {
       linkedListNode *head=this;
                       head->value=valueArray[0];    
       linkedListNode *prevNode=head;
       for(int i=1;i<size;i++)
       {
          linkedListNode *newNode=new linkedListNode(valueArray[i]);
          prevNode->next=newNode;
          prevNode=newNode;
       }
   }
   /*****
    * Method : isPalindrome
    * returns : bool Value whether the given linked list is a palindrome or NOT
    * Logic : i will iterate the linkedlist with 2 pointers slowPointer and fastPointer initially pointing to head,
    *        1)slowPointer moves one node at a time and fastPointer moves 2 nodes at a time, slow pointer values are pushed in a stack.
    *        2)when fastPointer reaches the end node fastPointer is pointing to NULL(even size list) or last Node (odd size list) 
    *        3)by this time half my list will be in the stack. 
    *        4) will iterate the slow pointer till it reaches the tail and check with stack values.stack will hold the reversed half list
    * 
    * Time complexity O(n)
    * space complexity O(n/2)~=O(n)
    *****/
   bool isPalindrome()
   {
       linkedListNode *head=this;
       linkedListNode *slowPointer=head,
                      *fastPointer=head;
       char charStack[10];
       int pushIndex=0,
           popIndex=0;
       
       while(fastPointer!=NULL && fastPointer->next!=NULL)
       {
           charStack[pushIndex++]=slowPointer->value;
           slowPointer=slowPointer->next;
           fastPointer=fastPointer->next->next;
       }
       popIndex=pushIndex-1;
       if(fastPointer!=NULL) 
            slowPointer=slowPointer->next;
            
       while(slowPointer!=NULL && popIndex>-1)
       {
           if(slowPointer->value!=charStack[popIndex--])
              return false;
           slowPointer=slowPointer->next;
       }

       if(popIndex>-1) return false;
       return true;
   }
   
};
int main()
{
//    char valueArray[]={'A','B','C','D','D','C','B','A'};
//    char valueArray[]={'A','B','C','D','C','B','A'};
    char valueArray[]={'A','B','E','D','C','B','A'};

    int size=sizeof(valueArray)/sizeof(valueArray[0]);

    linkedListNode *head=new linkedListNode(valueArray,size);
    bool isPlaindromeFlag=head->isPalindrome(); 
    if(isPlaindromeFlag)
        cout<<"Given linked list is a palindrome !!!";
    else
        cout<<"Given linked list is NOT a palindrome";
    return 0;
}
