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

bool isBST(Node* root, int min, int max) {
    //base case
    if(root == NULL) {
        return true;
    }

    if(root->data >= min && root->data <= max) {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;

    } else {
        return false;
    }
}

bool validateBST(Node* root) {

    return isBST(root, INT16_MIN, INT16_MAX);
}