#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

bool helper(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    if (left->val != right->val) return false;
    return helper(left->right, right->left) && helper(left->left, right->right);
}
bool isSymmetric(TreeNode* root) {
    return helper(root, root);
}