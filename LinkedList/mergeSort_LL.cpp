//Why merge sort is preferred for LL and quick sort for arrays
//https://www.geeksforgeeks.org/why-quick-sort-preferred-for-arrays-and-merge-sort-for-linked-lists/

#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int data) {

        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        int value = this -> data;

        //Memory free
        if(this -> next != NULL) {
            delete next;
            next = NULL;
        }

        cout<<" Memory is free for node with data "<<value<<endl;
    }

    
};

Node* getMid(Node* head) {

    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL) {

        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}

Node* merge(Node* left, Node* right) {

    if(left == NULL) {
        return right;
    }

    if(right == NULL) {
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    //merge 2 sorted LL
    while(left != NULL && right != NULL) {

        if(left -> data < right -> data) {
            temp -> next = left;
            temp = left;
            left = left -> next;

        } else {

            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    while(left != NULL) {

        temp -> next = left;
        temp = left;
        left = left -> next;

    }

    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }

    ans = ans -> next;
 
    return ans;

}

//T.C = O(nlogn), S.C = O(logn)
Node* mergeSort(Node* head) {

    //base case
    if(head == NULL || head -> next  == NULL) {
        return head;
    }

    //find mid and divide the LL into 2 halves
    Node* mid = getMid(head);

    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;

    //recursive calls for both halves
    left = mergeSort(left);
    right = mergeSort(right);

    //merge both halves
    Node* result = merge(left, right);

    //return answer
    return result;
}