Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.  (The values of the nodes may still be duplicates.)
Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.
The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.
The right-most node is also defined by the same way with left and right exchanged.
Example 1
Input:
  1
   \
    2
   / \
  3   4

Ouput:
[1, 3, 4, 2]

Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
So order them in anti-clockwise without duplicates and we have [1,3,4,2].
 
Example 2
Input:
    ____1_____
   /          \
  2            3
 / \          / 
4   5        6   
   / \      / \
  7   8    9  10  
       
Ouput:
[1,2,4,7,8,9,10,6,3]

Explanation:
The left boundary are node 1,2,4. (4 is the left-most node according to definition)
The leaves are node 4,7,8,9,10.
The right boundary are node 1,3,6,10. (10 is the right-most node).
So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].



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
    void leftBoundary(TreeNode* root, vector<int> &leftB, TreeNode*& llastNode)
    { 
        if(root==NULL) return;
        if(root->left!= NULL) 
        {
            leftB.push_back(root->left->val);
            llastNode=root->left; //last leftmost leaf Node
        }
        leftBoundary(root->left,leftB,llastNode);
        if(root->right!=NULL && root->left==NULL) 
        {
            leftB.push_back(root->right->val);
            llastNode=root->right;
            leftBoundary(root->right,leftB,llastNode);
        }
        return;
    }

    void rightBoundary(TreeNode* root, vector<int> &rightB, TreeNode*& rlastNode)
    {
        if(root==NULL) return;
        if(root->right!= NULL) 
        {
            rightB.push_back(root->right->val);
            rlastNode=root->right;
        }
        rightBoundary(root->right,rightB,rlastNode);
        if(root->right==NULL && root->left!=NULL) 
        {
            rightB.push_back(root->left->val);
            rlastNode=root->left;
            rightBoundary(root->left,rightB,rlastNode);
        }
        return;
    }
    
    void leafBoundary(TreeNode* root, vector<int> &leafB, TreeNode*& firstLeafNode, TreeNode*& lastLeafNode)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            leafB.push_back(root->val);
            if(firstLeafNode==NULL) firstLeafNode=root;
              lastLeafNode=root;
        }
        leafBoundary(root->left,leafB,firstLeafNode,lastLeafNode);
        leafBoundary(root->right,leafB,firstLeafNode,lastLeafNode);
}

    vector<int> boundaryOfBinaryTree(TreeNode* root) {

        vector<int> boundary;
        vector<int> rightB;
        vector<int> leafB;
        if(root==NULL) return boundary;
        TreeNode *llastNode=NULL,
                 *rlastNode=NULL,
                 *firstLeafNode=NULL,
                 *lastLeafNode=NULL;
        
        boundary.push_back(root->val);
        if(root->left == NULL) 
            llastNode=root;
        else
            leftBoundary(root,boundary,llastNode);
        
        leafBoundary (root, leafB, firstLeafNode, lastLeafNode) ;
             
        int i=0;
        if(llastNode==firstLeafNode) i++;
        // cout<<"\n llastNode : "<<llastNode->val;
        // cout<<"\n firstLeafNode : "<<firstLeafNode->val;
        int size=leafB.size();
        while(i<size)
        {
            boundary.push_back(leafB[i]);
            i++;
        }
        
        if(root->right != NULL)
        rightBoundary(root,rightB,rlastNode);
        i=rightB.size()-1;
        if(rlastNode==lastLeafNode) i--;

        
        while(i>-1)
        {
            boundary.push_back(rightB[i]);
            i--;
        }
        
        return boundary;
    }
};
