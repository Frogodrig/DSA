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

vector<int> verticalOrder(Node* root) {

    map<int, map<int, vector<int>>> nodes; //map<H.D. , map<lvl, nodeList>>
    queue<pair<Node*, pair<int, int>>> q;  //queue<pair<Node*, pair<H.D, lvl>>>
    vector<int> ans;

    if(root == NULL) {
        return ans;
    }

    q.push(make_pair(root, make_pair(0, 0)));

    while(!q.empty()) {
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left) {
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
        }

        if(frontNode->right) {
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }
        
    }

    for(auto i: nodes) {
        //i -> <int, map<int, vector<int>>>
        for(auto j: i.second) {
            //j -> <int, vector<int>>
            for(auto k: j.second) {
                ans.push_back(k);
            }
        }
    }

    return ans;
}