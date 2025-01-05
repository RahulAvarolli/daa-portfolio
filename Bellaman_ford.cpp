#include<bits/stdc++.h>
using namespace std;
void bellmanFord(int V, int E, vector<tuple<int,int,int>>& edges, int src){
    vector<int> d(V, INT_MAX);
    d[src] = 0;
    for(int i=1; i<V; i++){
        for(auto [u,v,w]: edges){
            if(d[u]!=INT_MAX && d[u]+w<d[v]) d[v]=d[u]+w;
        }
    }
    for(auto [u,v,w]: edges){
        if(d[u]!=INT_MAX && d[u]+w<d[v]){
            cout<<"Negative-weight cycle exists\n";
            return;
        }
    }
    for(int i=0; i<V; i++) cout<<"Distance to "<<i<<": "<<d[i]<<"\n";
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<tuple<int,int,int>> edges(E);
    for(int i=0; i<E; i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[i] = {u,v,w};
    }
    int src;
    cin>>src;
    bellmanFord(V,E,edges,src);
    return 0;
}
