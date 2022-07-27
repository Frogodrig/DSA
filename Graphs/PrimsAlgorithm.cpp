#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {

    //Preparing out data structures
    //create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> key(n+1); //n+1 because we want to represent the nodes by the indices of the vectors themselves.
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i=0; i<=n; i++) {//initilize the values
        key[i] = INT16_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    //Prim's Algorithm Starts
    //Initializing the source node
    key[1] = 0;
    parent[1] = -1;

    for(int i=1; i<n; i++) {

        int mini = INT16_MAX;
        int u;

        //Finding the node with minimum value in key array
        for(int v=1; v<=n; v++) {
            if(mst[v] == false and key[v] < mini) {
                u = v;
                mini = key[v];
            } 
        }

        //mark minimum valued node as true
        mst[u] = true;

        //check the adjacent nodes for the selected node
        for(auto it: adj[u]) {
            int v = it.first; //adjacent node
            int w = it.second; //associated weight
            if(mst[v] == false and w<key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for(int i=2; i<=n; i++) {//running from 2 as parent of source(node 1) is -1
        result.push_back(make_pair(make_pair(parent[i], i), key[i])); //inserting as u, v and w (u---(w)---v)
    }

    return result;
}