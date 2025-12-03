class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* node, int cur) {
        if (!node) return;
        cur = cur * 10 + node->val;
        if (!node->left && !node->right) {
            ans += cur;
            return;
        }
        dfs(node->left, cur);
        dfs(node->right, cur);
    }
    int sumNumbers(TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};






