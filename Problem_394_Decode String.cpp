class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;

        string current = "";
        int num = 0;

        for (char ch : s) {

            // If character is a digit
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            // If '[' comes
            else if (ch == '[') {
                numStack.push(num);
                strStack.push(current);

                num = 0;
                current = "";
            }

            // If ']' comes
            else if (ch == ']') {
                int repeat = numStack.top();
                numStack.pop();

                string previous = strStack.top();
                strStack.pop();

                string temp = "";

                // Repeat current string
                for (int i = 0; i < repeat; i++) {
                    temp += current;
                }

                current = previous + temp;
            }

            // If normal alphabet
            else {
                current += ch;
            }
        }

        return current;
    }
};
