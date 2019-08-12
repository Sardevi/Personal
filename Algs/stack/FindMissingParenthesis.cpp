/******************************************************************************
Stack Problem 1
===============
Created by : Saranyadevi Joseph
Find missing parenthesis in a given expression – 2 * ( 3 + 5(sasdfasdfasd)

Solution
==========
1. Create a character Stack. Will iterate through the given expression. which takes O(n) runtime complexity
2. i will add only '(' open parenthesis in the stack. will pop the stack when ')' is read from the expression
3. Final check. A)if size of the stack not Zero. ')' is missing
		B)If Step 2 pop operation fails '(' is missing

Complexity
===========
Runtime Complexity :O(n)
Space Complexity : constant

*******************************************************************************/

#include <iostream>

using namespace std;

/* Class : CharStack
 * Operations supported
 *    1) Push
 *    2) Pop
 *    3) Stack Size
 *    4) print stack
 */
class charStack
{
private:
    char arr[10];
    int headPtr=0;
public:
    charStack();
    char pop();
    void push(char value);
    charStack(char arr[],int length);
    void printStack();
    int charStackSize();
};

 /* Method : stackSize 
  * Return : int - size of the stack */
   
   int charStack::charStackSize()
   {
       return headPtr+1;
   }

/*Method :pop
 * returns : int - Top most value in the stack
 * Functionality : returns the remove the top most element in the stack  
 */ 
   
 char charStack::pop()
    {
    if(headPtr>=0) 
     {
        char value=arr[headPtr];
        arr[headPtr--]=' ';
        return value;
     }
     else
     {
         return ')'; //Error value ')' dont exist in the stack
     }
        
    }

  /* Method : push  
   * Return : void
   * input parameters : Char Value 
   * Functionality : Adds the input value to the top of the stack
   * */ 

    void charStack::push(char value)
    {
        headPtr++;
        arr[headPtr]=value;
    }
    /* Constructor : If a stack is provided*/

    charStack::charStack(char input_arr[10],int length)
    {
        for(int i=0;i<length;i++)
            arr[i]=input_arr[i];
        
        headPtr=length-1;
    }                             
    /* Constructor : To create a empty stack*/

    charStack::charStack()
    {
        headPtr=-1;
    }
    void charStack::printStack()
    {
        cout<<"\n Stack  : "<<arr;
        cout<<"\n headPtr  : "<<headPtr;
    }

int main()
{
    
    char arr[]="– 2 * ( 3 + 5(sasdfasdfasd)";
    int length=sizeof(arr)/sizeof(arr[0])-1;
    charStack parStack;
    bool closeParaFlag=0;
    
    for (int i=0;i<length;i++)
     {
         if(arr[i]=='(') 
              parStack.push(arr[i]);
         else if (arr[i]==')' && parStack.pop()==')') 
               {
                    cout<<"( is Missing in the Expression";
                    closeParaFlag=1;
                    break;
               }
     }
     
     int stackSize=parStack.charStackSize();
     
     if (stackSize==0 && closeParaFlag==0)
       cout<<"No Missing Parenthesis";
     else if(stackSize>0)
       cout<<stackSize<<" - ) are Missing in the Expression";
    
    return 0;
    
}

