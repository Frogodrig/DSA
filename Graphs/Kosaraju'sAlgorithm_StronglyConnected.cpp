#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj) {

    vis[node] = true;
    for(auto neighbour: adj[node]) {
        if(!vis[neighbour]) {
            dfs(neighbour, vis, st, adj);
        }
    }

    //Topological Logic
    st.push(node);
}

void revDfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &transposeAdj) {

    vis[node] = true;
    for(auto neighbour: transposeAdj[node]) {
        if(!vis[neighbour]) {
            revDfs(neighbour, vis, transposeAdj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
    
    //Create Adjacency List
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //Topological Sort
    stack<int> st;
    unordered_map<int, bool> vis;

    for(int i=0; i<v; i++) {
        if(!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    //Create a transposed graph
    unordered_map<int, list<int>> transpose;
    for(int i=0; i<v; i++) {
        vis[i] = 0;
        for(auto neighbour: adj[i]) {
            transpose[neighbour].push_back(i);
        }
    }

    //dfs call using above ordering
    int count = 0; //Number of disconnected components
    while(!st.empty()) {
        int top = st.top();
        st.pop();
        if(!vis[top]) {
            count++;
            revDfs(top, vis, transpose);
        }
    }

    return count;
}