#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
  public:
  
    void inorder(vector<int> &A, int i, int n, vector<int> &in) {
        
        if(i>=n) {
            return;
        }
        
        inorder(A, 2*i+1, n, in); //left element = 2*i+1
        in.push_back(A[i]);
        inorder(A, 2*i+2, n, in); //right element = 2*i+2
    
    }
    
    int swaps(vector<int> &in, int n) {
        
        vector<pair<int, int>> v(n);
        
        for(int i=0; i<n; i++) {
            v[i] = make_pair(in[i], i);
        }
        
        sort(v.begin(), v.end());
        
        int count = 0;
        for(int i=0; i<n; i++) {
            if(i == v[i].second) {
                continue;
                
            } else {
                count++;
                swap(v[i], v[v[i].second]);
                i--; //not sure if swapped element is in the right place
            }
        }
        
        return count;
    }
  
    int minSwaps(vector<int>&A, int n){
        
        vector<int> in;
        
        inorder(A, 0, n, in);
        int ans = swaps(in, n);
        
        return ans;
    }
    
    
};