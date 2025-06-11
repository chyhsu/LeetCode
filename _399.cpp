#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
LeetCode 399 – Evaluate Division
--------------------------------
Problem (re-phrased):
You are given a list of equations in the form A / B = k, where A and B
are strings representing variables and k is a real number.  For each
query X / Y, compute the value of the division based on the known
equations; if the answer cannot be determined, return –1.

Input
 • vector<vector<string>> equations – each element {A, B}.
 • vector<double> values            – where values[i] is the numeric ratio
   for equations[i].
 • vector<vector<string>> queries   – each element {X, Y} whose ratio is
   requested.

Output
 • vector<double> – answers to each query in order; use –1 if the value
   cannot be determined.
--------------------------------
*/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> graph;
        for(int i=0;i<equations.size();i++){
            string first=equations[i][0];
            string second=equations[i][1];
            
            graph[first].push_back({second,values[i]});
            graph[second].push_back({first,1/values[i]});
        }
        vector<double> result;
        for(const auto &q:queries){
            string first=q[0];
            string second=q[1];
            if(graph.find(first)==graph.end()||graph.find(second)==graph.end()){
                result.push_back(-1);
            }else{
                unordered_set<string> visited;
                double ans = dfs(first,second,graph,visited,1.0);
                result.push_back(ans);
            }
        }
        return result;
    };
    double dfs(const string &cur, const string &target,
               unordered_map<string,vector<pair<string,double>>>& graph,
               unordered_set<string>& visited,
               double product){
        if(cur==target) return product;
        visited.insert(cur);
        for(const auto &edge : graph[cur]){
            const string &next = edge.first;
            double weight = edge.second;
            if(!visited.count(next)){
                double res = dfs(next, target, graph, visited, product*weight);
                if(res != -1.0) return res;
            }
        }
        return -1.0;
    } 
};