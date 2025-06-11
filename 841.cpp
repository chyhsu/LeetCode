/*
LeetCode 841 – Keys and Rooms
----------------------------
Problem (re-phrased):
There are n rooms numbered 0 … n-1.  Each room i contains a list of keys
that grant entry to other rooms rooms[i].  Starting in room 0, determine
whether it is possible to visit every room at least once.

Input
 • vector<vector<int>>& rooms – rooms[i] is the list of keys in room i;
   1 ≤ n ≤ 1000, sum of key counts ≤ 3000.

Output
 • bool – true if all rooms can be visited, false otherwise.
----------------------------
*/
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