//MergeSort with inversion count

#include<iostream>
using namespace std;

int merge(int *arr, int s, int e) {

    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0;i<len1;i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0;i<len2;i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;
    int inversionCount = 0;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
            inversionCount = inversionCount + (len1-index1);  //if(a[i] > b[j], then a[i+1]...a[n] will also be > b[j] since a and b are sorted)
        }
    }

    while(index1<len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2<len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

    return inversionCount;
}



int mergeSort(int *arr, int s, int e) {

    //base condition
    if(s >= e) {
        return 0;
    }

    int mid = s + (e-s)/2;
    int inversionCount = 0;

    //sort the left part
    inversionCount+=mergeSort(arr, s, mid);

    //sort the right part
    inversionCount+=mergeSort(arr, mid+1, e);

    //merge
    inversionCount+=merge(arr, s, e);

    return inversionCount;
}


int main() {
    
    int arr[5] = {2,5,3,1,9};
    int n = 5;

    int inversions = mergeSort(arr, 0, n-1);

    cout<<"Number of inversions are: "<<inversions<<endl<<endl;

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}
