#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int minDepth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    if(root->left == nullptr && root ->right == nullptr) {
        return 1;
    } else if(root->left != nullptr && root ->right == nullptr) {
        return minDepth(root->left) + 1;
    } else if(root->left == nullptr && root ->right != nullptr) {
        return minDepth(root->right) + 1;
    }
    return min(minDepth(root->left) + 1, minDepth(root->right) + 1);
}

