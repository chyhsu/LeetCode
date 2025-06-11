/*
LeetCode 334 – Increasing Triplet Subsequence
-------------------------------------------
Problem (re-phrased):
Given an integer array nums, determine whether there exists a strictly
increasing subsequence of length three (i.e. i < j < k with nums[i] <
nums[j] < nums[k]).

Input
 • vector<int>& nums – 1 ≤ |nums| ≤ 5 × 10⁵, -2³¹ ≤ nums[i] ≤ 2³¹-1.

Output
 • bool – true if such a triplet exists, otherwise false.
-------------------------------------------
*/
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {
            if (nums.size() < 3) return false;
            
            int first = INT_MAX;    // smallest number so far
            int second = INT_MAX;   // second smallest number so far
            
            for (int num : nums) {
                if (num <= first) {
                    first = num;           // update smallest number
                } else if (num <= second) {
                    second = num;          // update second smallest
                } else {
                    return true;           // found a number larger than both
                }
            }
            return false;
        }
    };