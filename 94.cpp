#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
#include <algorithm>
#include <stack>
#include <utility>
#include <set>
#include <limits>

using namespace std;

void traverse(TreeNode* root, vector<int> &result) {
    if (!root) return;
    traverse(root->left, result);
    result.push_back(root->val);
    traverse(root->right, result);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> results;
    traverse(root, results);
    return results;
}