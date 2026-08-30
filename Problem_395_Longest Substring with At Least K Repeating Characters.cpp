class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.length() < k)
            return 0;

        // Count frequency of every character
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Find a character whose frequency is less than k
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i] - 'a'] < k) {
                // Split around this invalid character
                string left = s.substr(0, i);
                string right = s.substr(i + 1);

                return max(
                    longestSubstring(left, k),
                    longestSubstring(right, k)
                );
            }
        }

        // Every character occurs at least k times
        return s.length();
    }
};
