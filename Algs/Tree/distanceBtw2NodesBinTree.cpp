


#include <stdio.h>
#include <iostream>
using namespace std;
/**

Find the distance between two keys in a binary tree, no parent pointers are given. 
Distance between two nodes is the minimum number of edges to be traversed to reach one node from other.
* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
Time Complexity : O(n)
Space Complexity : O(n)

Logic : distance from root to node1 + distance from root to node2 - 2*distance from root to LCS
*/
class TreeNode {
   public:
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode()
    {
        val=0;
        left=NULL;
        right=NULL;
    }
    TreeNode(int value)
    {
        val=value;
        left=NULL;
        right=NULL;
    }
    
    int distanceBtwNodes(TreeNode* root,TreeNode *node1,TreeNode *node2)
    {
        int distN1=findNodeLevel(root,node1,0);
        int distN2=findNodeLevel(root,node2,0);
        int distLCS=findNodeLevel(root,lowestCommonAncestor(root,node1,node2),0);
        
        return distN1+distN2-2*distLCS;
    }
    
    int findNodeLevel(TreeNode* currNode,TreeNode *node, int level)
    {
        int nodeLevel=-1;
        if(currNode==NULL || node==NULL)
          return nodeLevel;
        if(currNode==node)
          return level;
        nodeLevel=findNodeLevel(currNode->left,node,level+1);
        if(nodeLevel==-1)
           nodeLevel=findNodeLevel(currNode->right,node,level+1);
        return nodeLevel;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     
        if(root==NULL)
         return root;
        if(root==p || root==q)
            return root;
        
        TreeNode *leftAns=lowestCommonAncestor(root->left,p,q);
        TreeNode *rightAns=lowestCommonAncestor(root->right,p,q);
        
        if(leftAns != NULL && rightAns != NULL)
            return root; //success
        if(leftAns != NULL)
            return leftAns;
        if(rightAns != NULL)
            return rightAns;
        return NULL;

        }
};
int main()
{
    TreeNode *root=new TreeNode(50);
    
    root->left=new TreeNode(10);
    root->right=new TreeNode(20);
    root->left->left=new TreeNode(30);
    root->left->right=new TreeNode(45);
    root->right->left=new TreeNode(80);
    root->right->right=new TreeNode(90);
    root->left->right->right=new TreeNode(52);
    
    int dis=root->distanceBtwNodes(root,root->left->left,root->left->right->right);
    cout<<"Distance btw 2 Nodes 30 and 52 :: " <<dis;
    return 0;
}
