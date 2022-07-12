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

// void reverse1(Node* &head, Node* curr, Node* prev) {

//     if(curr == NULL) {
//         head = prev;
//         return;
//     }

//     Node* forward = curr -> next;
    
//     reverse1(head, forward, curr);

//     curr -> next = prev;
// }

void insertAtTail(Node* &head, Node* &tail, int val) {

    Node* temp = new Node(val);

    if(head == NULL) {
        head = temp;
        tail = temp;
        return;

    } else {

        tail -> next = temp;
        tail = temp;

    }
}

Node* reverse(Node* head) {

    if(head == NULL || head -> next == NULL) {
        return head;
    }

    Node* smallHead = reverse(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return smallHead;
}

Node* add(Node* first, Node* second) {

    int carry = 0;
    int sum = 0;
    int digit = 0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;


    while(first!= NULL || second!=NULL || carry!=0) {

        int val1 = 0;
        if(first != NULL) {
            val1 = first -> data;
        }

        int val2 = 0;
        if(second != NULL) {
            val2 = second -> data;
        }

        sum = carry + val1 + val2;
        digit = sum%10;

        //create node and add in ans LL
        insertAtTail(ansHead, ansTail, digit);

        carry = sum/10;

        if(first!=NULL) {
            first = first -> next;
        }

        if(second != NULL) {
            second = second -> next;
        }
    }


    // while(first!= NULL && second!=NULL) {

    //     sum = carry + first -> data + second -> data;
    //     digit = sum%10;

    //     //create node and add in ans LL
    //     insertAtTail(ansHead, ansTail, digit);

    //     carry = sum/10;

    //     first = first -> next;
    //     second = second -> next;
    // }

    // while(first != NULL) {
    //     sum = carry + first -> data;

    //     digit = sum%10;

    //     //create node and add in ans LL
    //     insertAtTail(ansHead, ansTail, digit);

    //     carry = sum/10;
    //     first = first -> next;
    // }

    // while(second != NULL) {
    //     sum = carry + second -> data;

    //     digit = sum%10;

    //     //create node and add in ans LL
    //     insertAtTail(ansHead, ansTail, digit);

    //     carry = sum/10;
    //     second = second -> next;
    // }

    // while(carry != 0) {
    //     sum = carry;

    //     digit = sum%10;

    //     //create node and add in ans LL
    //     insertAtTail(ansHead, ansTail, digit);

    //     carry = sum/10;
    // }

    return ansHead;

}

Node* addTwoLists(Node* first, Node* second) {

    //reverse the LLs
    first = reverse(first);
    second = reverse(second);

    //Add the LLs
    Node* ans = add(first, second);

    //reverse the ans LL
    ans = reverse(ans);

    return ans;
}