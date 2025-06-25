#include<string>
#include<vector>
using namespace std;
class Solution {
    public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

/*
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();

       vector<int>prev(m+1,0);
       vector<int>curr(m+1,0);
       
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {   if(text1[i-1]==text2[j-1])
                {
                    curr[j]=prev[j-1]+1;
                }
                else 
                curr[j]=max(prev[j],curr[j-1]);


            }
            prev=curr;
        }
        return prev[m];
    }
};
*/