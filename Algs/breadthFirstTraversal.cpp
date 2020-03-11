/******************************************************************************
Level order traversal of a tree is breadth first traversal for the tree.

Example:
Given the below binary tree 
      12
     / \
    13   10
        /   \
       14    15
       / \   / \
      21 24  22 23  
      
OUTPUT :

 Level order traversal of binary tree is -  
12 13 10  null  null 14 15 21 24 22 23  null  null  null  null  null  null  null 


*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;
class node
{
public:
  int val;
  node *left;
  node *right;

public:
    node ()
  {
    val = 0;
    left = NULL;
    right = NULL;
  }
  node (int value)
  {
    val = value;
    left = NULL;
    right = NULL;
  }

// queue 
/*
   time complexity O(n);
   space complexity O(n); // iterated node is stored in queue 
   
  
*/

  void bfs (node * root)
  {
    node *binTree[50];
    if (root == NULL)
      return;
      
    binTree[0]=root;
    int dequeue=0,
        enqueue=1;
    
    while(dequeue<enqueue)
    {
        node* currNode=binTree[dequeue++];
        if(currNode==NULL) continue;
        binTree[enqueue++]=currNode->left;
        binTree[enqueue++]=currNode->right;
    }
    
    cout<<"\n Level order traversal of binary tree is -  \n";
    for(int i=0;i<enqueue-1;i++)
    {
        if(binTree[i]==NULL)
          cout<<" null ";
        else
          cout<<binTree[i]->val<<" ";
    }
    return;
  }
};



int main ()
{
  node *root = new node (12);
  root->left = new node (13);
  root->right = new node (10);

  root->right->left = new node (14);
  root->right->right = new node (15);

  root->right->left->left = new node (21);
  root->right->left->right = new node (24);

  root->right->right->left = new node (22);
  root->right->right->right = new node (23);


  root->bfs(root);


  return 0;
}
