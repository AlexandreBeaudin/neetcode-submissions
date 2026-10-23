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
    int maxDepth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        if (leftDepth > rightDepth) {
            return 1 + leftDepth;
        }
        return 1 + rightDepth;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return (std::abs(leftDepth - rightDepth) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};
