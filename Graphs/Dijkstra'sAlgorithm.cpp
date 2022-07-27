#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<set>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {

    //create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //create a distance array, initialize all values to INF
    vector<int> distance(vertices);
    for(int i=0; i<vertices; i++) {
        distance[i] = INT16_MAX;
    }

    //creation of set: pair<distance, node>
    set<pair<int, int>> st;

    //initialize distance of the source node
    distance[source] = 0;
    //insert the initialized source and its distance in the set
    st.insert(make_pair(0, source)); //distance, node

    
    while(!st.empty()) {
        //fetch top record (i.e. The record with minimum nodeDistance)
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        //remove top record
        st.erase(st.begin());

        //traverse for neighbours
        for(auto neighbour: adj[topNode]) {
            if(nodeDistance + neighbour.second < distance[neighbour.first]) {//neighbour.second = edge weight in adj list

                auto record = st.find(make_pair(distance[neighbour.first], neighbour.first));
                //If record found, then erase it
                if(record != st.end()) {
                    st.erase(record);
                }
                
                //distance update
                distance[neighbour.first] = nodeDistance + neighbour.second;

                //record the record in set
                st.insert(make_pair(distance[neighbour.first], neighbour.first));
            }
        }
    }

    return distance;
}