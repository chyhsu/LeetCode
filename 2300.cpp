#include <vector>
#include <algorithm>
#include <climits> // For INT_MAX
using namespace std;
/*
You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.


*/
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result(spells.size());
        
        // Sort potions in ascending order for binary search
        sort(potions.begin(), potions.end());
        
        for (int i = 0; i < spells.size(); i++) {
            // Calculate the minimum potion value needed
            // Use ceiling division to handle fractional values correctly
            long long minPotion = (success + spells[i] - 1) / spells[i]; // Ceiling division
            
            // If minPotion exceeds what's available, no potions will work
            if (minPotion > INT_MAX) {
                result[i] = 0;
                continue;
            }
            
            // Find the first potion that is >= minPotion
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            
            // Count potions from this point to the end
            result[i] = potions.end() - it;
        }
        
        return result;
    }
};
/*
class Solution {
public:
    int binarySearch(vector<int>&potions,int minPotion,int l,int r){
        int idx=-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(minPotion<=potions[mid]){
                idx=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return idx;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m=spells.size();
        int n=potions.size();

        sort(begin(potions),end(potions));
        int maxPotion=potions[n-1];

        vector<int>ans;

        for(int i=0;i<m;i++){
            long long minPotion=ceil((1.0*success)/spells[i]);

            if(minPotion>maxPotion){
                ans.push_back(0);
                continue;
            }

            int index=binarySearch(potions,minPotion,0,n-1);

            ans.push_back(n-index);
        }
        return ans;
    }
};
*/