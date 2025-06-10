#include <vector>
#include <queue>
using namespace std;
//BFS
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int room=q.front();
            q.pop();
            for(int key:rooms[room]){
                if(!visited[key]){
                    visited[key]=true;
                    q.push(key);
                }
            }
        }
        for(bool v:visited){
            if(!v){
                return false;
            }
        }
        return true;
    }
};

/*
//DFS
class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int currNode, set<int>& visited)
    {
        if(visited.find(currNode) != visited.end())
        {
            return;
        }
        else
        {
            visited.insert(currNode);
            for(int key: rooms[currNode])
            {
                dfs(rooms,key,visited);
            }
            
        }

    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        set<int> visited;
        dfs(rooms,0,visited);
        
        return visited.size() == rooms.size();
    }
};
*/