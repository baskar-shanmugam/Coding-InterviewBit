/*
Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if (A == NULL)
        return A;
    if (A->left == NULL && A->right == NULL)
        return A;
    flatten(A->left);
    flatten(A->right);
    TreeNode *tmpL = A->left;
    A->left = NULL;
    TreeNode *tmpR = A->right;
    A->right = tmpL;
    TreeNode *endR = tmpL;
    while(tmpL) {
        endR = tmpL;
        tmpL = tmpL->right;
    }
    if(endR)
    {endR->left = NULL;
    endR->right = tmpR;}
    return A;
}

