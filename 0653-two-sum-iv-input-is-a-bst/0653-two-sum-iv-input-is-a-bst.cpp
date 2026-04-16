class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        // Inorder traversal (iterative)
        while (curr != NULL || !st.empty()) {
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            arr.push_back(curr->val);
            curr = curr->right;
        }

        // Two pointer approach
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == k)
                return true;
            else if (sum < k)
                left++;
            else
                right--;
        }

        return false;
    }
};