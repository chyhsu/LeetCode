/*
LeetCode 1004 – Max Consecutive Ones III
---------------------------------------
Problem (re-phrased):
Given a binary array nums and an integer k, return the length of the
longest contiguous subarray that contains at most k zeros (you may flip
at most k zeros to ones).

Input
 • vector<int>& nums – 1 ≤ |nums| ≤ 10⁵, nums[i] is 0 or 1.
 • int k – 0 ≤ k ≤ |nums|.

Output
 • int – length of the longest subarray with at most k zeros.
---------------------------------------
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;  // left boundary of the window
        int max_length = 0;
        int zero_count = 0;  // count of zeros in current window
        
        for (int right = 0; right < nums.size(); ++right) {
            // If current element is 0, increment zero_count
            if (nums[right] == 0) {
                zero_count++;
            }
            
            // If zero_count exceeds k, move left boundary to the right
            // until zero_count is at most k
            while (zero_count > k) {
                if (nums[left] == 0) {
                    zero_count--;
                }
                left++;
            }
            
            // Update the maximum length of the window
            max_length = max(max_length, right - left + 1);
        }
        
        return max_length;
    }
};