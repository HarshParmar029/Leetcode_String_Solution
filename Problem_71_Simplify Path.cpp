class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string current = "";

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                
                if (current == "" || current == ".") {
                    // Ignore empty part and "."
                }
                else if (current == "..") {
                    // Go to parent directory
                    if (!st.empty()) {
                        st.pop_back();
                    }
                }
                else {
                    // Normal directory name
                    st.push_back(current);
                }

                current = "";
            }
            else {
                current += path[i];
            }
        }

        // Build the answer
        string ans = "";

        for (string dir : st) {
            ans += "/" + dir;
        }

        // Root directory
        if (ans == "") {
            return "/";
        }

        return ans;
    }
};
