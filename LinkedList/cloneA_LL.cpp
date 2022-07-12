//Clone a linked list with next and random pointer
//GFG

#include<iostream>
#include<unordered_map>
using namespace std;

class Node {

    public:
    int data;
    Node* next;
    Node* random; 

    Node(int data) {

        this -> data = data;
        this -> next = NULL;
        this -> random = NULL;
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

void insertAtTail(Node* &head, Node* &tail, int data) {

    Node* newNode = new Node(data);

    if(head == NULL) {
        
        head = newNode;
        tail = newNode;
        return;

    } else {

        tail -> next = newNode;
        tail = newNode;
    }

}

//T.C = O(n), S.C = O(n)
//Using Map
// Node* copyList(Node* head) {

//     //Create a clone list without random pointers
//     Node* cloneHead = NULL;
//     Node* cloneTail = NULL;

//     Node* temp = head;

//     while(temp != NULL) {
//         insertAtTail(cloneHead, cloneTail, temp -> data);
//         temp = temp -> next;
//     }

//     //create a mapping
//     unordered_map<Node*, Node*> oldToNewNode;

//     Node* originalNode = head;
//     Node* cloneNode = cloneHead;
//     while(originalNode != NULL) {
//         oldToNewNode[originalNode] = cloneNode;
//         originalNode = originalNode -> next;
//         cloneNode = cloneNode -> next;
//     }

//     originalNode = head;
//     cloneNode = cloneHead;

//     while(originalNode != NULL) {
//         cloneNode -> random = oldToNewNode[originalNode -> random];
//         originalNode = originalNode -> next;
//         cloneNode = cloneNode -> next;
//     }

//     return cloneHead;
// }


//T.C = O(n), S.C = O(1)
//Changing Links
Node* copyList(Node* head) {

    //Step1: Create a clonelist without random pointers
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while(temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp -> data);
        temp = temp -> next;
    }

    //Step2: Add clone nodes in b/w the original list
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL) {
        Node* next = originalNode -> next;
        originalNode -> next = cloneNode;
        originalNode = originalNode -> next;

        next = cloneNode -> next;
        cloneNode -> next = originalNode;
        cloneNode = next;
    }

    //Step3: Copy random pointers
    temp = head;

    while(temp != NULL) {
        if(temp -> next != NULL) {
            if(temp -> random != NULL) {
                //The below statement is equivalent to the if-else statements :-
                //temp -> next -> random = temp -> random ? temp -> random -> next : temp -> random;

                temp -> next -> random = temp -> random -> next;
            }

        } else {

            temp -> next = temp -> random; // temp -> next = NULL;

        }

        temp = temp -> next -> next;
        
    }

    //Step4: Revert changes from step 2.
    originalNode = head;
    cloneNode = cloneHead;
    
    while(originalNode != NULL && cloneNode != NULL) {
        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;

        if(originalNode != NULL) {
            cloneNode -> next = originalNode -> next;
        }
        cloneNode = cloneNode -> next;
    }

    //Step5: Return cloneHead
    return cloneHead;

}


