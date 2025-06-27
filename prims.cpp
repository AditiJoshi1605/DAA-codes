#include <iostream>
#include <vector>
#include <queue>

using namespace std;
void prims(vector<vector<pair<int,int>>> &graph,int source,vector<int> &visited){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,source});
    int mst=0;
    while(!pq.empty()){
        auto node=pq.top();
        int w=node.first;
        int u=node.second;
        pq.pop();
        if(visited[u]){
            continue;
        }
        mst+=w;
        visited[u]=1;
        for(auto &edge:graph[u]){
            int v=edge.first;   
            int weight=edge.second;
            if(!visited[v]){
                pq.push({weight,v});
            }
        }
    }
    cout << "Cost of Minimum Spanning Tree: " << mst << endl;
}

int main(){
    int v,e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;
    vector<vector<pair<int,int>>> graph(v);
    for(int i=0;i<e;i++){
        int m,n,w;
        cout << "Enter source, destination, and weight: ";
        cin >> m >> n >> w;
        graph[m].push_back({n,w});
        graph[n].push_back({m,w});
    }
    int source;
    cout << "Enter source node: ";
    cin >> source;
    vector<int> visited(v,0);
    prims(graph,source,visited);
    return 0;
}