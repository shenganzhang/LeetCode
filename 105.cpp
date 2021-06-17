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
class Solution {
public:

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preorder_start, int preorder_end,
                     int inorder_start, int inorder_end, unordered_map<int, int>& inorderElem2Index) {
        if (preorder_start > preorder_end) return nullptr;
        int parent = preorder[preorder_start];
        int parent_inorder_index = inorderElem2Index[parent];
        TreeNode* root = new TreeNode(parent);
        root->left = helper(preorder, inorder, preorder_start + 1, preorder_start + parent_inorder_index - inorder_start, inorder_start, parent_inorder_index - 1, inorderElem2Index);
        root->right = helper(preorder, inorder, preorder_start + parent_inorder_index - inorder_start + 1, preorder_end, parent_inorder_index + 1, inorder_end, inorderElem2Index);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderElem2Index;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderElem2Index[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inorderElem2Index);
    }
};