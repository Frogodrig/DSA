//442. Find All Duplicates in an Array
//https://leetcode.com/problems/find-all-duplicates-in-an-array/

//Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
//You must write an algorithm that runs in O(n) time and uses only constant extra space.

//Hint: use XOR

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findDuplicates(int arr[], int n) {

    vector<int> ans;
    sort(arr, arr+n);

    for(int i = 0 ; i<(n-1) ; i++){
            if((arr[i] ^ arr[i+1]) == 0){
                ans.push_back(arr[i]);
            }
        }

    for(int i = 0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    } cout<<endl;
}

int main() {
    
    int a[] = {4,3,2,7,8,2,3,1};
    findDuplicates(a, 8);
    return 0;
}
