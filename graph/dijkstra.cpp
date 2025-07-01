#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<pair<int,int>>>G,int src, int V){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int>dist(V,INT_MAX);
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty()){
        int currw=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        for(auto &it:G[u]){
            int v=it.first;
            int w=it.second;
            if(dist[v]>currw+w){
                dist[v]=currw+w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
int main(){
    int V,E;
    cin >> V >>E;
    vector<vector<pair<int,int>>>G(V);
    for(int i=0;i<E;i++){
        int u,v,w;
        cout<<i+1<<"th iteration";
        cin>>u >>v >>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    cout<<"enter src";
    int src;
    cin>>src;
    vector<int>dist=dijkstra(G,src,V);
    for(int i=0;i<V;i++){
        cout<< i << ":" << dist[i]<<" ";
    }
    
}