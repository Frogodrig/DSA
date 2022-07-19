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

int solve(Node* root, int &i, int k) {

    //base case
    if(root == NULL) {
        return -1;
    }

    //L
    int left = solve(root->left, i, k);

    if(left != -1) {
        return left;
    }

    //N
    i++;
    if(i == k) {
        return root->data;
    }

    //R
    return solve(root->right, i, k);

}


int kthSmallest(Node* root, int k) {
    int i = 0;
    int ans = solve(root, i, k);

    return  ans;
}