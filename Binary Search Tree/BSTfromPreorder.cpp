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

Node* solve(vector<int> &preorder, int mini, int maxi, int &i) {

    if(i >= preorder.size()) {
        return NULL;
    }

    if(preorder[i] < mini || preorder[i] > maxi) {
        return NULL;
    }

    Node* root = new Node(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);

    return root;
}

Node* preorderToBST(vector<int> &preorder) {
    int mini = INT_FAST16_MIN;
    int maxi = INT_FAST16_MAX;

    int i=0;
    return solve(preorder, mini, maxi, i);
}