//Return all the pairs from the given vector where the sum of the two elements == sum.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Two pointer approach
vector<pair<int,int>> pairSum(vector<int> v, int sum) {

    sort(v.begin(), v.end());

    int n = v.size();
    int first = 0;
    int last = n-1;

    vector<pair<int,int>> ans;

    while(first < last) {

        if(v[first] + v[last] == sum) {
            ans.push_back(make_pair(v[first], v[last]));
            first++;last--;
            
        } else if(v[first] + v[last] > sum) {
            last--;

        } else {
            first ++;
        }
    }

    return ans;

}

int main() {
    
    vector<int> a = {1,2,3,4,5};
    vector<pair<int,int>> ans = pairSum(a, 5);

    for(int i=0;i<ans.size();i++) {
        cout<<ans[i].first<<","<<ans[i].second<<endl;
    }

    return 0;
}
