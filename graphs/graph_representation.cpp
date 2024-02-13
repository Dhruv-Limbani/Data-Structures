#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int adj[n+1][n+1];
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u][v]=w;
        adj[v][u]=w;
    }


    vector<pair<int,int>> adj1[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj1[u].push_back({v,w});
        adj1[v].push_back({u,w});
    }



    return 0;
}