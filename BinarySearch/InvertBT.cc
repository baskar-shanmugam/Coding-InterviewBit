/*
Given a binary tree, invert the binary tree and return it. 
Look at the example for more details.

Example : 
Given binary tree

     1
   /   \
  2     3
 / \   / \
4   5 6   7
invert and return

     1
   /   \
  3     2
 / \   / \
7   6 5   4
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* Solution::invertTree(TreeNode* A) {
    if (A == NULL)
        return A;
    if (A->left ==NULL && A->right == NULL)
        return A;
    invertTree(A->left);
    invertTree(A->right);
    TreeNode *tmp = A->left;
    A->left = A->right;
    A->right = tmp;
    return A;
}

