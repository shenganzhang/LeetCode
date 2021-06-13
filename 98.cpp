#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

bool helper(double upper, double lower, TreeNode* current) {
    if (!current) return true;
    if (current->val >= upper || current->val <= lower) return false;
    return helper(current->val, lower, current->left) && helper(upper, current->val, current->right);
}

bool isValidBST(TreeNode* root) {
    return helper(std::numeric_limits<double>::infinity(), -std::numeric_limits<double>::infinity(), root);
}
