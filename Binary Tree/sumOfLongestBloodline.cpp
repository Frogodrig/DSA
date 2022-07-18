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

void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {

    //base case
    if(root == NULL) { //maybe the path has ended (Not mandatory as: root->left == NULL but root->right!=NULL)

        if(len > maxLen) {
            maxLen = len;
            maxSum = sum;
        }

        else if(len == maxLen) {
            maxSum = max(sum, maxSum);
        }

        return;
    }

    sum = sum + root -> data;
    solve(root->left, sum, maxSum, len+1, maxLen);
    solve(root->right, sum, maxSum, len+1, maxLen);
}

int sumOfLongRootToLeafPath(Node* root) {
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = INT16_MIN;

    solve(root, sum, maxSum, len, maxLen);

    return maxSum;
}