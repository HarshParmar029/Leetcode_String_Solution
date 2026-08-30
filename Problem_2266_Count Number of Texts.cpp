class Solution {
public:
    int countTexts(string pressedKeys) {
        const int MOD = 1000000007;

        int n = pressedKeys.size();
        vector<long long> dp(n + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            // Press current key once
            dp[i] = dp[i - 1];

            // Same key 2 times
            if (i >= 2 && pressedKeys[i - 1] == pressedKeys[i - 2]) {
                dp[i] = (dp[i] + dp[i - 2]) % MOD;
            }

            // Same key 3 times
            if (i >= 3 &&
                pressedKeys[i - 1] == pressedKeys[i - 2] &&
                pressedKeys[i - 2] == pressedKeys[i - 3]) {
                dp[i] = (dp[i] + dp[i - 3]) % MOD;
            }

            // Keys 7 and 9 can have 4 letters
            if (i >= 4 &&
                (pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9') &&
                pressedKeys[i - 1] == pressedKeys[i - 2] &&
                pressedKeys[i - 2] == pressedKeys[i - 3] &&
                pressedKeys[i - 3] == pressedKeys[i - 4]) {
                dp[i] = (dp[i] + dp[i - 4]) % MOD;
            }
        }

        return dp[n];
    }
};
