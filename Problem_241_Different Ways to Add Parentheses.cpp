class Solution {
public:

    vector<int> solve(string s) {

        vector<int> ans;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {

                // Left part
                vector<int> left = solve(s.substr(0, i));

                // Right part
                vector<int> right = solve(s.substr(i + 1));

                // Combine left and right results
                for (int a : left) {
                    for (int b : right) {

                        if (s[i] == '+')
                            ans.push_back(a + b);

                        else if (s[i] == '-')
                            ans.push_back(a - b);

                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }

        // If there is no operator, it is just a number
        if (ans.empty()) {
            ans.push_back(stoi(s));
        }

        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};
