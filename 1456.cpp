class Solution {
    public:
        int isVowel(char i){
            return (i=='a' || i=='e' || i=='i' || i=='o' || i=='u');
        }

        int maxVowels(string s, int k) {
            
            int cur=0;
            string cur_string="";
            for(int i=0;i<k;++i){
                if(isVowel(s[i])) ++cur;
                cur_string+=s[i];
            }
            int j=k-1;
            int max=cur;
            while(j<s.length()){
                ++j;
                if(isVowel(s[j-k])) --cur;
                if(isVowel(s[j])) ++cur;
                if(cur>max){
                    max=cur;
                }
            }
          
            return max;
        }
    };

//Reference Solution
// class Solution {
//     public:
//         int maxVowels(string s, int k) {
//             int count = 0, maxVowelCount = 0;
//             int n = s.size();
    
//             // Helper lambda to check if a character is a vowel
//             auto isVowel = [](char c) {
//                 return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
//             };
    
//             // Count vowels in the first window of size k
//             for (int i = 0; i < k; ++i)
//                 count += isVowel(s[i]);
//             maxVowelCount = count;
    
//             // Slide the window across the string
//             for (int i = k; i < n; ++i) {
//                 count += isVowel(s[i]);
//                 count -= isVowel(s[i - k]);
//                 maxVowelCount = max(maxVowelCount, count);
//                 if (maxVowelCount == k) return k; // Early exit if maximum possible found
//             }
    
//             return maxVowelCount;
//         }
//     };
    