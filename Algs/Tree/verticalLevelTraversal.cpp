
You are given a binary tree for which you have to print its vertical order traversal. your task is to complete the function verticalOrder which takes one argument the root of the binary tree and prints the node of the binary tree in vertical order as shown below.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal.

Note: This question is tagged as BST because to solve the questions efficiently, we need to use an ordered map (map in C++ and TreeMap in Java).  The ordered maps are mainly implemented using self-balancing-BST.
Input Format:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 
The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.
For example:
 
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N
Output Format:
For each testcase, the vertical order traversal of the tree is to be printed. The nodes' data are to be separated by spaces.
Your Task:
This is a function problem. Your task is to just complete the verticalOrder() function and you don't have to take any input or output. The newline is automatically appended by the driver code.
Constraints:
1 <= T <= 100
1 <= Number of nodes <= 5000
Example:
Input:
3
2 N 3 4 N
1 2 3 4 5 N 6
3 1 5 N 2 4 7 N N N N 6  
Output:
2 4 3
4 2 1 5 3 6
1 3 2 4 5 6 7
Explanation:
Testcase1:
         2
           \
            3
            /
         4
As it is evident from the above diagram that during vertical traversal 2, 4 will come first, then 3. So output is 2 1 5 3
Testcase2:
             1
           /     \
         2       3
      /     \        \
    4       5       6
As it is evident from the above diagram that during vertical traversal 4 will come first, then 2, then 1,5, then 3 and then 6. So the output is 4 2 1 5 3 6.

#include <stdio.h>
#include <map> 
#include <vector> 
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
  
  void verticalTraversal(node* root, map<int,vector<int>> &verOrder, int verLevel)
  {
      if(root==NULL) //exit
         return;
    
      verOrder[verLevel].push_back(root->val);
      verticalTraversal(root->left,verOrder,verLevel-1); 
      verticalTraversal(root->right,verOrder,verLevel+1);
     
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
 
  map<int,vector<int>> verOrder;
  root->verticalTraversal(root,verOrder,0);
 
  map<int,vector<int>>::iterator itr;
  int minVerticalLevel=0,
      maxVerticalLevel=0;
  for(itr=verOrder.begin();itr!=verOrder.end();itr++)
  {
      minVerticalLevel=min(minVerticalLevel,itr->first);
      maxVerticalLevel=max(maxVerticalLevel,itr->first);
  }
  
  for(int i=minVerticalLevel;i<=maxVerticalLevel;i++)
  {
      cout<<"\n vertical level :: "<<i<<"\n";
      vector<int> res=verOrder.find(i)->second;
      int j=0,
          size=res.size();
      for(j=0;j<size-1;j++)
      {
          cout<<res[j]<<",";
      }
      if(j<size) cout<<res[j];
  }
  
  return 0;
}
