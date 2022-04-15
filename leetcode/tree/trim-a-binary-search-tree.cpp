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
  void trimLow(TreeNode *t, int low) {
    if (!t)
      return;
    if (t->val == low) {
      t->left = nullptr;
    } else if (t->val > low) {
      trimLow(t->left, low);
    } else {
      if (!t->right)
        return;
      int val = t->right->val;
      TreeNode *l = t->right->left;
      TreeNode *r = t->right->right;
      t->val = val;
      t->left = l;
      t->right = r;
      trimLow(t, low);
    }
  }

  void trimHigh(TreeNode *t, int high) {
    if (!t)
      return;
    if (t->val == high) {
      t->right = nullptr;
    } else if (t->val < high) {
      trimHigh(t->right, high);
    } else {
      if (!t->left)
        return;
      int val = t->left->val;
      TreeNode *l = t->left->left;
      TreeNode *r = t->left->right;
      t->val = val;
      t->left = l;
      t->right = r;
      trimHigh(t, high);
    }
  }

  TreeNode *trimBST(TreeNode *root, int low, int high) {
    TreeNode *ll = root;
    while (ll->left) {
      ll = ll->left;
    }
    if (high < ll->val)
      return nullptr;

    TreeNode *hh = root;
    while (hh->right) {
      hh = hh->right;
    }
    if (low > hh->val)
      return nullptr;

    trimLow(root, low);
    trimHigh(root, high);
    return root;
  }
};
