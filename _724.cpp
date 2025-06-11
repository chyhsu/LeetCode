/*
LeetCode 724 – Find Pivot Index
------------------------------
Problem (re-phrased):
An array pivot index is a position where the sum of all elements to its
left equals the sum of all elements to its right.  Given an integer array
nums, return the left-most pivot index; if no such index exists, return
-1.

Input
 • vector<int> nums – array length 1 ≤ n ≤ 10⁴.

Output
 • int – smallest pivot index, or –1 if none.
------------------------------
*/
#include <vector>
using namespace std;
class Solution {
    public:
    int pivotIndex(std::vector<int>& nums) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        int left_sum = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            
            if (left_sum == total_sum - left_sum - nums[i]) {
                return i; 
            }
            
            left_sum += nums[i];
        }

        return -1; 

};}