/*
LeetCode 1732 – Find the Highest Altitude
----------------------------------------
Problem (re-phrased):
You are given a list gain where gain[i] is the net gain in altitude
between point i and point i+1 on a bike trip starting at altitude 0.
Return the highest altitude reached at any point of the trip (including
starting point).

Input
 • vector<int>& gain – 1 ≤ |gain| ≤ 100, -100 ≤ gain[i] ≤ 100.

Output
 • int – maximum altitude reached.
----------------------------------------
*/
#include <vector>
using namespace std;

class Solution {
    public:
        int largestAltitude(vector<int>& gain) {
            int max=0;
            int temp=0;
            vector<int> altitude;
            altitude.push_back(0);
            for(int i=0;i<gain.size();++i){
                temp=altitude[i]+gain[i];
                altitude.push_back(temp);
                if(temp>max){
                    max=temp;
                }
            }
            return max;
        }
    };

//Reference Solution
// class Solution {
//     public:
//         int largestAltitude(vector<int>& gain) {
//             int alt = 0;
//             int maxAlt = 0;
    
//             for (int g : gain) {
//                 alt += g;
//                 maxAlt = max(maxAlt, alt);
//             }
    
//             return maxAlt;
//         }
//     };