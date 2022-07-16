#include<iostream>
#include<queue>
#include<stack>
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

pair<bool, int> isSumTreeFast(Node* root) {

    //base case
    if(root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    //leaf node check
    if(root -> left == NULL and root -> right == NULL) {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = isSumTreeFast(root -> left);
    pair<bool, int> rightAns = isSumTreeFast(root -> right);

    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;

    bool condn = root -> data == leftAns.second + rightAns.second;

    pair<bool, int> ans;

    if(isLeftSumTree and isRightSumTree and condn) {
        ans.first = true;
        ans.second = root -> data + leftAns.second + rightAns.second; // or 2*root->data

    } else {
        ans.first = false;
        //ans.second wont matter as ans.first is false
    }

    return ans;
}


bool isSumTree(Node* root) {

    return isSumTreeFast(root).first;
}