class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> used(26, false);

        // Count frequency of every character
        for (char c : s) {
            freq[c - 'a']++;
        }

        string st;

        for (char c : s) {
            freq[c - 'a']--;

            // Already present in answer
            if (used[c - 'a']) {
                continue;
            }

            // Remove bigger characters if they appear again later
            while (!st.empty() &&
                   st.back() > c &&
                   freq[st.back() - 'a'] > 0) {

                used[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            used[c - 'a'] = true;
        }

        return st;
    }
};
