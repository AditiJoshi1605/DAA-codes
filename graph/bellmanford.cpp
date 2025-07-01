#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
void printPath(int node,vector<int> &parent){
    if(node==-1)
        return;
    printPath(parent[node],parent);
    cout << node << " ";
}
vector<int>bellmanford(int V,int src,vector<vector<pair<int,int>>>G,vector<int>&parent){
    vector<int>dist(V,INT_MAX);
    dist[src]=0;
    parent[src]=-1;
    for(int i=0;i<V-1;i++){
        for(int u=0;u<V;u++){
            for(auto it:G[u]){
                int v=it.first;
                int w=it.second;
                if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    parent[v]=u;
                }
            }
        }
    }
    for(int u=0;u<V;u++){
        for(auto it:G[u]){
            int v=it.first;
            int w=it.second;
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
                cout<<"NEGATIVE CYCLE DETECTED!"<<endl;
                return {};
            }
        }
    }
    return dist;
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<pair<int,int>>>G(V);
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u >>v >>w;
        G[u].push_back({v,w});
    }
    int src;
    cin >>src;
    vector<int>parent(V,-1);
    vector<int>dist=bellmanford(V,src,G,parent);
    if(!dist.empty()){
        //prints shortest path from src node to all other nodes with distance
        cout << "\nShortest path from node " << src << ":\n";
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX){
                cout<<i<<"NO PATH\n";
            }
            else{
                printPath(i,parent);
                cout<<":"<<dist[i]<<endl;
            }
        }
    }

}