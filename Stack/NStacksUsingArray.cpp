#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

class NStack {

    int *arr;
    int *top;
    int *next;

    int n, s;

    int freespot;

    public:
        //initialization
        NStack(int N, int S) {

            n = N;
            s = S;
            arr = new int[S];
            top = new int[n];
            next = new int[s];

            // memset(top, -1 , sizeof(top));
            //initialize top
            for(int i=0; i<n; i++) {
                top[i] = -1;
            }

            //initialize next
            for(int i=0; i<s; i++) {
                next[i] = i+1;
            }

            //update last index to -1
            next[s-1] = -1;

            //initialize freespot
            freespot = 0;
        }

    bool push(int x, int m) {

        //check for overflow
        if(freespot == -1) {
            return false;
        }

        //find index
        int index = freespot;

        //insert element
        arr[index] = x;

        //update freespot
        freespot = next[index];

        //update next
        next[index] = top[m-1];

        //update top
        top[m-1] = index;

        return true;
    }

    //reverse the flow of the push function
    int pop(int m) {

        //check for underflow
        if(top[m-1] == -1) {
            return -1;
        }

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];

    }    
};