/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            // Binary search on eating speed k
            int left = 1;
            int right = *max_element(piles.begin(), piles.end());
            while (left < right) {
                int mid = left + (right - left) / 2;
                long long hours = 0;
                for (int p : piles) {
                    // ceil division without floating point
                    hours += (p + mid - 1) / mid;
                    // Early break if hours already exceed h to save time
                    if (hours > h) break;
                }
                if (hours <= h) {
                    right = mid; // try smaller k
                } else {
                    left = mid + 1; // need bigger k
                }
            }
            return left;
        }
};
/*
class Solution {
public:
    long long totalHours(vector<int>& piles, int k) {
        long long hours = 0;
        for (long long int pile : piles) {
            hours += (pile + (long long)k - 1) / k; // Cast if needed
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end()); 
        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = totalHours(piles, mid); // Make sure this is long long

            if (hours <= h) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
};
*/