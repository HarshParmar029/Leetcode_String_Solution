class Solution {
public:
    int minOperations(string s) {

        int n = s.length();
        int ans = INT_MAX;

        for (int r = 0; r < n; r++) {

            // r left rotations
            int cost = r;

            for (int i = 0; i < n / 2; i++) {

                int a = s[(r + i) % n] - 'a';
                int b = s[(r + n - 1 - i) % n] - 'a';

                // Cost to make a and b equal
                int cost1 = (b - a + 26) % 26;
                int cost2 = (a - b + 26) % 26;

                cost += min(cost1, cost2);
            }

            ans = min(ans, cost);
        }

        return ans;
    }
};
