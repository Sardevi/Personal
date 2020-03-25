Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.
Example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.

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
    int minDepth(TreeNode* root) {
     
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) //leaf node
            return 1;
        int ld=minDepth(root->left);
        int rd=minDepth(root->right);
        
        if(ld==0) ld=rd;
        if(rd==0) rd=ld;// if treeRoot dont have a child
        
        return min(ld,rd)+1;
    }
};

