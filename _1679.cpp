/*
LeetCode 1679 – Max Number of K-Sum Pairs
----------------------------------------
Problem (re-phrased):
Given an integer array nums and an integer k, you may choose pairs of
numbers (nums[i], nums[j]) such that their sum equals k, and each index
may be used at most once.  Return the maximum possible number of such
pairs.

Input
 • vector<int>& nums – 1 ≤ |nums| ≤ 10⁵.
 • int k – target sum.

Output
 • int – maximum number of disjoint pairs with sum k.
----------------------------------------
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;
        
        for (int num : nums) {
            int complement = k - num;
            if (freq[complement] > 0) {
                count++;
                freq[complement]--;
            } else {
                freq[num]++;
            }
        }
        
        return count;
    }
    };

// Reference Solution
    // class Solution {
    //     public:
    //         int maxOperations(vector<int>& nums, int k) {
    //             sort(nums.begin(),nums.end());
    //             int i =0;
    //             int j = nums.size()-1;
    //             int ans = 0;
    //             while(j>i){
    //                 if(nums[i]+nums[j]==k)
    //                 {
    //                     ans++;
    //                     i++;
    //                     j--;
    //                 }
    //                 else if(nums[i]+nums[j]<k){
    //                     i++;
    //                 }
    //                 else
    //                     j--;
    //             }
    //             return ans;
                
    //         }
    //     }
