/*
LeetCode 1926 – Nearest Exit from Entrance in Maze
------------------------------------------------
Problem (re-phrased):
Given a maze represented as a 2D grid of characters, find the shortest
path from the entrance to the nearest exit.  The maze consists of '.'
(empty cells), '+' (walls).  The entrance is marked as
'.' and the exit is marked as 'E'.

Input
 • vector<vector<char>> maze – 2D grid of '.' (empty), '#' (wall), 'E' (exit).
 • vector<int> entrance       – coordinates of the entrance.

Output
 • int – shortest path length from entrance to nearest exit.
------------------------------------------------
*/  
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isWall(const vector<vector<char>>& maze, int r, int c)
    {
        return   maze[r][c] == '+';
    }
    bool isOut(const vector<vector<char>>& maze, int r, int c){
        return r<0||r>=maze.size()||c<0||c>=maze[0].size();
    }

    int bfs(vector<vector<char>>& maze, int a, int b,vector<vector<int>>& dist){
        queue<pair<int,int>> q;
        q.push({a,b});
        vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(auto &dir:directions){
                int newX=x+dir.first;
                int newY=y+dir.second;
                if(isOut(maze,newX,newY) && !(x==a&&y==b) ){
                    return dist[x][y];
                }
                if(!isOut(maze,newX,newY) && !isWall(maze,newX,newY) && dist[newX][newY]==-2 && !(newX==a&&newY==b)){
                    dist[newX][newY]=dist[x][y]+1;
                    q.push({newX,newY});
                }
            }
        }
        return -1;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();

        vector<vector<int>> dist(m,vector<int>(n,-2));
        dist[entrance[0]][entrance[1]]=0;
        int result=bfs(maze,entrance[0],entrance[1],dist);
        
        return result;
    }
};
/*
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<pair<int,int>,int>> q;
        q.push({{entrance[0],entrance[1]},0});
        int row = maze.size();
        int col = maze[0].size();
        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, 1, 0, -1};
        maze[entrance[0]][entrance[1]] = '+';
        int moves = 0;
        while(!q.empty()){
            pair<pair<int,int>,int> curr = q.front();
            q.pop();
            int r = curr.first.first;
            int c = curr.first.second;
            int steps = curr.second + 1;
            for(int i=0; i<4; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>-1&&nr<row&&nc>-1&&nc<col&& maze[nr][nc]=='.'){
                    if(nr ==0 ||nr == row-1||nc==0||nc== col-1){
                        return steps;
                    }
                    maze[nr][nc] = '+';
                    q.push({{nr,nc},steps});
                }
            }
        }
        return -1;
    }
};
*/