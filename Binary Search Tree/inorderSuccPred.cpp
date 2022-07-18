#include<iostream>
#include<queue>
using namespace std;

class Node {

    public: 
        int data;
        Node* left;
        Node* right;

   Node(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
   }     

};

void findPreSuc(Node* root, Node*& pre, Node*& suc, int data)
{
    // Base case
    if (root == NULL)  return ;
  
    // If data is present at root
    if (root->data == data)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
  
        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            Node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
  
    // If data is smaller than root's data, go to left subtree
    if (root->data > data)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, data) ;
    }
    else // go to right subtree
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, data) ;
    }
}