#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBrackets(string &s) {

    stack<char> st;

    for(int i=0; i<s.length() ; i++) {
        char ch =s[i];

        if(ch == '(' or ch == '+' or ch == '-' or ch == '*' or ch == '/') {
            st.push(ch);

        } else {

            //ch is a '(' or a lowercase letter

            if(ch == ')') {
                bool isRedundant = true;

                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' or top == '-' or top == '*' or top == '/' ) {
                        isRedundant = false;

                    }
                    st.pop();

                }

                if(isRedundant) {
                    return true;
                }
                st.pop();

            }
        }
    }

    return false;
}