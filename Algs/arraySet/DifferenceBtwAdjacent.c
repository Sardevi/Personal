/******************************************************************************
solved by : Saranyadevi Joseph
Problem 5 : 
=============
Search an element in an array where difference between adjacent elements is 1.
For example: arr[] = {8, 7, 6, 7, 6, 5, 4, 3, 2, 3, 4, 3}
Search for 3 and Output: Found at index 7  .

solution
==========
Linear search
1.As there can be duplicates, we will find the first index found with adjacent
elements diff of 1
2.element in index 0(first) and numOfElements-1(last) have only one adjacent
elements. index (1,2,...numOfElements-2) is considered first then first and
last element 

Runtime complexity
==================
Best case O(n)
worst case O(n)

Space complexity: O(1)
*******************************************************************************/

#include <stdio.h>

/* Method : findElementIndex
   return : index of the Element to be found 
   arguments : Given integer array, Number of elements in the array (int) ,
Element(int)
to be found      
*/
int findElementIndex(int arr[], int numOfElements, int element)
{

  for(int i=1; i<numOfElements-1; i++) // first priority for element with 2 adjacent elements
   {
    if(element==arr[i] && (arr[i]-arr[i-1]==1 || arr[i-1]-arr[i]==1) 
                 && (arr[i]-arr[i+1]==1 || arr[i+1]-arr[i]==1))
                    
    return i;
   }
   
  //first and last element
  if(arr[0]==element && (arr[1]-arr[0]==1 || arr[0]-arr[1]==1)) return 0;
  else
  if(arr[numOfElements-1]==element && (arr[numOfElements-2]-arr[numOfElements-1]==1 || arr[numOfElements-1]-arr[numOfElements-2]==1)) return numOfElements-1;

 return -999;   
}

int main()
{
    int index=-999;
    int arr[]={8, 7, 6, 7, 6, 5, 4, 3, 2, 3, 4, 3};
    int element=-999;
    printf("Enter Element to be found : ");
    scanf("%d",&element);
    
    int numOfElements=sizeof(arr)/sizeof(arr[0]);
    index=findElementIndex(arr,numOfElements,element);
    if(index==-999) printf("Element (%d) not found" ,element);
    else
      printf("Element ( %d ) found at index ( %d ) .",element,index);
    return 0;
}
