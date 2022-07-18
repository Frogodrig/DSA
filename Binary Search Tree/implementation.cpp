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

Node* insertIntoBST(Node* root, int data) {

    //base case
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root -> data) {
        root->right = insertIntoBST(root->right, data);

    } else {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(Node* &root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root) {
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {

        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            }

        } else {
            cout<<temp->data<<" ";

            if(temp->left) {
                q.push(temp->left);
            }

            if(temp->right) {
                q.push(temp->right);
            }
        }

    }

}

Node* minVal(Node* root) {
    Node* temp = root;

    while(temp->left != NULL) {
        temp = temp->left;
    }

    return temp;
}

Node* maxVal(Node* root) {
    Node* temp = root;

    while(temp->right != NULL) {
        temp = temp->right;
    }

    return temp;
}

int main() {

    Node* root = NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);

    cout<<"Printning the BST"<<endl;
    levelOrderTraversal(root);
}