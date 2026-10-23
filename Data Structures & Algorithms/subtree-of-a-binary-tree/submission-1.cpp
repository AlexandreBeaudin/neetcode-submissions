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
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr || subRoot == nullptr) {
            return root == subRoot;
        }
        if (root->val != subRoot->val) {
            return false;
        }
        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr || subRoot == nullptr) {
            return root == subRoot;
        }
        if (root->val == subRoot->val) {
            return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        /*
        if (root == nullptr || subRoot == nullptr) {
            return (root == subRoot);
        }
        if (root->left == nullptr && root->right == nullptr && subRoot->left == nullptr && subRoot->right == nullptr) {
            return true;
        }

        if (root->val != subRoot->val) {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
        */
    }
};
