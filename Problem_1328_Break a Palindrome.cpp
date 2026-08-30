class Solution {
public:
    string breakPalindrome(string palindrome) {

        int n = palindrome.length();

        // Single character cannot be made non-palindrome
        if (n == 1) {
            return "";
        }

        // Check first half
        for (int i = 0; i < n / 2; i++) {

            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        // If first half contains only 'a'
        palindrome[n - 1] = 'b';

        return palindrome;
    }
};
