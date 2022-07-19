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

void inorder(Node* root, vector<int> &in) {

    if(root == NULL) 
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);    
}

Node* flatten(Node* root) {

    vector<int> inorderVal;
    inorder(root, inorderVal);
    int n = inorderVal.size();

    Node* newRoot = new Node(inorderVal[0]);

    Node* curr = newRoot;

    for(int i=0; i<n; i++) {

        Node* temp = new Node(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr -> left = NULL;
    curr -> right = NULL;

    return newRoot;

}