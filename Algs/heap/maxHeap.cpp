/******************************************************************************
Max Heap :: Array Implementation
=========
Solution
============
Implementing maxHeap

Step 1: Add the value to the leaf node(add to the end of the array)
Step 2: Check with its parent
     a: If value is less than or equal to parent value. Tree is complete
     b: if value is greater than the parent value ,swap and repeat step 2 till 2.a is satisfied

Logic:
======
left_child = 2 * parent + 1
right_child = 2 * parent + 2

*******************************************************************************/

#include <iostream>

using namespace std;
/******
Method: buildMaxHeap
Return : void
Input arguments : given integer array and length of the given array **
functionality : build a maxHeap in an array with
                left_child = 2 * parent + 1
                right_child = 2 * parent + 2

***************************************/
void buildMaxHeap(int arr[],int length)
{
    int maxHeap[10];
    int currentI=0,parentI=0,tempValue=0;
    for(int arrayI=0,heapI=0;arrayI<length;arrayI++,heapI++)
    {
        maxHeap[heapI]=arr[arrayI]; // Add data to the leaf node
        
        currentI=heapI;
        while(currentI>0)
        {
            if(currentI%2==0) // current added node is a right child
              parentI=(currentI-2)/2;
            else // left child
              parentI=(currentI-1)/2;
              
            if(maxHeap[currentI]>maxHeap[parentI]) // swap the values
             {
                tempValue=maxHeap[currentI];
                maxHeap[currentI]=maxHeap[parentI];
                maxHeap[parentI]=tempValue;
                currentI=parentI;
             }
             else
               break; // Parent is greater than all its children, Its safe to move on as the tree is complete
        }
        
        
    }
    
    std::cout << "Max Heap :: ";
    for(int i=0;i<length;i++)
       cout<< maxHeap[i] << "  ";
}
 

int main()
{
    int arr[]={7,2,10,5,15,43,7,1,9};
    int length=sizeof(arr)/sizeof(arr[0]);
    buildMaxHeap(arr,length);
}
