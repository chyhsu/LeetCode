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