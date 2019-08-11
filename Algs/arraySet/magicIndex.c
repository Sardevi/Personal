/******************************************************************************
 *
Solved and developed by : Saranyadevi Joseph

Problem 2:
==========
A magic index in an array A[0…n-1] is defined to be an index such that A[i] = i. 
Given a sorted array of distinct integers, write a method to find a magic index if one exists, 
in an array A. FOLLOW UP: What if the values are not distinct?

Solution
=========
using Binary search 
if binary pointer index greater than its respectfull array value. in Next iteration will consider left array till current BinaryPointerIndex as tailPointerIndex
else right array from BinaryPointerIndex as headPointerIndex  

FOLLOW UP : solution will not works for non distinct array. iteration of O(n) will be needed
===========

Run time complexity:
===================
 Best case : O(logn)
 worse case : O(logn)
space complexity  : constant
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*
 * Method : findMagicNumberInSortedA
 * Return : integer MagicIndex 
 * arguments : Input integer array, headPtr intialized with zero, tail pointer intialized with last element index, numOfElements in input array  */

int findMagicNumberInSortedA(int arr[],int headPtr,int tailPtr,int numOfElements)
{

   int binPtr=0;
   int notFound=-999;
   while(binPtr>=headPtr && binPtr<=tailPtr)
   {
       binPtr=headPtr+round((tailPtr-headPtr)/2);
    
       if(headPtr<0 || tailPtr>numOfElements-1 || binPtr<0 || binPtr>numOfElements-1) return;
       if(tailPtr-headPtr==1)
           {
               if(arr[headPtr]==headPtr) return headPtr;
               else if(arr[tailPtr]==tailPtr) return tailPtr;
               return notFound;
           }
       if(arr[binPtr]==binPtr) return binPtr;
       else if(arr[binPtr]<binPtr) headPtr=binPtr;
       else if(arr[binPtr]>binPtr) tailPtr=binPtr;
   }
   return notFound;
}

int main()
{
   //int arr[]={-2,-1,0,3,5,7,8}; // 3
   //int arr[]={-2,1,3,5,7,8}; // 1
   //int arr[]={-2,-1,0,1,2,5}; // 5
   //int arr[]={0,2,3,5}; // 0
   
 //  int arr[]={-2,-1,3,5,7,8}; // no Match
   int arr[]={-2,-1,3,3,3,5,7,8}; // 3 non distinct
 
   int tailPtr=(sizeof(arr)/sizeof(arr[0]))-1;
   int headPtr=0;
   int magicIndex=findMagicNumberInSortedA(arr,headPtr,tailPtr,tailPtr+1);
   if(magicIndex==-999) 
	   printf("Magic Index not found");
   else printf("Magic index : %d",magicIndex);
   return 0;
}
