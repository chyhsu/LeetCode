/*
LeetCode 643 – Maximum Average Subarray I
----------------------------------------
Problem (re-phrased):
Given an integer array nums and an integer k, find the contiguous subarray
of length k that has the maximum average value and return that average as
a double.

Input
 • vector<int>& nums – 1 ≤ |nums| ≤ 3 × 10⁴, -10⁴ ≤ nums[i] ≤ 10⁴.
 • int k – 1 ≤ k ≤ |nums|.

Output
 • double – maximum average value of any length-k subarray.
----------------------------------------
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
            // Calculate the sum of the first window
            int window_sum = 0;
            for (int i = 0; i < k; ++i) {
                window_sum += nums[i];
            }
            int max_sum = window_sum;
            
            // Slide the window through the array
            for (int i = k; i < nums.size(); ++i) {
                // Add the new element and remove the first element of previous window
                window_sum += nums[i] - nums[i - k];
                if (window_sum > max_sum) {
                    max_sum = window_sum;
                }
            }
            
            return static_cast<double>(max_sum) / k;
        }
    };

// Reference Solution
// class Solution {
//     public:
//         double findMaxAverage(vector<int>& nums, int k) {
//             int i = 0, j = 0;
//             int sum = 0;
//             double maxAvg = 0;
//             while(j<k){
//                 sum += nums[j++];
//             }
//             maxAvg = (double)sum/k;
//             while(j<nums.size()){
//                 sum += nums[j++];
//                 sum -= nums[i++];
//                 maxAvg = max(maxAvg, (double)sum/k);
//             }
//             return maxAvg;
//         }
//     };