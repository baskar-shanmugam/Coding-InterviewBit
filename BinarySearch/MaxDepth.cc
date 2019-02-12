/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
min depth = 2.*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 void calDepth(TreeNode* A, int& d) {
    if (A == NULL)
        return;
    if (A->left == NULL && A->right == NULL) {
        d++;
        return;
    }
        
    int tempL = 0;
    int tempR = 0;
    calDepth(A->left, tempL);
    if (tempL) tempL++;
    calDepth(A->right, tempR);
    if (tempR) tempR++;
    if (tempL && tempR) {
        if (tempL< tempR)
            d = tempL;
        else
            d = tempR;
    } else if (tempL) {
        d = tempL;
    } else {
        d = tempR;
    }
    return;
 }
 
int Solution::minDepth(TreeNode* A) {
    int depth = 0;
    calDepth(A, depth);
    return depth;
}

