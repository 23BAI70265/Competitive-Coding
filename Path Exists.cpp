#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    bool dfs(vector<vector<int>> &graph,int source,int destination,vector<bool> &vis){
        vis[source] = true ;
        for(auto &it : graph[source]){
            if(vis[it]) continue ;
            if(it == destination || dfs(graph, it, destination, vis)) return true ;
        }
        return false ;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true ;
        vector<vector<int>> graph(n) ;
        for(auto &it : edges){
            graph[it[0]].push_back(it[1]) ;
            graph[it[1]].push_back(it[0]) ;
        }
        vector<bool> vis(n, false) ;
        return dfs(graph, source, destination, vis) ;
    }
};
int main(){

    return 0 ;
}