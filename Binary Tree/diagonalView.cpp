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

vector<int> diagonal(Node* root) {

    queue<Node*> q;
    vector<int> ans;

    //base case
    if(root == NULL) {
        return ans;
    }

    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        while(temp) {
            ans.push_back(temp->data);

            if(temp->left) {
                q.push(temp->left);
            }

            temp = temp-> right;
        }
    }

    return ans;
}