class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string s = "";

        for (char ch : target) {
            s += 'a';

            ans.push_back(s);

            for (char c = 'b'; c <= ch; c++) {
                s.back() = c;
                ans.push_back(s);
            }
        }

        return ans;
    }
};
