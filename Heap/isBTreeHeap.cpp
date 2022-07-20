#include<iostream>
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

int countNodes(Node* root) {
    //base case
    if(root == NULL) {
        return 0;
    }

    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    
    return ans;
}

bool isCBT(Node* root, int index, int count) {
    if(root == NULL) {
        return true;
    }

    if(index >= count) {
        return false;
    }

    else {
        bool left = isCBT(root->left, 2*index+1, count);
        bool right = isCBT(root->right, 2*index+2, count);

        return (left and right);
    }
}

bool isMaxOrder(Node* root) {
    //leaf node
    if(root->left == NULL and root->right == NULL) {
        return true;
    }

    //only left child
    if(root->right == NULL) {
        return (root->data > root->left->data);
    }

    //if both children exist
    else {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left and right and (root->data > root->left->data and root->data > root->right->data));
    }
}

bool isHeap(Node* root) {

    int index = 0;
    int totalCount = countNodes(root);

    if(isCBT(root, index, totalCount) and isMaxOrder(root)) {
        return true;

    } else {    
        return false;

    }
}