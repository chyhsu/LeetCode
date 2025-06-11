/*
LeetCode 151 – Reverse Words in a String
---------------------------------------
Problem (re-phrased):
Given a string s, reverse the order of its words.  A word is defined as a
sequence of non-space characters.  The returned string must contain a
single space between words and must not start or end with a space.

Input
 • string s – may contain leading, trailing, or multiple spaces.

Output
 • string – words in reverse order, trimmed and single-spaced.
---------------------------------------
*/
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Solution {
    public:
        std::vector<string> collector(string s){
            string temp="";
            std::vector<string> result;
            for(auto itr=s.begin();itr<s.end();++itr){
                if(*itr==' '){
                    if(temp!=""){
                        result.push_back(temp);
                    }
                    temp.clear();
                    continue;
                }else{
                    temp.push_back(*itr);
                }

            }
            if(temp!=""){
                result.push_back(temp);
            }
            return result;
        }
        string reverseWords(string s) {
            std::vector<string> str_collected=collector(s);
            reverse(str_collected.begin(),str_collected.end());
            string result;
            for(int i=0;i<str_collected.size();++i){
                result+=str_collected.at(i);
                result+=" ";
            }
            result.erase(result.length()-1,1);
            return result;

        }
    };

// Reference Solution
// class Solution {
//     public:
//         string reverseWords(string s) {
//             vector<string> words;
//             string token;
    
//             for (auto c : s) {
//                 if (c == ' ') {
//                     if (!token.empty()) {
//                         words.push_back(token);
//                         token.clear();
//                     }
//                     continue;
//                 }
//                 token += c;
//             }
    
//             if (!token.empty()) {
//                 words.push_back(token);
//                 token.clear();
//             }
    
//             string res;
//             while (words.size() > 1) {
//                 res += words.back();
//                 res += ' ';
//                 words.pop_back();
//             }
    
//             res += words.back();
    
//             return res;
//         }
//     };
    
    