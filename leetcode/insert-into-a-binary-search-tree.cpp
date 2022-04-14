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
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    TreeNode *c = root;
    if (!c) {
      c = new TreeNode(val);
      return c;
    }
    while (c) {
      if (val > c->val) {
        if (c->right) {
          c = c->right;
        } else {
          c->right = new TreeNode(val);
          break;
        }
      } else {
        if (c->left) {
          c = c->left;
        } else {
          c->left = new TreeNode(val);
          break;
        }
      }
    }
    return root;
  }
};
