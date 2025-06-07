class Solution {
    public:
        
        
        string reverseVowels(string s) {
            int front=0;
            int back=s.length()-1;
            char temp;
            
       
            while(front<=back)
            {
                if((s[front]=='a' || s[front]=='e' || s[front]=='o'|| s[front]=='i' || s[front]=='u') || (s[front]=='A' || s[front]=='E' || s[front]=='O'|| s[front]=='I' || s[front]=='U')){
                    if((s[back]=='a' || s[back]=='e' || s[back]=='o'|| s[back]=='i' || s[back]=='u') || (s[back]=='A' || s[back]=='E' || s[back]=='O'|| s[back]=='I' || s[back]=='U')){
                        temp=s[front];
                        s[front]=s[back];
                        s[back]=temp;
                        ++front;
                        --back;
                    }else{
                        --back;
                    }
                }else{
                    ++front;
                }
            }
           
            return s;
        }
    };

// Reference Solution
// class Solution {
//     public:
//         string reverseVowels(string s) {
//              int i = 0;
//         int j = s.length() - 1;
    
//         while (i < j) {
//             // Move i to the next vowel
//             while (i < j && !isVowel(s[i])) i++;
    
//             // Move j to the previous vowel
//             while (i < j && !isVowel(s[j])) j--;
    
//             // Swap vowels
//             char temp = s[i];
//             s[i] = s[j];
//             s[j] = temp;
    
//             i++;
//             j--;
//         }
    
//         return s;  
//         }
//         bool isVowel(char c) {
//         c = tolower(c); // Make it case-insensitive
//         return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
//     }
//     };