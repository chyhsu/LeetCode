#include<vector>
using namespace std;
class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int r=0;
            for(auto i:nums){
                r^=i;
            }
            return r;
        }
    };