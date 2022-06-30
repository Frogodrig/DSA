#include<iostream>
using namespace std;

void selectionSort(int arr[], int n) {

    for(int i = 0;i<n-1;i++) {

        int minIndex = i;

        for(int j = i+1;j<n;j++) {

            if(arr[j] < arr[minIndex]) {

                minIndex = j;
            }
        }

        swap(arr[minIndex], arr[i]);
    }
}

int main() {
    
    int a[] = {0, 9, 7, 1, 4, 2};
    selectionSort(a, 6);

    for(int i=0;i<6;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
