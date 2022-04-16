/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int traverse(TreeNode *t, int val) {
    if (!t)
      return val;

    int accumulate = traverse(t->right, val);

    t->val += accumulate;

    return traverse(t->left, t->val);
  }

  TreeNode *convertBST(TreeNode *root) {
    traverse(root, 0);
    return root;
  }
};
