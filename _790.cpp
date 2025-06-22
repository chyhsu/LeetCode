#include <vector>
using namespace std;
class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int MOD = 1e9 + 7;
        // Using long long to be safe and prevent overflow during intermediate calculations
        vector<long long> dp(n + 1);
        dp[0] = 1; // Base case for the recurrence: one way to tile a 2x0 board (do nothing)
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            // The recurrence relation is dp[i] = 2 * dp[i-1] + dp[i-3]
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
        }

        return dp[n];
    }
};
/*
class Solution {
public:
    int numTilings(int n) {
        vector<long> fullState = {1, 2 }; // n = 1, 2
        long partialState = 1; // n = 2
        if (n <= 2) return fullState[n-1];

        int MOD = pow(10, 9) + 7;
        for(int i = 3; i <= n; i++){
            long full    = (fullState[1] + fullState[0] + 2 * partialState) % MOD;
            partialState = (partialState + fullState[0]) % MOD;
            fullState[0] = fullState[1];
            fullState[1] = full;
        }

        return (int)fullState[1];
    }
};
*/