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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        return balanced(root) && isBalanced(root->left) && isBalanced(root->right);
    }

    bool balanced(TreeNode* root) {
        if (root == nullptr) return true;
        int heightDifference = height(root->left) - height(root->right);
        return heightDifference >=-1 && heightDifference <=1;
    }

    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};
