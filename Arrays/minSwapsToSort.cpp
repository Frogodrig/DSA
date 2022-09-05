#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    vector<pair<int, int>> v(n);
	    
	    for(int i=0; i<n; i++) {
	        v[i] = make_pair(nums[i], i);
	    }
	    
	    sort(v.begin(), v.end());
	    
	    int count = 0;
	    for(int i=0; i<n; i++) {
	        if(i == v[i].second) {
	            continue;
	            
	        } else {
	            count++;
	            swap(v[i], v[v[i].second]);
	            i--;
	        }
	    }
	    
	    return count;
	}
};