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

Node* buildTree(Node* root) {

    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1) {
        return NULL;
    }

    cout<<"Enter data for left node: "<<data<<endl;
    root -> left = buildTree(root->left);
    cout<<"Enter data for right node: "<<data<<endl;
    root -> right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL); //separator

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { //purana level completely traversed
            cout<<endl;

            if(!q.empty()) { 
                q.push(NULL);
            }

        } else {
            cout<<temp -> data<<" ";
            if(temp -> left != NULL) {
                q.push(temp->left);
            }

            if(temp -> right != NULL) {
                q.push(temp->right);
            }

        }

        
    }
}

void reverseLevelOrderTraversal(Node* root) {
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    q.push(NULL); //separator

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        s.push(temp);

        if(temp == NULL) { //purana level completely traversed
            if(!q.empty()) { 
                q.push(NULL);
            }

        } else {
            if(temp -> right != NULL) { //Difference: in levelOrder we process left then right child
                q.push(temp->right);
            }

            if(temp -> left != NULL) {
                q.push(temp->left);
            }

        }
    }

    while(!s.empty()) {
        Node* temp = s.top();
        s.pop();

        if(temp == NULL) {
            cout<<endl;

        } else {
            cout<<temp->data<<" ";

        }
    }
}

void inorder(Node* root) {
    //Base Case
    if(root == NULL) {
        return;
    }

    inorder(root -> left);
    cout<<root -> data<<" ";
    inorder(root -> right);
}

void preorder(Node* root) {
    //Base Case
    if(root == NULL) {
        return;
    }

    cout<<root -> data<<" ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(Node* root) {
    //Base Case
    if(root == NULL) {
        return;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout<<root -> data<<" ";
}

Node* buildFromLevelOrder(Node* root) {
    queue<Node*> q;
    cout<<"Enter data for root: "<<endl;
    int data;cin>>data;

    if(data == -1) {
        return NULL;
    }
    
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left node of:  "<<temp->data<<endl;
        int leftData;cin>>leftData;

        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node of:  "<<temp->data<<endl;
        int rightData;cin>>rightData;

        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp->right);
        }
    }

    return root;
}

int main() {
    Node* root = NULL;

    // Node* levelOrderCreation = buildFromLevelOrder(root);

    //creating a Tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"Printing the level order traversal output "<<endl;
    levelOrderTraversal(root);

    cout<<endl<<endl;

    cout<<"Printing the reverse level order traversal output "<<endl;
    reverseLevelOrderTraversal(root);

    cout<<endl<<endl;

    cout<<"Inorder traversal is: ";
    inorder(root);

    cout<<endl<<endl;

    cout<<"Preorder traversal is: ";
    preorder(root);

    cout<<endl<<endl;
    cout<<"Postorder traversal is: ";
    postorder(root);

    cout<<endl<<endl;

    return 0;
}
