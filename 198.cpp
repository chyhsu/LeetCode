/*
LeetCode 198 – House Robber
--------------------------
Problem (re-phrased):
You are a professional robber planning to rob houses along a street. Each
house has a certain amount of money stashed, the only constraint stopping
you from robbing each of them is that adjacent houses have security systems
connected and it will automatically contact the police if two adjacent
houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting
the police.

Input
 • vector<int>& nums – array of length 1 ≤ n ≤ 10⁴.

Output
 • int – maximum amount of money that can be robbed.
--------------------------
*/
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n==1)return nums[0];
            vector<int> accumulated_values(n,0);
            accumulated_values[n-1]=nums[n-1];
            accumulated_values[n-2]=max(nums[n-1],nums[n-2]);
            for(int i=n-3;i>=0;i--){
                accumulated_values[i]=*max_element(accumulated_values.begin()+i+2,accumulated_values.end())+nums[i];
            }
            return *max_element(accumulated_values.begin(),accumulated_values.end());
        }
    };