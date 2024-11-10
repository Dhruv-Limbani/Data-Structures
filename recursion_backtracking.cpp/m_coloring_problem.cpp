#include<bits/stdc++.h>
using namespace std;

bool is_possible(int v, int c, vector<int>& color, vector<pair<int, int>>& edges){
    for(auto it: edges){
        if(it.first==v && color[it.second]==c) return false;
        if(it.second==v && color[it.first]==c) return false;
    }
    return true;
}
bool color_graph(int node, vector<pair<int, int>>& edges, vector<int>& color, int m){
    if(node==color.size()) return true;
    for(int c=0; c<m; c++){
        if(is_possible(node, c, color, edges)){
            color[node] = c;
            if(color_graph(node+1, edges, color, m)) return true;
            else color[node] = -1;
        }
    }
    return false;
}
bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
    vector<int> color(v,-1);
    return color_graph(0, edges, color, m);
}