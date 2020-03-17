/******************************************************************************

Given a binary tree, return the zigzag level order traversal of its nodes' values.
(ie, from left to right, then right to left for the next level and alternate between).
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
  12  
  10    13  
  14    15  
  23    22    24    21  

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

// stack 
/*
   time complexity O(n);
   space complexity O(n); // iterated node is stored in stack 
   
   Logic:
   ======
   I will store the nodes in the stack, using NULL as level boundry, every time a level is read,
   depends on which level will push node from left to right or right to left traversal order. 
   next level will be read again fom top of the stack. repeat till all the nodes in a level have no children.
  
*/

  void zigZagOrderTravesal (node * root)
  {
    node *binTree[50];
    if (root == NULL)
      return;

    binTree[0] = root;
    binTree[1] = NULL;		// break the level stack to pop

    int nChildrenInLevel = 1, pop = 0, push = 2, level = 1;	//root will be in level 0

    while (nChildrenInLevel > 0)
      {
	nChildrenInLevel = 0;
	while (pop > -1 && binTree[pop] != NULL)
	  {
	    node *currNode = binTree[pop--];
	    if (level % 2 == 0)	//even levels left then right
	      {
		if (currNode->left != NULL)
		  {
		    binTree[push++] = currNode->left;
		    nChildrenInLevel++;
		  }
		if (currNode->right != NULL)
		  {
		    binTree[push++] = currNode->right;
		    nChildrenInLevel++;
		  }
	      }
	    else		//odd levels right then left
	      {
		if (currNode->right != NULL)
		  {
		    binTree[push++] = currNode->right;
		    nChildrenInLevel++;
		  }
		if (currNode->left != NULL)
		  {
		    binTree[push++] = currNode->left;
		    nChildrenInLevel++;
		  }

	      }
	  }
	pop = push - 1;
	binTree[push++] = NULL;
	level++;
      }

    for (int i = 0; i < push - 1; i++)
      {
	if (binTree[i] == NULL)
	  {
	    std::cout << std::endl;
	  }
	else
	  {
	    cout << "  " << binTree[i]->val << "  ";
	  }
      }
    return;
  }

};



int
main ()
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


  root->zigZagOrderTravesal (root);


  return 0;
}
// returning as Vector object
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       TreeNode *binTree[100000];
       binTree[0]=root; //root level=0;
       binTree[1]=NULL;
       int level=1,
           push=2,
           pop=0;
        
       int levelNode=1;
 
       vector<vector<int>> binTreeVal;
       if(root!=NULL) 
       {
           binTreeVal.resize(1);
           binTreeVal[0].resize(1);
       }
        while(levelNode>0)
        {
            levelNode=0;          
            while(pop>-1 && binTree[pop]!=NULL)
            {
              TreeNode* currNode=binTree[pop--];
               if(level%2==0) //left to right
               {
                   if(currNode->left!=NULL)
                   {   
                       levelNode++;
                       binTree[push++]=currNode->left;
                   }
                   if(currNode->right!=NULL)
                   {   
                       levelNode++;
                       binTree[push++]=currNode->right;
                   }
               }
               else
               {
                   if(currNode->right!=NULL)
                   {   
                       levelNode++;
                       binTree[push++]=currNode->right;
                   }
                   if(currNode->left!=NULL)
                   {   
                       levelNode++;
                       binTree[push++]=currNode->left;
                   }
               }
                    
        //      cout<<"\n currentNode : "<<currNode->val;  
            }
        
        pop=push-1;
        binTree[push++]=NULL; //To break the level
        level++;
        if(levelNode>0) 
        {
            binTreeVal.resize(level);
          //  cout<<"\nlevel : " << level;
            binTreeVal[level-1].resize(levelNode);          
        }
        
       }

    //push index will have number of elements in binTree
    for(int i=0,col=0,row=0;i<push-1;i++)
    {
        if(binTree[i]==NULL)
        {
            row++;
            col=0;
            //cout<<endl;
            continue;
        }
        else
        {
           binTreeVal[row][col++]=binTree[i]->val;
           //cout<<"  "<<binTree[i]->val<<"  ";
        }
    }

     return binTreeVal;
    }
};
