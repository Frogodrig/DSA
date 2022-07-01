#include<iostream>
#include<vector>
using namespace std;

vector<int> intersection(int arr1[], int arr2[], int n, int m) {

    vector<int> ans;
    int i=0,j=0;

    while(i<n and j<m) {

        if(arr1[i] == arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
            j++;
        } else if(arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return ans;
}


int main() {
    
    
    return 0;
}

