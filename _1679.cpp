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
