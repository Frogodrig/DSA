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

Node* minVal(Node* root) {
    Node* temp = root;

    while(temp->left != NULL) {
        temp = temp->left;
    }

    return temp;
}

Node* maxVal(Node* root) {
    Node* temp = root;

    while(temp->right != NULL) {
        temp = temp->right;
    }

    return temp;
}

Node* deleteFromBST(Node* root, int val) {
    //base case
    if(root == NULL) {
        return root;
    }

    if(root->data == val) {
        //0 children
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if(root->left != NULL and root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->right != NULL and root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 childern
        if(root->left != NULL and root->right != NULL) {

            //option 1
            //replace with minimum value from right subtree
            int mini = minVal(root->right) -> data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;

            //option 2
            //replace with maximum value from left subtree
            // int maxi = maxVal(root->left) -> data;
            // root->data = mini;
            // root->right = deleteFromBST(root->left, maxi);
            // return root;
        }
    }

    else if(root->data > val) {
        deleteFromBST(root->left, val);
    }

    else if(root->data < val) {
        deleteFromBST(root->right, val);
    }
}