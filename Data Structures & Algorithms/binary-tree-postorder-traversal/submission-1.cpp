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
    vector<int> theVector;
public:
    void postorderTraversal_helper(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        postorderTraversal_helper(node->left);
        postorderTraversal_helper(node->right);
        theVector.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorderTraversal_helper(root);
        return theVector;
    }
};