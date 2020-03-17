#include<stdio.h>
#include<iostream>

/***
 * Problem: Build a balanced Tree and perform in,pre and post order traversal
 * ========
 * 
 * TimeComplexity : O(n), everynode is traversed once
 * SpaceComplexity: O(n), tree size
 * 
 * Logic:
 * =======
 * BuildTree: 1) building a tree from a given array, root=array[0](first value) where nodeIndex=0
 *               left child = 2*nodeIndex+1, right child =2*nodeIndex+2 
 *            2) one node is created per call and BuildTree is recursively called for everynode creation
 * 
 * Traversal : traversal method is Recursively called where node data is read in the below order          
 * inOrderTraversal : Starts with tree root. 
 *                    Order of node traversal
 *                         1) left
 *                         2) current
 *                         3) right
 * 
 * pre OrderTraversal : Starts with tree root. 
 *                    Order of node traversal
 *                         1) current
 *                         2) left
 *                         3) right
 
 * postOrderTraversal : Starts with tree root. 
 *                    Order of node traversal
 *                         1) left
 *                         2) right
 *                         3) current
 * * 
 * Sample Input :  arr[]={1,2,3,5,7,8,9};
 * Output : 
Pre OrderTraversal
  1  2  5  7  3  8  9
In OrderTraversal
  5  2  7  1  8  3  9
Post OrderTraversal
  5  7  2  8  9  3  1


 ***/
 
 
class node{
      int data;
      node* left;
      node* right;
    public:
      node()
      {
          data=-999;
          left=NULL;
          right=NULL;
      }
      node(int value)
      {
          data=value;
          left=NULL;
          right=NULL;
      }
      ~node()
      {
          std::cout << "Node is deleted" << std::endl;
      }

    node* buildTree(int arr[],int length,int current=0);
    void inOrderTraversal(node* currentNode);
    void preOrderTraversal(node* currentNode);
    void postOrderTraversal(node* currentNode);

};

/* Method : buildTree
   Class : node
   Arguments : int arr[], input data/values to build the tree
                int length, length of the given input array
                int currentIndex, index to the element for which the currentNode is created 
   Return : node pointer, pointer to the created New Node
   Logic:  1) building a tree from a given array, root=array[0](first value) where nodeIndex=0
              left child = 2*nodeIndex+1, right child =2*nodeIndex+2 
           2) one node is created per call and BuildTree is recursively called for everynode creation
*/

node* node::buildTree(int arr[],int length,int currentI)
{
    
    if(currentI>=length) return NULL;
    node *currentNode;
    if(currentI==0) 
    { 
        currentNode=this;
        currentNode->data=arr[currentI];
    }
    else
        currentNode=new node(arr[currentI]);

    currentNode->left=buildTree(arr,length,2*currentI+1);
    currentNode->right=buildTree(arr,length,2*currentI+2);

    return currentNode;
}

/***
 * Method : inOrderTraversal
 * Class : node
 * return : VOID
 * Arguments : node pointer, currentNode which is being read
 * Logic: traversal method is Recursively called where node data is read in the below order 
 *                         1) left
 *                         2) current
 *                         3) right
 ****/
void node::inOrderTraversal(node* currentNode)
{
    if(currentNode==NULL) return;

    inOrderTraversal(currentNode->left);
    std::cout<<"  "<<currentNode->data;
    inOrderTraversal(currentNode->right);
}
/***
 * Method : preOrderTraversal
 * Class : node
 * return : VOID
 * Arguments : node pointer, currentNode which is being read
 * Logic: traversal method is Recursively called where node data is read in the below order 
 *                         1) current
 *                         2) left
 *                         3) right
 ****/

void node::preOrderTraversal(node* currentNode)
{
    if(currentNode==NULL) return;
    
    std::cout<<"  "<<currentNode->data;
    preOrderTraversal(currentNode->left);
    preOrderTraversal(currentNode->right);
}
/***
 * Method : postOrderTraversal
 * Class : node
 * return : VOID
 * Arguments : node pointer, currentNode which is being read
 * Logic: traversal method is Recursively called where node data is read in the below order 
 *                         1) left
 *                         2) right
 *                         3) current
 ****/
void node::postOrderTraversal(node* currentNode)
{
    if(currentNode==NULL) return;
    
    postOrderTraversal(currentNode->left);
    postOrderTraversal(currentNode->right);
    std::cout<<"  "<<currentNode->data;

    return;
}

int main()
{
    int arr[]={1,2,3,5,7,8,9};
    int length=sizeof(arr)/sizeof(arr[0]);
    node *root=new node();
    root->buildTree(arr,length,0);
    std::cout<<"\nPre OrderTraversal\n";
    root->preOrderTraversal(root);
    std::cout<<"\nIn OrderTraversal\n";
    root->inOrderTraversal(root);
    std::cout<<"\nPost OrderTraversal\n";
    root->postOrderTraversal(root);

    return 1;
}
