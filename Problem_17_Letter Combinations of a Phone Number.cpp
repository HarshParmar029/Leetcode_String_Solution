class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty())
            return ans;

        vector<string> mp = {
            "",     "",     "abc",  "def",
            "ghi",  "jkl",  "mno",  "pqrs",
            "tuv",  "wxyz"
        };

        string current;

        function<void(int)> backtrack = [&](int index) {

            // All digits processed
            if (index == digits.size()) {
                ans.push_back(current);
                return;
            }

            string letters = mp[digits[index] - '0'];

            for (char c : letters) {
                current.push_back(c);

                backtrack(index + 1);

                current.pop_back();
            }
        };

        backtrack(0);

        return ans;
    }
};
