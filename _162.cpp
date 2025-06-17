#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Handle edge cases
        int n = nums.size();
        if (n == 1) return 0;
        
        // Check endpoints
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;
        
        // Binary search for a peak
        int left = 1;
        int right = n-2;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if mid is a peak
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                return mid;
            }
            
            // If not a peak, move toward the higher neighbor
            if (nums[mid] < nums[mid+1]) {
                // Ascending slope, peak is to the right
                left = mid + 1;
            } else {
                // Descending slope, peak is to the left
                right = mid - 1;
            }
        }
        
        // This should not be reached if the problem guarantees a peak exists
        return -1;
    }
};