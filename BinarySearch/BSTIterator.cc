/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.

 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
Try to optimize the additional space complexity apart from the amortized time complexity. 

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

vector<int> val;
int itr = 0;
void inorder(TreeNode*r, vector<int> &v) {
    if (r == NULL) return;
    inorder(r->left, v);
    v.push_back(r->val);
    inorder(r->right, v);
}
BSTIterator::BSTIterator(TreeNode *root) {
    inorder(root, val);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return (itr < val.size())? true:false;
}

/** @return the next smallest number */
int BSTIterator::next() {
    return val[itr++];
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

