#include <algorithm>
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
    
    