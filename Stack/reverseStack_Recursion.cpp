#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &stack, int n) {

    //base case
    if(stack.empty()) {
        stack.push(n);
    }

    int num = stack.top();
    stack.pop();
    
    //recursive call
    insertAtBottom(stack, n);

    stack.push(num);
}

void reverseStack(stack<int> &stack) {

    //base case
    if(stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();

    //recursive call
    reverseStack(stack);

    insertAtBottom(stack, num);
}