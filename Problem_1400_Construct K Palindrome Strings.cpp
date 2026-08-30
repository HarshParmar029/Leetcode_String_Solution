class Solution {
public:
    bool canConstruct(string s, int k) {
        
        // We cannot make more strings than the
        // total number of characters.
        if (k > s.length()) {
            return false;
        }

        // Frequency of each lowercase character
        int freq[26] = {0};

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Count characters having odd frequency
        int odd = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                odd++;
            }
        }

        // Each palindrome needs at least one odd-frequency
        // character as its center.
        if (odd > k) {
            return false;
        }

        return true;
    }
};
