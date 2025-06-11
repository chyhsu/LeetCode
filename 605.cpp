/*
LeetCode 605 – Can Place Flowers
--------------------------------
Problem (re-phrased):
You are given an array flowerbed where flowerbed[i] is 1 if there is a
flower in plot i and 0 otherwise, along with an integer n.  A new flower
can be planted in a plot only if both neighboring plots are empty (or the
plot is at the boundary).  Return true if n new flowers can be planted
without violating the rule.

Input
 • vector<int>& flowerbed – 1 ≤ size ≤ 2 × 10⁴, values 0 or 1.
 • int n – number of new flowers to plant.

Output
 • bool – true if n flowers can be planted, otherwise false.
--------------------------------
*/
#include <vector>
#include <cmath>
using namespace std;

class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
            int count=0;
            flowerbed.push_back(0);
            flowerbed.insert(flowerbed.begin(),0);
            int j=0;
            for(int i=0; i<flowerbed.size();++i)
            {
                if(flowerbed[i]==0)
                {
                    ++j;
                }
                if(flowerbed[i]==1)
                {
                    count+=ceil(j/2.0)-1;
                    j=0;
                }
            }
            count+=ceil(j/2.0)-1;
            return count>=n;
        }
    };

// Reference Solution
// class Solution {
//     public:
//         bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//             int count = 0;
//             for (int i = 0; i < flowerbed.size(); ++i) {
//                 if (flowerbed.at(i) == 0 && (i == 0 || flowerbed.at(i - 1) == 0) && (i == flowerbed.size() - 1 || flowerbed.at(i + 1) == 0)) {
//                     flowerbed.at(i) = 1;
//                     ++count;
//                 }
//             }
//             return count >= n;
//         }
// };
