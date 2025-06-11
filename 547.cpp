#include <vector>
using namespace std;

/*
LeetCode 547 – Number of Provinces (a.k.a. Friend Circles)
---------------------------------------------------------
Problem (re-worded):
Given an n × n binary matrix isConnected where isConnected[i][j] = 1
signifies that city i and city j are directly linked by a road and
isConnected[i][j] = 0 otherwise, any city is considered to belong to the
same province as itself and every city that is reachable through a chain
of direct connections.

Input
 • vector<vector<int>> isConnected – an n × n symmetric matrix with
   1 ≤ n ≤ 200, where isConnected[i][i] = 1.

Output
 • Return the total number of provinces, i.e. the number of connected
   components in the undirected graph induced by isConnected.
---------------------------------------------------------
*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(),false);
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                dfs(isConnected,visited,i);
                count++;
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& graph, vector<bool>& visited,int start){
        if(visited[start]){
            return;
        }else{
            visited[start]=true;
            int size=graph[start].size();
            for(int i=0; i<size; i++){
                if(graph[start][i]==1&&!visited[i]){
                    dfs(graph,visited,i);
                }
            }
        }
    }
};
