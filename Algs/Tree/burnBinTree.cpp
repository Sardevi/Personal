/******************************************************************************

Burn the binary tree starting from the target node
Given a binary tree and target node. By giving the fire to the target node and fire starts to spread in a complete tree. The task is to print the sequence of the burning nodes of a binary tree.
Rules for burning the nodes : 
Fire will spread constantly to the connected nodes only.
Every node takes the same time to burn.
A node burns only once.
Examples:
Input : 
                       12
                     /     \
                   13       10
                          /     \
                       14       15
                      /   \     /  \
                     21   24   22   23
target node = 14

Output :
14
21, 24, 10
15, 12
22, 23, 13

Explanation : First node 14 burns then it gives fire to it's 
neighbors(21, 24, 10) and so on. This process continues until 
the whole tree burns.


Solution:
========
Space Complecity : O(2n) call stack + queue = O(n)
time Complecity : O(n) traverse all the node 
Logic:
=======
Target to next node possibilites left,right child and parent node.
1. traversing from root to target node using DFS, which will have all the parents in call stack.
2. when the node matches the target value, i will add its children to queue 
3. if target found in left tree or right tree other sibiling is added to the queue and break the recursive call. 
4. will iterate 
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
   int burnTree(node* currNode, int target, queue<node*>& q)
   {
        
       if(currNode == NULL)
       {
           return 0;
       }
         // cout<<" \n currNode :: "<<currNode->val<<endl;

       if(currNode->val==target)
       {
       //    cout<<"I am in Target :: \n"<<target;
           cout<<currNode->val<<endl;
           if(currNode->left!=NULL)
               q.push(currNode->left);
           if(currNode->right!=NULL)
               q.push(currNode->right);
           return 1;
       }
       int leftTreeRes=burnTree(currNode->left,target,q);
       
       if(leftTreeRes==1)
       {
           int qSize=q.size();
           while(qSize>0)
           {
               node* tempNode=q.front();
               cout<<tempNode->val<<",";
               if(tempNode->left!=NULL)
                 q.push(tempNode->left);
               if(tempNode->right!=NULL)
                 q.push(tempNode->right);
               q.pop();     
               qSize--;
           }
           
           // adding the right tree in the queue, so no need for recursive call, while loop will read the right tree.
           if(currNode->right!=NULL)
             q.push(currNode->right);
        
           cout<<currNode->val<<endl;
           return 1;     

       }

       int rightTreeRes=burnTree(currNode->right,target,q);
       
       if(rightTreeRes==1)
       {
           int qSize=q.size();
           while(qSize>0)
           {
               node* tempNode=q.front();
               cout<<tempNode->val<<",";
               if(tempNode->left!=NULL)
                 q.push(tempNode->left);
               if(tempNode->right!=NULL)
                 q.push(tempNode->right);
               q.pop();     
               qSize--;
           }
           // adding the left tree in the queue, so no need for recursive call, while loop will read the right tree.
           if(currNode->left!=NULL)
             q.push(currNode->left);
           
           cout<<currNode->val<<endl;
           return 1;     
       }
   }
  
}; // class
int main()
{
    node* root=new node(12);
    queue<node*> q;
    
    root->left=new node(13);
    root->right=new node(10);
    root->right->left=new node(14);
    root->right->right=new node(15);

    root->right->left->left=new node(21);
    root->right->left->right=new node(24);

    root->right->right->left=new node(22);
    root->right->right->right=new node(23);


    root->burnTree(root,14,q);

    
    int qSize=q.size();
    
    while(qSize>0)
     {
       node* tempNode=q.front();
       cout<<tempNode->val;
       q.pop();     
       if(qSize>1)
         cout<<",";
       else
         cout<<endl;
       qSize--;
     }
    
}
