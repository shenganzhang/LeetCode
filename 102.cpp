#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> results;
    if (!root) return results;
    queue<TreeNode*> current;
    queue<TreeNode*> next;
    current.push(root);
    while (!current.empty()) {
        vector<int> temp;
        while(!current.empty()) {
            auto elem = current.front(); current.pop();
            if (elem -> left) next.push(elem->left);
            if (elem -> right) next.push(elem->right);
            temp.push_back(elem->val);
        }
        results.push_back(temp);
        while(!next.empty()) {
            auto elem = next.front(); next.pop();
            current.push(elem);
        }
    }
    return results;
}