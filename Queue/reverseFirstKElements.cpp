#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {

    //pop first k elements from Q and push into stack;
    stack<int> s;

    for(int i=0; i<k; i++) {
        s.push(q.front());
        q.pop();
    }

    //fetch the elements from the stack and push into Q
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    //fetch the first n-k from the Q and push them to the back
    for(int i=0; i<q.size()-k; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}