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

void flatten(Node* root) {

    Node* curr = root;

    while(curr != NULL) {

        //find predecessor
        if(curr->left) {
            Node* pred = curr->left;
            while(pred != NULL) {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        } 
    }

    curr = curr -> left;

}