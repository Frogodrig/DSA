#include<iostream>
#include<stack>
using namespace std;

bool isValidParenthesis(string expression) {

    stack<char> s;

    for(int i=0; i<expression.length(); i++) {

        char ch = expression[i];

        //if openening bracket, push
        if(ch == '(' || ch == '{' || ch == '[') {
            
            s.push(ch);

        } else {

            //if closing bracket, check top and pop
            if(!s.empty()) {

                char top = s.top();

                if((ch == ')' && top == '(') or (ch == '}' && top == '{') or (ch == ']' && top == '[')) {

                    s.pop();

                } else {

                    return false;

                }
            } else {

                return false;

            }
            
        }
    }

    if(s.empty()) {

        return true;

    } else {

        return false;

    }
}