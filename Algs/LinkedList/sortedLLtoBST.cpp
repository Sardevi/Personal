Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
Example:
Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
 
 ====================
Solution :
=======
   1)find the middle element in the given linked list, will be the root of the BST,
   2)recursively call the function to for left list and right list 
      a) left list = head to middle-1 elements
      b) right list = middle+1 to tail element
   3) form the left sub tree then right sub tree and using call stack will connect it to the current root. 
======
Space Complexity : O(n) call stack
Time Complexity : O(nlogn) to find middle element + O(n) for reading all the middle nodes
===================

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedLinkedListToBST(ListNode* head,ListNode* tail)
    {
        if(head==NULL)
            return NULL;
        if(head==tail || head->next==NULL)
        {
            TreeNode *bstNodehead=new TreeNode(head->val);
            return bstNodehead;
        }
        if(head->next==tail)
        {
          TreeNode *bstNodehead=new TreeNode(head->val);
          TreeNode *bstNodetail=new TreeNode(tail->val);  
          bstNodetail->left=bstNodehead;
          return bstNodetail;
        }   
        ListNode *slowPtrll=head,
                 *fastPtrll=head,
                 *prevSlowPtrll=NULL;
        
        while(fastPtrll!=NULL && fastPtrll->next!=NULL &&  fastPtrll!=tail && fastPtrll->next!=tail)
        {
            prevSlowPtrll=slowPtrll;
            slowPtrll=slowPtrll->next;
            fastPtrll=fastPtrll->next->next;
        }
        
        TreeNode *bstNode=new TreeNode(slowPtrll->val);
        bstNode->left=sortedLinkedListToBST(head,prevSlowPtrll);
        bstNode->right=sortedLinkedListToBST(slowPtrll->next,tail);
        
        return bstNode;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head==NULL)
             return NULL;
      
        return sortedLinkedListToBST(head,NULL);
    }
};
