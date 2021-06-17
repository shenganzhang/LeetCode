void flatten(TreeNode* root) {
    while (root) {
        if (root->left) {
            auto connect = root->left;
            while (connect->right) connect = connect->right;
            connect->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        root = root->right;
    }
}