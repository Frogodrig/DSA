//The Celebrity Problem (GFG)
//https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
//Everyone knows the celebrity but the celebrity does not know anyone at a party.
//Find if there exists a celebrity at the party.

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool knows(vector<vector<int>> &m, int a, int b, int n) {

    if(m[a][b] == 1) {
        return true;

    } else {
        return false;

    }
}


int celebrity(vector<vector<int>> &m, int n) {

    stack<int> s;

    for(int i=0;i<n;i++) {
        s.push(i);
    }

    //get 2 elements and check for knows condition
    while(s.size() > 1) {

        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(knows(m, a, b, n)) {
            s.push(b);

        } else {
            s.push(a);

        }
    }
    
    //Potential celebrity (single element remaining in stack)
    int candidate = s.top();

    //verify the potential celebrity
    bool rowCheck = false;
    int zeroCount = 0;
    for(int i=0; i<n; i++) {
        if(m[candidate][i] == 0) {
            zeroCount++;

        }
    }

    //all zeroes
    if(zeroCount == n) {
        rowCheck = true;
    }

    bool colCheck = false;
    int oneCount = 0;

    for(int i=0; i<n; i++) {
        if(m[i][candidate] == 1) {
            oneCount++;

        }
    }

    if(oneCount == n-1) {
        colCheck = true;
    }

    if(rowCheck && colCheck) {
        return candidate;

    } else {
        return -1;

    }
}



