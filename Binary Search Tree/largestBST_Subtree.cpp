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

class info {
    public: 
        int maxi;
        int mini;
        bool isBST;
        int size;
};

info solve(Node* root, int &ans) {

    //base case
    if(root == NULL) {
        return {INT_FAST16_MIN, INT_FAST16_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if(left.isBST and right.isBST and (root->data > left.maxi && root->data < right.mini)) {
        currNode.isBST = true;

    } else {
        currNode.isBST = false;

    }

    //answer update
    if(currNode.isBST) {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

int largestBST(Node* root) {
    int maxSize = 0;
    info temp = solve(root, maxSize);

    return maxSize;
}