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
        
        return max(ld,rd)+1;
    }
};
