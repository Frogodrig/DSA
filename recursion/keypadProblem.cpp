//LeetCode 17.
//Letter Combinations of a phone number
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/


#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
    
private:
    void solve(string digit, string output, int index, vector<string> &ans, string mapping[]) {
        
        if(index >= digit.length()) {
            
            if(output.length() != 0) {
                ans.push_back(output);
            }
            
            return;
        }
        
        int number = digit[index] - '0';
        
        string value = mapping[number];
        
        for(int i=0; i<value.length(); i++) {
            output.push_back(value[i]);
            solve(digit, output, index+1, ans, mapping);
            output.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        string output = "";
        int index = 0;
        
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        solve(digits, output, index, ans, mapping);
        
        return ans;
    }
};