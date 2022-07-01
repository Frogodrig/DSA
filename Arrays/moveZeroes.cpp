//Leetcode 283.

#include<iostream>
using namespace std;

void moveZeroes(int arr[], int n) {

    int i = 0;

    for(int j=0;j<n;j++) {

        if(arr[j] != 0) {
            swap(arr[j], arr[i]);
            i++;
        }
    }

}


int main() {

    int a[] = {0,1,0,3,12};
    
    moveZeroes(a, 5);
    
    for(int i=0;i<5;i++) {
        cout<<a[i]<<" ";
    } cout<<endl;

    return 0;
}
