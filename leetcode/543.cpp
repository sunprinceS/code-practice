int ans;
bool isLeaf(TreeNode* node){
  return (node->left == NULL && node->right == NULL);
}
int diameterOfBinaryTree(TreeNode* root){
  ans = 1;
  find_depth(root);
  return ans;
}
int find_depth(TreeNode* node){
}
