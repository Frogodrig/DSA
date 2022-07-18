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

int findPosition(int in[], int element, int n) { //this can be optimized by using map to obtain position in O(1) time

    for(int i=0; i<n; i++) {
        if(in[i] == element) {
            return i;
        }
    }

    return -1;
}

void createMapping(int in[], map<int, int> &nodeToIndex, int n) { 

    for(int i=0; i<n; i++) {
        nodeToIndex[in[i]] = i;
    }

}

Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex) {

    //base case
    if(index >= n || inorderStart > inorderEnd) {
        return NULL;
    }

    //create a root node for element
    int element = pre[index++];
    Node* root = new Node(element);
    //find element index in inorder
    // int position = findPosition(in, element, n);
    int position = nodeToIndex[element];

    //recursive calls
    root -> left = solve(in, pre, index, inorderStart, position-1, n, nodeToIndex);
    root -> right = solve(in, pre, index, position+1, inorderEnd, n, nodeToIndex);

    return root;
}


Node* buildTree(int in[], int pre[], int n) {

    int preOrderIndex = 0;
    map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);
    //create nodes to index mapping
    Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n, nodeToIndex);

    return ans;
}