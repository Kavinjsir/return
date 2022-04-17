class Solution {
public:
  TreeNode *traverse(TreeNode *origin, TreeNode *record) {
    if (!origin)
      return record;

    TreeNode *nr = traverse(origin->left, record);

    nr->right = new TreeNode(origin->val);

    return traverse(origin->right, nr->right);
  }

  TreeNode *increasingBST(TreeNode *root) {
    TreeNode *pre = new TreeNode();
    traverse(root, pre);
    return pre->right;
  }
};
