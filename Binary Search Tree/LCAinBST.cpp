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

//Recursive approach
Node* LCAinBST(Node* root, Node* P, Node* Q) {

    if(root == NULL) {
        return NULL;
    }

    if(root->data < P->data and root->data > Q->data) {
        return LCAinBST(root->right, P, Q);
    }

    if(root->data > P->data and root->data > Q->data) {
        return LCAinBST(root->left, P, Q);
    }

    return root;
}

//iterative approach
Node* LCAinBST(Node* root, Node* P, Node* Q) {

    Node* temp = root;

    while(temp != NULL) {

        if(temp->data < P->data and temp->data < Q->data) {
            temp = temp->right;

        }

        else if(temp->data > P->data and temp->data > Q->data) {
            temp = temp->left;

        }

        else {
            return temp;
            
        }
    }

}