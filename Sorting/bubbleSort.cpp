#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {

    for(int i=0;i<n-1;i++) { //for round 1 to n-1

        bool swapped = false; //optimization: figuring out if any swaps took place after a given round

        for(int j=0;j<n-i;j++) {

            if(arr[j] > arr[j+1]) {

                swap(arr[j], arr[j+1]); 
                swapped = true;

            }
        }

        if(swapped == false) { //If no swaps took place in the given round then there's no need for further rounds.
            break;
        }

    }
}

int main() {
    
    int a[] = {6,2,8,4,10};
    bubbleSort(a, 5);

    for(int i=0;i<5;i++) {
        cout<<a[i]<<" ";
    } cout<<endl;

    return 0;
}
