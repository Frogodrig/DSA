#include<iostream>
#include<queue>
#include<stack>
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

void inOrder(Node* root, int &count) {
     if(root == NULL) {
          return;
     }

     inOrder(root->left, count);
     if(root -> left == NULL and root -> right == NULL) {
          count++;
     }
     inOrder(root->right, count);
}

int noOfLeafNodes(Node* root) {
     int cnt = 0;
}