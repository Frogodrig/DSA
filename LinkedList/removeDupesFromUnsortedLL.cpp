#include<iostream>
#include<map>
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

Node* removeDuplicates(Node* head) {

    if(head == NULL) {
        return NULL;
    }

    map<Node*, bool> visited;

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {

        if((curr -> next != NULL) && visited[curr] == true) {

            Node* nextNode = curr -> next;
            Node* nodetoDelete = curr;
            delete(nodetoDelete);
            prev -> next = nextNode;

        } else { // not equal

            visited[curr] = true;
            prev = curr;
            curr = curr -> next;

        }
    }

    return head;

}

//2 more approaches: O(n^2) method where we will traveserse the entire LL for any given element and a O(nlogn) method where we need to first sort the LL then apply removeDupesFromSortedLL algorithm