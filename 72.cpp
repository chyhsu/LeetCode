#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
    public:
        int minDistance(string word1, string word2) {
            int n = word1.length();
            int m = word2.length();
            vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
            for(int i=1; i<=n; i++) {
                dp[i][0] = i;
            }
            for(int j=1; j<=m; j++) {
                dp[0][j] = j;
            }
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=m; j++) {
                    if(word1[i-1] == word2[j-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    }
                }
            }
            for(auto i:dp){
                for(auto j:i){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
            return dp[n][m];
        }
    };
/*
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        for(int j = 0; j <= m; j++) prev[j] = j;

        for(int i=1;i<=n;i++){
            curr[0] = i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j]=0+prev[j-1];
                }else{
                    int insert=1+curr[j-1];
                    int deletion=1+prev[j];
                    int replace=1+prev[j-1];
                    curr[j]=min(insert,min(deletion,replace));
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};
*/