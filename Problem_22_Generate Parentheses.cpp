class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        function<void(string, int, int)> backtrack =
            [&](string s, int open, int close) {

                // If we used all pairs
                if (s.length() == 2 * n) {
                    ans.push_back(s);
                    return;
                }

                // We can add '(' if we still have some left
                if (open < n) {
                    backtrack(s + "(", open + 1, close);
                }

                // We can add ')' only if it will remain valid
                if (close < open) {
                    backtrack(s + ")", open, close + 1);
                }
            };

        backtrack("", 0, 0);

        return ans;
    }
};
