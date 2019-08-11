
/******************************************************************************


Solved and developed by : Saranyadevi Joseph

Problem 1
=========
Find the element that appears once in a sorted array where all other elements appear twice one after another. Find that element in 0(logn) complexity.
Input:   arr[] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8}
Output:  4      


Solution
========
Binary Search
1. Find middle index in the given array, Check middle index element and its adjacent. If found once return element
2. Only one element occurs once and other twice, so will split the array into
check only odd length array using recursive call.
3. corner cases
  A. first and last index [0 and numOfElemnts-1] will have only one adjacent to
check
  B. Single element array   

Run time Complexity
===================
Best case O(logn)
worst case O(logn)

space Complexity : O(logn) recursion call  

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Method : findSingleOcc
   Returns : Element that appears oncce
   Arguments : Input integer array, start search Index, end search index,
numof Elements in input array */

  
int findSingleOcc(int arr[],int startIndex,int endIndex,int numOfElements)
{
      
    if(startIndex<0 || endIndex>numOfElements || startIndex>numOfElements ||
endIndex<0 ||startIndex>endIndex) return -999; //Not found

    if(startIndex==endIndex) return arr[startIndex]; // Single element array
    
    int midIndex= startIndex+(endIndex-startIndex)/2; 
 
    if((midIndex==0 && arr[midIndex]!=arr[midIndex+1]) || (midIndex==numOfElements-1 && arr[midIndex]!=arr[midIndex-1])) // first and last element of original array
              return arr[midIndex];
    else if(startIndex!= 0 && !(arr[startIndex]==arr[startIndex-1] || arr[startIndex]==arr[startIndex+1])) // we already have index startIndex,endIndex.. O(1) check.. instead of recursion call 
              return arr[startIndex];
    else if(endIndex!= numOfElements-1 && !(arr[endIndex]==arr[endIndex-1] || arr[endIndex]==arr[endIndex+1]))
              return arr[endIndex];
              
    else if(midIndex!=0 && arr[midIndex]==arr[midIndex-1])
         {
          if((midIndex-2-startIndex+1)%2!=0)         endIndex=midIndex-2;  // check in left array if it has odd number of elements
          else if((endIndex-midIndex+1+1)%2!=0)    startIndex=midIndex+1;  // check in right array if it has odd number of elements
         }
    else if(midIndex!=numOfElements-1 && arr[midIndex]==arr[midIndex+1])
         {
          if((midIndex-1-startIndex+1)%2!=0)       endIndex=midIndex-1; 
          else if((endIndex-midIndex+2+1)%2!=0)  startIndex=midIndex+2; 
         }
   
   return findSingleOcc(arr,startIndex,endIndex,numOfElements); //left or right odd array is called 
}

int main()
{
   //int arr[]={1,1, 3, 3, 4, 4, 5, 5,7,7, 8, 8, 9,9,10}; //10
   //int arr[]={11,11, -3, -3, 4, 4, 5, 5,-7,-7, 8,8,10}; //10
   //int arr[]={1, 3, 3, 4, 4, 5, 5,7,7, 8, 8,10,10}; //1
   // int arr[]={1};//1
    int arr[]={1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8}; //4
    const int numOfElements=sizeof(arr)/sizeof(arr[0]);
    int oddElement=-999;
    if(numOfElements%2==0) 
      printf("Even number of elements in the sorted array. No Single occ");   
    else 
      oddElement=findSingleOcc(arr,0,numOfElements-1,numOfElements);
    printf("Element that appears once : %d",oddElement);
    return 0;
}
