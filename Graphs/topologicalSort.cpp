#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<list>
using namespace std;

void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj) {

    visited[node] = 1;

    for(auto neighbour: adj[node]) {
        if(!visited[neighbour]) {
            topoSort(neighbour, visited, s, adj);
        }
    }

    //important to our logic
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {

    //create adjacency list
    unordered_map<int, list<int>> adj;

    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //call dfs topological sort util function for all components
    unordered_map<int, bool> visited;
    stack<int> s;
    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            topoSort(i, visited, s, adj);
        }
    }

    vector<int> ans;

    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}



