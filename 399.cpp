/*
LeetCode 399 – Evaluate Division
--------------------------------
Problem (re-phrased):
You are given a set of equations representing the division of variables.
Each equation equations[i] = {Ai, Bi} corresponds to Ai / Bi = values[i].
A query queries[j] = {Cj, Dj} asks for the numerical result of Cj / Dj.
If the expression cannot be evaluated from the known equations, the
answer is –1.0.

Input
 • vector<vector<string>> equations – list of variable pairs.
 • vector<double> values           – values[i] is the quotient Ai / Bi.
 • vector<vector<string>> queries  – list of queries.

Output
 • vector<double> – answers for each query in order; -1.0 when unknown.
--------------------------------
*/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<equations.size();i++){
    }
};