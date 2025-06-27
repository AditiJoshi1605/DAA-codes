#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int find(int u, vector<int>&parent){
    if(u==parent[u])
        return u ;
    return parent[u]=find(parent[u],parent); //ultimate parent
}
void unionEdge(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = find(u, parent);
    v = find(v, parent);

    if (u == v) return; // already in the same set

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}
vector<pair<int,pair<int,int>>> kruskals(vector<pair<int,pair<int,int>>>&G , int N){
    vector<pair<int,pair<int,int>>>sol;
    sort(G.begin(),G.end());
    vector<int>parent(N);
    for(int i=0;i<N;i++){
        parent[i]=i;
    }
    vector<int>rank(N,0);
    for(auto edge:G){
        int u=edge.second.first;
        int v=edge.second.second;
        if(find(u,parent)!=find(v,parent)){
            sol.push_back(edge);
            unionEdge(u,v,parent,rank);
        }
    }
    return sol;
}
int main(){
    vector<pair<int,pair<int,int>>>G,sol;
    int N,E,u,v,w;
    cin>>N>>E;
    for(int i=0;i<E;i++){
        cin>>u>>v>>w;
        G.push_back(make_pair(w,make_pair(u,v)));
    }
    int sum=0;
    sol=kruskals(G,N);
    cout<<"kruskals finised";
    for (auto edge : sol) {
        cout << edge.second.first << " " << edge.second.second << " " << edge.first << endl;
        sum += edge.first;
    }
    cout << "Total Weight of MST: " << sum << endl;
    return 0;
}