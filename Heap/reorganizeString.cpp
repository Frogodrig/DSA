#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>
using namespace std;

//Question Hint: maximum occuring character will be placed first
//Perform alternating


// custom comparator for maxHeap
class compare {

    public:
        bool operator()(pair<int, char> &a, pair<int, char> &b) {
            return b.first > a.first;
        }
};

string reorganizeString(string s) {

    unordered_map<char, int> mapping;

    //store the frequecy of character occurence in a map
    for(int i=0; i<s.length(); i++) { 
        mapping[s[i]]++;
    }

    //creating maxHeap
    priority_queue<pair<int, char>, vector<pair<int, char>>, compare> pq; 

    for(auto it: mapping) {
        pq.push({it.second, it.first}); //inserting second value before first as we are using maxHeap on the basis of the frequency
    }

    //answer string
    string ans = ""; 

    //handling first character (character with largest frequency)
    //block variable is used to avoid adjacent insertion in answer string
    //when a character is in the block it is taken out of the maxHeap
    pair<int, char> block = pq.top(); 
    pq.pop();

    ans += block.second;
    block.first = block.first - 1;

    //handling for rest of the characters
    while(pq.size() > 0) {
        pair<int, char> temp = pq.top();
        pq.pop();

        ans += temp.second;
        temp.first = temp.first - 1;

        if(block.first > 0) { //Insert back into the maxHeap only if the frequency is > 0
            pq.push(block);
        }

        block = temp;
         
    }

    //even after exhausting maxHeap if something is left in the block then answer is not possible. (example i/p: "aaab") 
    if(block.first > 0) {
        return "";
    }

    //return answer
    return ans;
}   