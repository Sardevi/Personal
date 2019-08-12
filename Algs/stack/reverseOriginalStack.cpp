/******************************************************************************
stack Problem 3
================
Reverse a stack and put the reversed value back in the same stack. 
You can use only one other stack and a temp variable.

Solution
========
1.Have 2 integer stacks. 1 input and 1 to processing. and one temp variable.
2.Iterate a loop to the size of the given stack. Each time -1 element will be read from the input stack
3.A) pop and copy the top element in the stack to temp varable
  B) pop and store the rest in the Processing stack till the input stack is empty
  c) Push the temp variable into input stack followed by the all the values in the processing stack
  D) repeat step 3, for -1 elements 

Runtime Complexity : O(n)*O(2(n-1))=O(2n^2)
Space Complexity : O(2n)
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
};

/*Method :pop
 * returns : int - Top most value in the stack
 * Functionality : returns and the remove the top most element in the stack  
 */ 

    char charStack::pop()
    {
    if(headPtr>=0) 
     {
        char value=arr[headPtr];
        arr[headPtr--]=' ';
        return value;
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
    /* Method :printStack
       Returns : Void
       Functionality : Display the content of the stack
    */
    void charStack::printStack()
    {
        cout<<"\n Stack  : "<<arr;
        cout<<"\n headPtr  : "<<headPtr;
    }

int main()
{
    
    char arr[]="ABC1234";
    int length=sizeof(arr)/sizeof(arr[0])-1;
    charStack s1=charStack(arr,length);
    
    charStack s2;
    
    char tempVar;
    cout<<length<<endl;
    s1.printStack();
    s2.printStack();
    
    
     for(int i=0;i<length;i++)
     {
        tempVar=s1.pop();
        for(int j=i+1;j<length;j++)
        {
          s2.push(s1.pop());
        }
        s1.push(tempVar);
        for(int j=i+1;j<length;j++)
        {
            s1.push(s2.pop());
        }
    }
    
    s1.printStack();
    return 0;
}
