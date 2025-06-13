/*
Problem: 2542. Maximum Subsequence Score

You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k.
You must choose a subsequence of indices from nums1 of length k.

For chosen indices i0, i1, ..., ik - 1, your score is defined as:

(nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).

Return the maximum possible score.

A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1}
by deleting some or no elements.

Constraints:
 • n == nums1.length == nums2.length
 • 1 <= n <= 10^5
 • 0 <= nums1[i], nums2[i] <= 10^5
 • 1 <= k <= n
*/
#include <vector>
#include <queue>
#include <algorithm> // For sort

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs(n);
        
        // Pair each element of nums1 with corresponding element in nums2
        for (int i = 0; i < n; i++) {
            pairs[i] = {nums2[i], nums1[i]}; // Store as {nums2_val, nums1_val} for sorting
        }
        
        // Sort pairs in descending order of nums2 values.
        sort(pairs.rbegin(), pairs.rend());
        
        // Min-heap to maintain the k largest elements of nums1 encountered so far
        // for the current nums2[i] as the minimum.
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long current_sum_of_top_k_from_nums1 = 0;
        long long max_score_found = 0;
        
        for (int i = 0; i < n; i++) {
            int current_num2_val = pairs[i].first;
            int current_num1_val = pairs[i].second;
            
            // Add current_num1_val to the heap and update sum
            minHeap.push(current_num1_val);
            current_sum_of_top_k_from_nums1 += current_num1_val;
            
            // If heap size exceeds k, remove the smallest element from sum and heap
            if (minHeap.size() > k) {
                current_sum_of_top_k_from_nums1 -= minHeap.top();
                minHeap.pop();
            }
            
            // If we have exactly k elements in the heap, it's a valid candidate subsequence
            // The current_num2_val is the minimum of nums2 for this subsequence (due to sorting)
            if (minHeap.size() == k) {
                max_score_found = max(max_score_found, current_sum_of_top_k_from_nums1 * current_num2_val);
            }
        }
        
        return max_score_found;
    }
};

/*
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> sortedNums;
        int n = nums2.size();
        sortedNums.reserve(n);

        for (int i=0; i<n; i++)
            sortedNums.push_back({nums1[i], nums2[i]});

        sort(sortedNums.begin(), sortedNums.end(), [](const pair<int,int>& a, const pair<int,int>& b) -> bool { return a.second > b.second; });
        
        priority_queue<int, vector<int>, greater<int>> maxOfNums1;
        long long sum = 0;
        auto it = sortedNums.begin();
        for (int i=0; true; i++) {
            maxOfNums1.push(it->first);
            sum += it->first;
            if (i+1 == k)
                break;
            it++;
        }

        long long maximum = sum * it->second;

        for (it++; it != sortedNums.end(); it++) {
            if (it->first > maxOfNums1.top()) {
                sum = sum - maxOfNums1.top() + it->first;
                maxOfNums1.pop();
                maxOfNums1.push(it->first);
                
                maximum = max(sum * it->second, maximum);
            }
        }

        return maximum;
    }
};
*/