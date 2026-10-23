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
    vector<int> final;
public:
    void preorder_helper(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        final.push_back(node->val);
        preorder_helper(node->left);
        preorder_helper(node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder_helper(root);
        return final;
    }
};