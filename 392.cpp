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
