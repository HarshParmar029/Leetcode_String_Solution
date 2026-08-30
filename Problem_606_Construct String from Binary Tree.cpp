class Solution {
public:
    string tree2str(TreeNode* root) {
        if (root == nullptr)
            return "";

        string ans = to_string(root->val);

        // Left child
        if (root->left) {
            ans += "(" + tree2str(root->left) + ")";
        }

        // Right child
        if (root->right) {
            // If left child is absent, we must add ()
            if (!root->left)
                ans += "()";

            ans += "(" + tree2str(root->right) + ")";
        }

        return ans;
    }
};
