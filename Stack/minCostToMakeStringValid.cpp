#include<iostream>
#include<stack>
using namespace std;

int findMinimumCost(string str) {

    //odd length string
    if(str.length() & 1) {
        return -1;
    }

    stack<char> s;
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];

        if(ch == '{') {
            s.push(ch);

        } else { //ch is '}'

            if(!s.empty() and s.top() == '{') {
                s.pop();

            } else {
                s.push(ch);

            }
        }
    }

    //stack now contains an invalid expression
    int a = 0; //count of closed brace
    int b = 0; //count of open brace

    while(!s.empty()) {
        if(s.top() == '{') {
            b++;

        } else {
            a++;

        }

        s.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;

    return ans;
}