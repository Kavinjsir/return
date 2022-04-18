class Solution {
public:
  TreeNode *increasingBST(TreeNode *root) {

    TreeNode *prev = NULL, *node = root;

    while (node != NULL) {

      if (node->left == NULL) {
        prev = node;
        node = node->right;
        continue;
      }

      TreeNode *child = node->left;
      TreeNode *left = child->right;

      child->right = node;
      node->left = left;

      if (prev == NULL)
        root = child;
      else
        prev->right = child;

      node = child;
    }

    return root;
  }
};
