
#include <stdio.h>
#include <stdlib.h>


int findSingleOcc(int arr[],int s,int e,int noe)
{
    
   // printf(" Start : %d   End : %d   noe : %d ", s,e,noe);

 
    if(s<0 || e>noe || s>noe || e<0 ||s>e) return -999; 

    if(s==e) return arr[s];
    
    int b= s+(e-s)/2; 
 
    if((b==0 && arr[b]!=arr[b+1]) || (b==noe-1 && arr[b]!=arr[b-1])) // first and last element of original array
              return arr[b];
    else if(s!= 0 && !(arr[s]==arr[s-1] || arr[s]==arr[s+1])) // we already have index s,e.. O(1) check.. instead of recursion call 
              return arr[s];
    else if(e!= noe-1 && !(arr[e]==arr[e-1] || arr[e]==arr[e+1]))
              return arr[e];
              
    else if(b!=0 && arr[b]==arr[b-1])
         {
          if((b-2-s+1)%2!=0)         e=b-2;  // check in left array if it has odd number of elements
          else if((e-b+1+1)%2!=0)    s=b+1;  // check in right array if it has odd number of elements
         }
    else if(b!=noe-1 && arr[b]==arr[b+1])
         {
          if((b-1-s+1)%2!=0)       e=b-1; 
          else if((e-b+2+1)%2!=0)  s=b+2; 
         }
   
   return findSingleOcc(arr,s,e,noe); //left or right odd array is called 
}

int main()
{
   //int arr[]={1,1, 3, 3, 4, 4, 5, 5,7,7, 8, 8, 9,9,10}; //10
   //int arr[]={11,11, -3, -3, 4, 4, 5, 5,-7,-7, 8,8,10}; //10
    //int arr[]={1, 3, 3, 4, 4, 5, 5,7,7, 8, 8,10,10}; //1
   int arr[]={1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8}; //4
    const int noe=sizeof(arr)/sizeof(arr[0]);
    int fe=-999;
    if(noe%2==0) 
      printf("Even number of elements in the sorted array. No Single occ");   
    else 
      fe=findSingleOcc(arr,0,noe-1,noe);
    printf("Element that appears once : %d",fe);
    return 0;
}
