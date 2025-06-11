/*
LeetCode 283 – Move Zeroes
-------------------------
Problem (re-phrased):
Given an integer array nums, move all zeros to the end while preserving
the relative order of the non-zero elements.  The operation must be done
in-place with O(1) extra space.

Input
 • vector<int> nums – array of length 1 ≤ n ≤ 10⁴.

Output
 • The array is modified in place; no value is returned.
-------------------------
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int left=0;
            int right=left+1;
            int temp;
            if (nums.size() == 1) return;
            while (left < nums.size() && right < nums.size()) {
                // Find the next zero
                while (left < nums.size() && nums[left] != 0) {
                    left++;
                }
                
                // Right should always be ahead of left
                if (right <= left) {
                    right = left + 1;
                }
                
                // Find the next non-zero after left
                while (right < nums.size() && nums[right] == 0) {
                    right++;
                }
                
                // If we found both a zero and a non-zero, swap them
                if (left < nums.size() && right < nums.size()) {
                    swap(nums[left], nums[right]);
                    left++;
                    right++;
                }
            }

        }
    };

// Reference Solution
// class Solution {
//     public:
//         void moveZeroes(vector<int>& nums) {
//             //Brute Force O(n) O(n)
//             // vector<int> temp(nums.size());
//             // int j=0;
//             // for(int i =0;i<nums.size();i++){
//             //     if(nums[i]!=0) temp[j++] = nums[i];
//             // }
//             // nums= temp;
    
    
//             //Optimal O(n) O(1)
//             int n = nums.size();
//             int j=0;
//             for(int i=0;i<n;i++){
//                 if(nums[i]!=0){
//                     swap(nums[i],nums[j]);
//                     j++;
//                 }
//             }
            
//         }
//     };