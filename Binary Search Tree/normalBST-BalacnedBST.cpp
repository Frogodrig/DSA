#include<iostream>
#include<queue>
#include<vector>
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

Node* inorderToBST(int s, int e, vector<int> &inorderVal) {
    //base case
    if(s > e) {
        return NULL;
    }

    int mid = (s+e)/2;
    Node* root = new Node(inorderVal[mid]);
    root->left = inorderToBST(s, mid-1, inorderVal);
    root->right = inorderToBST(mid+1, e, inorderVal);

    return root;
}

Node* balancedBST(Node* root, int target) {
    vector<int> inorderVal;
    inorder(root, inorderVal);
    
    return inorderToBST(0, inorderVal.size()-1, inorderVal);
}