#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i=1;i<n;i++) { //Rounds
        int temp = arr[i]; 
        int j = i-1;
        for(; j>=0;j--) { //comparison with previously sorted elements (inserting into a sorted array)

            if(arr[j] > temp) {
                //shifting 
                arr[j+1] = arr[j];

            } else { //that element is already sorted
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main() {
    
    int a[] = {10,1,7,4,8,2,11};
    insertionSort(a, 7);

    for(int i=0;i<7;i++) {
        cout<<a[i]<<" ";
    } cout<<endl;

    return 0;
}
