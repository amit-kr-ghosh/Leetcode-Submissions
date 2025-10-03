/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) return nullptr;
        
        for (int i = 0; i < (int)inorder.size(); ++i) {
            inIndex[inorder[i]] = i;
        }
      
        pre = &preorder;
        return build(0, n - 1, 0, n - 1);
    }

private:
    unordered_map<int,int> inIndex;
    vector<int>* pre;

    TreeNode* build(int preL, int preR, int inL, int inR) {
        if (preL > preR || inL > inR) return nullptr;
        int rootVal = (*pre)[preL];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inIndex[rootVal];               
        int leftSize = mid - inL;                 

        root->left = build(preL + 1, preL + leftSize, inL, mid - 1);
        root->right = build(preL + leftSize + 1, preR, mid + 1, inR);

        return root;
    }
};



