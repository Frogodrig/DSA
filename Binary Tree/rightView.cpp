#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

void solve(Node* root, vector<int> &ans, int level) {
    //base case
    if(root == NULL) {
        return;
    }

    //Reached new level
    if(level == ans.size()) {
        ans.push_back(root->data);
    }

    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);
}

vector<int> leftView(Node* root) {

    vector<int> ans;
    solve(root, ans, 0);

    return ans;
}