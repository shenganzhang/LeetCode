#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int helper(TreeNode* current, int level) {
    if (!current) return level;
    return max(helper(current->left, level + 1), helper(current->right, level + 1));
}

int maxDepth(TreeNode* root) {
    return helper(root, 0);
}