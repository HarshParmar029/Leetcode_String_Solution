class Solution {
public:

    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j])
                i++;

            j++;
        }

        return i == s.size();
    }

    int findLUSlength(vector<string>& strs) {
        int ans = -1;

        for (int i = 0; i < strs.size(); i++) {
            bool uncommon = true;

            for (int j = 0; j < strs.size(); j++) {

                if (i == j)
                    continue;

                if (isSubsequence(strs[i], strs[j])) {
                    uncommon = false;
                    break;
                }
            }

            if (uncommon) {
                ans = max(ans, (int)strs[i].size());
            }
        }

        return ans;
    }
};
