/*
LeetCode 1493 – Longest Subarray of 1's After Deleting One Element
-----------------------------------------------------------------
Problem (re-phrased):
Given a binary array nums, you must delete exactly one element.  Return
the length of the longest subarray containing only 1's that can be
obtained.

Input
 • vector<int>& nums – 1 ≤ |nums| ≤ 10⁵, nums[i] is 0 or 1.

Output
 • int – maximum length of subarray consisting solely of 1's after
   deleting one element.
-----------------------------------------------------------------
*/
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            int max_length=0;
            int k=1;
            int left=0;
            for(int right=0;right<nums.size();++right){
                if(nums[right]==0) --k;
                while(k<0){
                    if(nums[left]==0){
                        ++k;
                    }
                    ++left;
                }
                max_length = max(max_length, right - left + 1);
            }
            
            return max_length-1;
        }
        
    };