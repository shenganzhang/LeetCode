TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return nullptr;
    auto result = new TreeNode();
    result->val += root1? root1->val:0;
    result->val += root2? root2->val:0;
    result->left = mergeTrees(root1? root1->left:nullptr, root2? root2->left:nullptr);
    result->right = mergeTrees(root1? root1->right:nullptr, root2? root2->right:nullptr);
    return result;
}