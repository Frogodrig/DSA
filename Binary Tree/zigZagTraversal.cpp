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

vector<int> zigZagTraversal(Node* root) {

    vector<int> result;
    if(root == NULL) {
        return result;
    }

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()) {

        int size = q.size();
        vector<int> ans(size);

        //Level Process
        for(int i=0;i<size;i++) {
            Node* frontNode = q.front();
            q.pop();

            //normal insert or reverse insert
            int index = leftToRight ? i : size - i - 1; 
            ans[index] = frontNode -> data;

            if(frontNode -> left) {
                q.push(frontNode -> left);

            } 

            if(frontNode -> right) {
                q.push(frontNode -> right);
            }
        }

        //Direction change
        leftToRight = !leftToRight;

        for(auto i: ans) {
            result.push_back(i);
        }
    }

    return result;
}

