#include<iostream>
using namespace std;

class twoStack {

    private:
        int *arr;
        int top1;
        int top2;
        int size;

    public:

    twoStack(int size) {
        this -> size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }    

    void push1(int num) {
        if(top2 - top1 > 1) {
            top1++;
            arr[top1] = num;

        } else {
            cout<<"Stack 1 overflow"<<endl;

        }
    }

    void push2(int num) {
        if(top2 - top1 > 1) {
            top2--;
            arr[top2] = num;

        } else {
            cout<<"Stack 2 overflow"<<endl;

        }
    }

    int pop1() {
        if(top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;

        } else {
            cout<<"Stack 1 underflow"<<endl;
            return -1;

        }

    }

    int pop2() {
        if(top2 < size) {
            int ans = arr[top1];
            top2++;
            return ans;

        } else {
            cout<<"Stack 2 underflow"<<endl;
            return -1;

        }

    }

};