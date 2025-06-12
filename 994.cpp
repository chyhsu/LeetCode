/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/
#include <vector>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        if(isAllRotten(grid)) return 0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if(q.empty()) return -1; // no rotten oranges to start but some fresh exist
        bfs(grid,count,q);
        if(!isAllRotten(grid)) return -1;
        return count;
    }
    bool isAllRotten(vector<vector<int>>& grid){
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==1) return false;
            }
        }
        return true;
    }
    bool isWall(pair<int,int> cur, vector<vector<int>>& grid){
        int r = cur.first;
        int c = cur.second;
        // if out of bounds return true immediately (no grid access)
        if(r < 0 || r >= (int)grid.size() || c < 0 || c >= (int)grid[0].size()){
            return true;
        }
        // cell is wall/empty or already rotten
        return grid[r][c] == 0 || grid[r][c] == 2;
    }
    void bfs(vector<vector<int>>& grid, int &count, queue<pair<int,int>>& q){
        vector<pair<int,int>> Directions={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int sz = q.size();
            bool spread = false;
            while(sz--){
                auto cur = q.front(); q.pop();
                for(auto dir:Directions){
                    int NextX=cur.first+dir.first;
                    int NextY=cur.second+dir.second;
                    if(isWall({NextX,NextY},grid)) continue;
                    // Fresh orange becomes rotten
                    spread = true;
                    grid[NextX][NextY]=2;
                    q.push({NextX,NextY});
                }
            }
            if(spread) ++count; // one minute elapsed when at least one spread occurred
        }
    }
};