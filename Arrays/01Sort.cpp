#include<iostream>
using namespace std;

void sortZeroOne(int arr[], int n) {

    int left = 0;
    int right = n-1;

    while(left < right) {


        while(arr[left] == 0 && left < right) {
            left++;
        }

        while(arr[right] == 1 && left < right) {
            right--;
        }

        if(left < right && arr[left] == 1 && arr[right] == 0) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
        

    }
}

int main() {
    
    int a[] = {1,1,0,0,0,0,1,0};

    sortZeroOne(a, 8);

    for(int i=0;i<8;i++) {
        cout<<a[i]<<" ";
    }cout<<endl;

    return 0;
}
