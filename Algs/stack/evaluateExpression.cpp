/******************************************************************************
stack Problem 2
================
Evaluate an expression given only single digits and only 2 operators * and +.

created By: Saranyadevi Joseph

Solution
=========
Split the problem into *(Multiplication) and +(addition). Because * operation gets priority than +
Step 1: Iterate through the given expression and evaluate the * operations.
   A) Push all the values which require addition operation(+) in a integer stack
   B) Evaluate values which require * Multiplication operation and push their result in stack 
   C) All the integer values stored in the stack will be for addition
Step 2:
   Sum of the values in the stack will be the output

Runtime Complexity : O(n) + O(m), m=size of stack
==================
Space Complexity : O(m)
=================
*********************************************************************************/

#include <iostream>

using namespace std;
/* Class : intStack
 * Operations supported
 *    1) Push
 *    2) Pop
 *    3) Stack Size
 *    4) print stack
 */
class intStack
{
private:
    int arr[10];
    int headPtr=0;
public:
    intStack();
    int pop();
    void push(int value);
    void push(char value);
    intStack(int arr[],int length);
    void printStack();
    int stackSize();
};
   
 /* Method : stackSize 
  * Return : int - size of the stack */
   int intStack::stackSize()
   {
       return headPtr+1;
   }
/*Method :pop
 * returns : int - Top most value in the stack
 * Functionality : returns the remove the top most element in the stack  
 */ 
   int intStack::pop()
    {
    if(headPtr>=0) 
     {
        int value=arr[headPtr];
        arr[headPtr--]=0;
        return value;
     }
    }
  /* Method : push  
   * Return : void
   * input parameters : int Value 
   * Functionality : Adds the input value to the top of the stack
   * */ 
   void intStack::push(int value)
    {
        headPtr++;
        arr[headPtr]=value;
    }
  /* Method : push  
   * Return : void
   * input parameters : Char Value 
   * Functionality : Adds the input value after typecasting it into Integer. to the top of the stack
   * */ 
    void intStack::push(char value)
    {
        headPtr++;
        arr[headPtr]=value-'0';
    }

    /* Constructor : If a stack is provided*/
    intStack::intStack(int input_arr[10],int length)
    {
        for(int i=0;i<length;i++)
            arr[i]=input_arr[i];
        
        headPtr=length-1;
    }                             
    /* Constructor : To create a empty stack*/
    intStack::intStack()
    {
        for(int i=0;i<10;i++)
            arr[i]=0;
        headPtr=-1;
    }
    /*Method; printStack
     *Returns: Void
     *Functionality : display the content of the stack, Mainly used of debugging
     ***/
    void intStack::printStack()
    {
        cout<<"\n Stack  : "<<arr;
        cout<<"\n headPtr  : "<<headPtr;
    }

int main()
{
    
    //char arr[]="2*3+4*2";
    //char arr[]="2*3*4*2";
    //char arr[]="2+3*4*2";
    //char arr[]="2+3+4+2";
    //char arr[]="2+3+4*2";
    //char arr[]="3*4+2";
    char arr[]="3*2*4+2";


    int length=sizeof(arr)/sizeof(arr[0])-1;
    intStack expStack;
    int lsv=0;
    int rsv=0;
    int value=0;
    int i=0;
    while(i<length)
     {
        if(i==length-1)
           { 
               expStack.push(arr[i]);
               i++;
           }
        if(arr[i+1]=='*') 
           {
               lsv=arr[i]-'0';
               rsv=arr[i+2]-'0';
               value+=lsv*rsv;
               expStack.push(value);
               i+=3;
           }
        else if(arr[i+1]=='+')
           {
               expStack.push(arr[i]);
               expStack.push(arr[i+2]);
               i+=3;
           }       
        
        else if(arr[i]=='+')
           {
                i++;
           }
        else if(arr[i]=='*')
            {
                lsv=expStack.pop();
                rsv=arr[i+1]-'0';
                value+=lsv*rsv;
                expStack.push(value);
                i+=2;
            }
      //Reset values
      lsv=0;
      rsv=0;
      value=0;
     }          

 int stackSize=expStack.stackSize();
 value=0;
    for(i=0;i<stackSize;i++)
      value+=expStack.pop();
      
    cout<<"\n Given expression : "<<arr;
    cout<<"\n Output value : "<<value;
    
    return 0;
    
}

