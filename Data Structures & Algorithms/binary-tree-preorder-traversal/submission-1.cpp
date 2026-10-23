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
    void preorderTraversal_helper(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        theVector.push_back(node->val);
        preorderTraversal_helper(node->left);
        preorderTraversal_helper(node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorderTraversal_helper(root);
        return theVector;
    }
};