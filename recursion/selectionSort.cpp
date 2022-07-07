#include<iostream>
using namespace std;

void sortArray(int *arr, int i, int n) {

    if (i>=n-1) {
        return;
    }

    int min = i;

    for(int j=i+1;j<n;j++) {
        if(arr[min] > arr[j]) {
            min = j;
        }
    }

    swap(arr[min], arr[i]);

    sortArray(arr, i+1, n);
}

int main() {
    
    int arr[5] = {2,5,1,6,9};

    sortArray(arr, 0, 5);

    for(int i=0;i<5;i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}