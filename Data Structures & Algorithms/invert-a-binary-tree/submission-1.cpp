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
    void flip(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        TreeNode* leftNode = node->left;
        TreeNode* rightNode = node->right;
        node->left = rightNode;
        node->right = leftNode;
        flip(node->left);
        flip(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        flip(root);
        return root;
    }
};
