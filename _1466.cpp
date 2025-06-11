#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // Build bidirectional graph where the second field indicates
        // whether traversing this edge from the current node requires a reorder (1) or not (0).
        vector<vector<pair<int,int>>> graph(n);
        for (auto &e : connections) {
            int u = e[0], v = e[1];
            graph[u].push_back({v, 1}); // edge u -> v must be reversed when going from u to v
            graph[v].push_back({u, 0}); // edge v -> u is already correctly oriented
        }

        vector<bool> visited(n, false);
        int count = 0;
        dfs(0, graph, visited, count);
        return count;
    }

private:
    void dfs(int node,
             const vector<vector<pair<int,int>>> &graph,
             vector<bool> &visited,
             int &count) {
        visited[node] = true;
        for (auto &[nbr, need] : graph[node]) {
            if (!visited[nbr]) {
                count += need;
                dfs(nbr, graph, visited, count);
            }
        }
    }
};
/*
class Solution {
public:
    void reverse(int node, vector<vector<int>>& adj, int &count, vector<bool>&vis)
    {
      if(vis[node]==true){
        return;
      }
      vis[node] = true;
      for(auto it: adj[node])
      {
        if(vis[abs(it)] == false)
        {
          if(it>0)
          {
            count++;
          }
          reverse(abs(it),adj,count,vis);
        }
      }
    }
    int minReorder(int n, vector<vector<int>>& v) {
      vector<vector<int>>adj (n);
      vector<bool>vis(n,false);
      for(int i=0; i<v.size(); ++i)
      {
        int m = v[i][0];
        int n = v[i][1];
        adj[m].push_back(n);
        adj[n].push_back(-m);
      }
      int count=0;
      reverse(0,adj,count,vis);
      return count;
    }
}; */