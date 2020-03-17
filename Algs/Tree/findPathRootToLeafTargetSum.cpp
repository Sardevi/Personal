/******************************************************************************
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
Note: A leaf is a node with no children.
Example:
Given the below binary tree and sum = 57,
      12
     / \
    13   10
        /   \
       14    15
       / \   / \
      21 24  22 23  
return true, as there exist a root-to-leaf path 12->10->14->21 which sum is 57. and print the path
*******************************************************************************/
#include <stdio.h>

#include <bits/stdc++.h> 

using namespace std;
class node

{

public:

    int val;

    node* left;

    node* right;

public:

   node()
   {
       val=0;
       left=NULL;
       right=NULL;
   }

   node(int value)
   {
       val=value;
       left=NULL;
       right=NULL;
   }
   bool findPath(node* currNode, int sum, int& pathValue)
   {
       
       if(currNode==NULL)
       {
           return false;
       }
  
       pathValue+=currNode->val;
       if(currNode->left==NULL && currNode->right==NULL) //Leaf currNode
       {
           if(pathValue==sum)
           {
                std::cout<<"Path : "<<currNode->val<<" <= "; 
                return true;
           }
          pathValue = pathValue - currNode->val;
          return false;
       }
       bool rightPathFound=false;
       bool leftPathFound=findPath(currNode->left,sum,pathValue);
       if(!leftPathFound)
       {
          rightPathFound=findPath(currNode->right,sum,pathValue);
       }
       if(leftPathFound==false && rightPathFound==false)
        {   
          pathValue-=currNode->val;
          return false;
        } 
       //Either left or right path exists
       std::cout<<currNode->val<<" <= ";

       return true;
   }//findPath
};

int main()
{
  node* root=new node(12);
//int sum=25;
//int sum=59;
int sum=60;
//int sum=57;
    queue<node*> q;

    root->left=new node(13);
    root->right=new node(10);
    root->right->left=new node(14);
    root->right->right=new node(15);

    root->right->left->left=new node(21);
    root->right->left->right=new node(24);

    root->right->right->left=new node(22);
    root->right->right->right=new node(23);


    int pathValue=0;
    bool pathFound=root->findPath(root,sum,pathValue);
    if(pathFound)
      std::cout <<  "Path from Root" << std::endl;
    else
      std::cout << "Path Not found " << std::endl;
    return 0;
}
