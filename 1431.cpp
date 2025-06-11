/*
LeetCode 1431 – Kids With the Greatest Number of Candies
-------------------------------------------------------
Problem (re-phrased):
Given an array candies where candies[i] is the number of candies that the
ith child has and an integer extraCandies, for each child determine
whether they could have the greatest number of candies among all the
children if they were given all extraCandies.  Return a vector<bool>
with the answers.

Input
 • vector<int>& candies – 2 ≤ |candies| ≤ 100, 1 ≤ candies[i] ≤ 100.
 • int extraCandies      – 1 ≤ extraCandies ≤ 50.

Output
 • vector<bool> – true/false for each child.
-------------------------------------------------------
*/
#include <vector>
#include <string>
using namespace std;
class Solution {
    public:
        int max(vector<int> candies){
            int idx=0;
            int max=candies[idx];
            
            for(int i=0;i<candies.size();++i){
                if(candies[i]>max)
                {
                    idx=i;
                    max=candies[i];
                }
            }
            return max;
        }
        vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies){
            std::vector<bool> result;
            for(int i=0;i<candies.size();++i)
            {
                vector<int> temp=candies;
                temp[i]+=extraCandies;
                if(max(temp)==temp[i])
                {
                    result.push_back(true);
                }else{
                    result.push_back(false);
                }
                
                
            }
            return result;
        }
    };

// Reference Solution
// class Solution {
//     public:
//         vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
//             vector<bool> ret_vector (candies.size(),false);
//             int max_candies = *(max_element(candies.begin(), candies.end()));
    
//             for (int candy_pos = 0; candy_pos < candies.size(); ++candy_pos) {
//                 if (candies.at(candy_pos)+extraCandies >= max_candies) {
//                     ret_vector.at(candy_pos) = true;
//                 }
//             }
    
//             return ret_vector;
//         }
// };