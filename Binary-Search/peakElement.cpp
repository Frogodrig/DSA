#include<iostream>
using namespace std;

int peakElementOfMountain(int arr[], int start, int end) {

    int s = start;
    int e = end;
    
    int mid = s + (e-s)/2;
    int ans;

    while(s < e) { //if we do s<=e, it'll compare a[mid]<a[mid+1] in the last iteration resulting in an infinite loop

        if(arr[mid] < arr[mid+1]) {
            s = mid + 1;
        } else { //arr[mid] > arr[mid] + 1  or arr[mid] is the peak element
            e = mid;
        }

        mid = s + (e-s)/2;

    }
    return arr[s];
}


int main()
{
    int a[] = {0,1,2,3,4,5,4,3,2,1,0};

    int peakElement = peakElementOfMountain(a, 0, 11);
    cout<<"Peak element of the mountain array is: "<<peakElement;

    return 0;
}
