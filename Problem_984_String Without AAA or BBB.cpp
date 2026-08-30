class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans;

        while (a > 0 || b > 0) {

            // Last two characters are same
            if (ans.size() >= 2 &&
                ans[ans.size() - 1] == ans[ans.size() - 2]) {

                if (ans.back() == 'a') {
                    ans += 'b';
                    b--;
                } else {
                    ans += 'a';
                    a--;
                }
            }

            // Otherwise use the character with larger count
            else {
                if (a >= b && a > 0) {
                    ans += 'a';
                    a--;
                } else {
                    ans += 'b';
                    b--;
                }
            }
        }

        return ans;
    }
};
