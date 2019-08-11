/******************************************************************************

solved by : Saranyadevi Joseph
Problem 6
============
Given an array of numbers, split the array into two where one array 
contains the sum of n-1 numbers and the other array with all the n-1 elements..

Solution
=========
Linear check
1. find the sum of all the numbers in input array -  O(n)
2. check every element in the array, if the current element is equalTo sum of all the other elements in the array -  O(n)
3. if step 2 is successful spilt the array as nth and all other n-1 elements else print unsuccessful message.

Runtime complexity
=================
Best and worst case: O(2n)
Space complexity : O(1)
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*
 * Method : splitArray
 * return : void
 * arguments : input integer array, n as number of elements in the input array*/
void spiltArray(int arr[],int n)
{
    int nthE=0;
    int nthFlag=0;
    int sum_n=0;
    
    printf("\n Array 2 \n All the n-1 elements : ");
    for(int i=0;i<n;i++)
    {
        sum_n+=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        if(sum_n-2*arr[i]==0) { nthE=arr[i]; nthFlag=1;}
        else
        printf(" %d , ",arr[i]);
    }
    if (nthFlag==1) 
       printf("\n Array 1 \n Sum of n-1 numbers : %d", nthE);
    else
       printf("\nArray 1 is Empty\n Spliting Array was not Successful. Not able to find the nth element whose value = sum of n-1 number");
}
int main()
{
    int arr[]={1,3,4,5,13}; //13
    // int arr[]={-1,-2,3,0}; //0
     //int arr[]={-1,-2,3,1}; //Not successful
    const int n=sizeof(arr)/sizeof(arr[0]);
    spiltArray(arr,n);
    return 0;
}
