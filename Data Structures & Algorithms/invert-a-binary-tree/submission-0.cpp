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
    TreeNode* invertTreeHelper(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode *newNode = new TreeNode;
        newNode->val = root->val;
        newNode->left = invertTreeHelper(root->right);
        newNode->right = invertTreeHelper(root->left);
        return newNode;
    }
    TreeNode* invertTree(TreeNode* root) {
        return invertTreeHelper(root);
    }
};
