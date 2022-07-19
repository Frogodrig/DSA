#include<iostream>
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

void inorder(Node* root, vector<int> &in) {

    if(root == NULL) 
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);    
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b) {

    vector<int> ans(a.size() + b.size());

    int i = 0;
    int j = 0;
    int k =0;

    while(i<a.size() and j<b.size()) {
        if(a[i] < b[j]) {
            ans[k++] = a[i++];

        } else {
            ans[k++] = a[j++];
        }
    }

    while(i<a.size()) {
        ans[k++] = a[i++];
    }

    while(j<b.size()) {
        ans[k++] = a[j++];
    }

    return ans;
}

Node* inorderToBST(int s, int e, vector<int> &in) {
    //base case
    if(s > e) {
        return NULL;
    }

    int mid = (s+e)/2;

    Node* root = new Node(in[mid]);
    root->left = inorderToBST(s, mid-1, in);
    root->right = inorderToBST(mid+1, e, in);

    return root;
}

//T.C = O(m+n) S.C = O(m+n)
// Node* mergeBST(Node* root1, Node* root2) {

//     //step 1: store inorder
//     vector<int> bst1, bst2;
//     inorder(root1, bst1);
//     inorder(root2, bst2);

//     //step 2: merge both sorted arrays
//     vector<int> mergedArray = mergeArrays(bst1, bst2);

//     //step 3: use merged inorder array to build BST
//     int s = 0;
//     int e = mergedArray.size() - 1;
//     return inorderToBST(s, e, mergedArray);
// }

Node* convertIntoDoublyLinkedList(Node* root, Node* &head) {

    //base case
    if(root == NULL) {
        return NULL;
    }

    convertIntoDoublyLinkedList(root->right, head);
    root->right = head;

    if(head != NULL) { //just because it may happen that there is no right subtree
        head->left = root;
    }

    head = root;

    convertIntoDoublyLinkedList(root->left, head);

    return head;
    
}

Node* mergeLinkedList(Node* head1, Node* head2) {

    Node* head = NULL;
    Node* tail = NULL;

    while(head1 != NULL and head2 != NULL) {
        if(head1->data < head2->data) {
            if(head == NULL) {
                head = head1;
                tail = head1;
                head1 = head1->right;

            } else {
                tail->right = head1;
                head1->left = tail; //beacuse its a Doubly LL
                tail = head1;
                head1 = head1->right;

            }

        } else {
            if(head == NULL) {
                head = head2;
                tail = head2;
                head2 = head2->right;

            } else {
                tail->right = head2;
                head2->left = tail; //beacuse its a Doubly LL
                tail = head2;
                head2 = head2->right;

            }

        }
    }

    while(head1 != NULL) {
        tail->right = head1;
        head1->left = tail; //beacuse its a Doubly LL
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL) {
        tail->right = head2;
        head2->left = tail; //beacuse its a Doubly LL
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL) {
        cnt++;
        temp = temp->right;
    }

    return cnt;
}

Node* sortedLLtoBST(Node* &head, int n) {

    //base case
    if(n <= 0 or head == NULL) {
        return NULL;
    }

    Node* Left = sortedLLtoBST(head, n/2);
    Node* root = head;
    root->left = Left;

    head = head->right;

    root->right = sortedLLtoBST(head, n-n/2-1);

    return root;
}


//optimized approach S.C = O(h1 + h2)
Node* mergeBST(Node* root1, Node* root2) {

    //step1: convert BST into sorted Doubly LL
    Node* head1 = NULL;
    convertIntoDoublyLinkedList(root1, head1);
    head1->left = NULL;

    Node* head2 = NULL;
    convertIntoDoublyLinkedList(root2, head2);
    head2->left = NULL;

    //step2: merge sorted Doubly LL
    Node* head = mergeLinkedList(head1, head2);

    //step3: convert sorted Doubly LL to BST
    return sortedLLtoBST(head, countNodes(head));
}