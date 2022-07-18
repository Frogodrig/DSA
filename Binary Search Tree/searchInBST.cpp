#include<iostream>
#include<queue>
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

//recursive approach
// bool searchInBST(Node* root, int x) {
//     //base case
//     if(root == NULL) {
//         return false;
//     }

//     if(root->data == x) {
//         return true;
//     }

//     if(root->data > x) {
//         searchInBST(root->left, x);

//     } else {
//         searchInBST(root->right, x);
//     }
// }

//iterative approach
bool searchInBST(Node* root, int x) {
    
    Node* temp = root;

    while(temp != NULL) {
        if(temp->data == x) {
            return true;
        }

        if(temp->data > x) {
            temp = temp->left;

        } else {
            temp = temp-> right;

        }
    }

    return false;
}