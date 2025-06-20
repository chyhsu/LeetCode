/*Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.*/

#include <vector>
#include <iostream>
using namespace std;
class Solution {
    public:
        vector<vector<int>> combinationSum3(int k, int n) {
            vector<vector<int>> result;
            vector<int> temp;
            for(int i=1;i<10;i++){
                temp.push_back(i);
                track(result,temp,k-1,n-i);
                temp.pop_back();
            }
            return result;
        }
        void track(vector<vector<int>> &result,vector<int> temp,int k, int n){
            if(k==0 && n==0){
                result.push_back(temp);
                return;
            }
            else{
                for(int i=temp[temp.size()-1]+1;i<10;++i){
                    temp.push_back(i);
                    track(result,temp,k-1,n-i);
                    temp.pop_back();
                }
            }
        }
        
};
/*
class Solution {
public:
    void helper(vector<vector<int>>&ans,  int n , int k, int i , vector<int>&curr,int currsum){
        if(currsum==n && k==curr.size()){
            ans.push_back(curr);
            return;
        }
        if(k==curr.size()||i==10)return;
        helper(ans,n,k,i+1,curr,currsum);
        curr.push_back(i);
        helper(ans,n,k,i+1,curr,currsum+i);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>curr;
        helper(ans,n,k,1,curr,0);
        return ans;

    }
};
*/