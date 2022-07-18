#include<iostream>
#include<queue>
#include<map>
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

void createMapping(int in[], map<int, int> &nodeToIndex, int n) {
    for(int i=0; i<n; i++) {
        nodeToIndex[in[i]] = i;
    }
}

Node* solve(int in[], int post[], int &index, int postOrderStart, int postOrderEnd, int n, map<int, int> &nodeToIndex) {

    //base case
    if(index < 0 or postOrderStart>postOrderEnd) {
        return NULL;
    }

    //create a root node for element
    int element = post[index--];
    Node* root = new Node(element);

    //find element's position in inorder
    int position = nodeToIndex[element];

    //recursive calls [In case of postorder and inorder, we first build the right subtree]
    root->right = solve(in, post, index, position+1, postOrderEnd, n, nodeToIndex);
    root->left = solve(in, post, index, postOrderStart, position-1, n, nodeToIndex);
    
    return root;
}

Node* buildTree(int in[], int post[], int n) {

    int postOrderIndex = n-1;
    map<int, int> nodeToIndex; 

    //create nodes to index mapping
    createMapping(in, nodeToIndex, n);

    Node* ans = solve(in, post, postOrderIndex, 0, n-1, n, nodeToIndex);

    return ans;
}