Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.
The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.
Example 1:
Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:
Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:
Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:
Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.

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
    
    int findHeight(TreeNode *root, int level)
    {
        if(root==NULL) 
            return level;
        int lh=findHeight(root->left,level+1);
        int rh=findHeight(root->right,level+1);
        
        return max(lh,rh);
    }
    
    int widthOfBinaryTree(TreeNode* root) {

        if(root==NULL)
            return 0;
        int level[100][2]; //level will be the index

        int height=findHeight(root,0);
        //initilize level array
        level[0][0]=0; //Start index of level 0
        level[0][1]=0; // end index of level 0
        int i;
      // cout<<"\n height : "<<height;
        for(i=1;i<height;i++)
        {
            level[i][0]=2*level[i-1][0]+1;
            level[i][1]=2*level[i-1][1]+2;
        }
        int size=level[i-1][1];
        TreeNode *binTree[100000];
        binTree[0]=root;
        
        int cnt=1,
            enqueue=1,
            dequeue=0;
        TreeNode *currNode;
      // cout<<"\n Size : "<<size;
        while(cnt<size)
        {
            currNode=binTree[dequeue++];
            if(currNode==NULL)
            {
                binTree[enqueue++]=NULL;
                binTree[enqueue++]=NULL;
            }
            else
            {
                binTree[enqueue++]=currNode->left;
                binTree[enqueue++]=currNode->right;                
            }
            cnt+=2;
        }
        
        //update level boundaries
        int iStart,
            iEnd,
            width=0,
            levelWidth=0;
    
        for(int i=0;i<height;i++) //find first and last not NULL node
        {
            iStart=level[i][0];
            iEnd=level[i][1];
            
            while(binTree[iStart]==NULL)
                iStart++;
            while(binTree[iEnd]==NULL)
                iEnd--;
            
            level[i][0]=iStart;
            level[i][1]=iEnd;
            
            levelWidth=iEnd-iStart+1;
            
            width=max(width,levelWidth);
        }
 
        return width;
    }
};
