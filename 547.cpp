#include <vector>
using namespace std;
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
