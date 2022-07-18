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

void traverseLeft(Node* root, vector<int> &ans) {
    //base case
    if((root == NULL) || (root -> left == NULL and root -> right == NULL)) {
        return;
    }

    ans.push_back(root -> data);
    if(root -> left) {
        traverseLeft(root -> left, ans);

    } else {
        traverseLeft(root -> right, ans);

    }
}

void traverseLeaf(Node* root, vector<int> &ans) {
    //base case
    if(root == NULL) {
        return;
    }
    if(root -> left == NULL and root -> right == NULL) {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node* root, vector<int> &ans) {
    //base case
    if((root == NULL) || (root -> left == NULL and root -> right == NULL)) {
        return;
    }

    if(root -> right) {
        traverseRight(root -> right, ans);

    } else {
        traverseRight(root -> left, ans);
    }

    //wapas aane pe store
    ans.push_back(root -> data); // storing at last because we need the reverse of right part
}

vector<int> boundary(Node* root) {

    vector<int> ans;
    if(root == NULL) {
        return ans;
    }

    ans.push_back(root -> data);

    //process left part
    traverseLeft(root -> left, ans);

    //process leaf nodes
    //left subtree
    traverseLeaf(root -> left, ans);
    //right subtree
    traverseLeaf(root -> right, ans);

    //process right part
    traverseRight(root -> right, ans);

    return ans;
}