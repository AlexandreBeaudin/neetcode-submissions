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
    vector<int> inorder;
public:
    void inorderTraversal_helper(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal_helper(node->left); 
        inorder.push_back(node->val);
        inorderTraversal_helper(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorderTraversal_helper(root);
        return inorder;
    }
};