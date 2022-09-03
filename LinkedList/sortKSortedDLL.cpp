#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {

    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {

        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
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

class compare {
    bool operator()(Node* first, Node* second) {
        return first->data > second->data;
    }

};

Node* sort(Node* head, int k) {

    if(head == NULL) {
        return head;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;
    Node* newHead = NULL;
    Node* curr = head;

    for(int i=0; head!= NULL and i<=k; i++) {//running till k+1 because range of 
        pq.push(head);
        head = head->next;
    }

    while(!pq.empty()) {
        
        if(newHead == NULL) {
            newHead = pq.top();
            newHead->prev = NULL;
            curr = newHead;

        } else {
            curr->next = pq.top();
            pq.top()->prev = curr;
            curr = pq.top();

        }

        pq.pop();

        if(head != NULL) {
            pq.push(head);
            head = head->next;
        }
    }

    curr->next = NULL;
    return newHead;
    
}