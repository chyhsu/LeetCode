/*
LeetCode 392 – Is Subsequence
----------------------------
Problem (re-phrased):
Given two strings s and t, determine whether s is a subsequence of t –
that is, whether you can obtain s by deleting zero or more characters
from t without changing the relative order of the remaining characters.

Input
 • string s – candidate subsequence, length 0 ≤ |s| ≤ 100.
 • string t – source string, length 0 ≤ |t| ≤ 10⁴.

Output
 • bool – true if s is a subsequence of t, false otherwise.
----------------------------
*/
#include <string>
using namespace std;
class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int cut=0;
            bool check=false;
            for(auto i:s){
                check=false;
                for(int j=cut;j<t.length();++j){
                    if(t[j]==i){
                        cut=j+1;
                        check=true;
                        break;
                    }
                }
                if(!check){
                    return false;
                }
            }
            return true;
            
        }
    };

// Reference Solution
// class Solution {
//     public:
//         bool isSubsequence(string s, string t) {
//             int i = 0;
//             int j = 0;
//             while (i < s.length() && j < t.length()) {
//                 if (s[i] == t[j]) {
//                     i++;
//                 }
//                 j++;
//             }
//             return i == s.length();
//         }
//     };
