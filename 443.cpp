/*
LeetCode 443 – String Compression
---------------------------------
Problem (re-phrased):
Given an array of characters chars, compress it in-place: for each group
of consecutive repeating characters, replace the group with the character
followed by the group's length (written as individual digits).  The
compressed string is written back into chars and the function returns the
new length.

Input
 • vector<char>& chars – 1 ≤ |chars| ≤ 2000.

Output
 • int – length of the compressed string stored in chars.
---------------------------------
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        int compress(vector<char>& chars) {
            char cur=chars[0];
            int count=0;
            std::string result="";
            for(auto i:chars){
                if(cur==i){
                    ++count;
                }else{
                    if(count!=1){
                        result+=cur;
                        result+=to_string(count);
                    }else{
                        result+=cur;
                    }
                    cur=i;
                    count=1;
                }

            }
            if(count!=1){
                result+=cur;
                result+=to_string(count);
            }else{
                result+=cur;
            }
            for(int i=0;i<result.length();++i){
                chars[i]=result[i];
            }
            return result.length();
        }
    };

// Reference Solution
// class Solution {
//     public:
//         int compress(vector<char>& chars) {
//             int i = 0;
//             int j = 0;
//             int n = chars.size();
//             while (i < n) {
//                 int count = 0;
//                 while (i < n && chars[i] == chars[j]) {
//                     ++i;
//                     ++count;
//                 }
//                 chars[j] = chars[i - 1];
//                 ++j;
//                 if (count > 1) {
//                     for (char c : to_string(count)) {
//                         chars[j] = c;
//                         ++j;
//                     }
//                 }
//             }
//             return j;
//         }
//     };