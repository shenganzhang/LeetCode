class Solution {
public:
    int ans =0;
    int helper(TreeNode* root) {
        if (!root) return 0;
        int left_depth = helper(root->left);
        int right_depth = helper(root->right);
        ans = max(ans, left_depth + right_depth);
        return max(left_depth, right_depth) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return ans;
    }
};