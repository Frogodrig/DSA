//Given an array of n = 2m + 1 elements where m number of elements occur twice in the array and there is one element that only occurs once, find that unique element which only occurs once.
//Hint: a xor (^) a = 0
//      a ^ 0 = a

#include<iostream>
using namespace std;

int findUnique(int arr[], int n) {

    int ans = 0;

    for(int i=0;i<n;i++) {
        ans = ans ^ arr[i];
    }

    return ans;
}


int main() {
    
    int a[] = {2,3,1,6,3,6,2};

    cout<<"Unique element is : "<<findUnique(a, 7)<<endl;

    return 0;
}
