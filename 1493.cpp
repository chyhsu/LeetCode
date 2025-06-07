#include <algorithm>
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