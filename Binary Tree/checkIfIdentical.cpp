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

bool isIdentical(Node* r1, Node* r2) {

    //base cases
    if(r1 == NULL and r2 == NULL) {
        return true;
    }
    if(r1 == NULL && r2 != NULL) {
        return false;
    }
    if(r1 != NULL && r2 == NULL) {
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if(left and right and value) {
        return true;

    } else {
        return false;
        
    }
}

