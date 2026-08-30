class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;

        for (int center = 0; center < n; center++) {
            
            // Odd length palindrome
            int l = center, r = center;
            while (l >= 0 && r < n && s[l] == s[r]) {
                ans++;
                l--;
                r++;
            }

            // Even length palindrome
            l = center;
            r = center + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                ans++;
                l--;
                r++;
            }
        }

        return ans;
    }
};
