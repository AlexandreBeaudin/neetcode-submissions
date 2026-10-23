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
    void postorder_helper(TreeNode* node) {
        if (node == nullptr) return;

        postorder_helper(node->left);
        postorder_helper(node->right);
        final.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder_helper(root);
        return final;
    }
};