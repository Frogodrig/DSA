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

vector<int> topView(Node* root) {
    vector<int> ans;

    //base case
    if(root == NULL) {
        return ans;
    }

    map<int, int> topNode; //mapping of H.D. and data of node
    queue<pair<Node*, int>> q; //pair of node and H.D.

    q.push(make_pair(root, 0));

    while(!q.empty()) {

        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if(frontNode->left) {
            q.push(make_pair(frontNode->left, hd-1));
        }

        if(frontNode->right) {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    for(auto i: topNode) {
        ans.push_back(i.second);
    }

    return ans;
}