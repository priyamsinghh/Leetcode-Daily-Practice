/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  int minCameraCover(TreeNode* root) {
    vector<int> ans = dfs(root);
    return min(ans[1], ans[2]);
  }

 private:
  
  vector<int> dfs(TreeNode* root) {
    if (!root)
      return {0, 0, 1000};

    vector<int> l = dfs(root->left);
    vector<int> r = dfs(root->right);

    const int s0 = l[1] + r[1];
    const int s1 = min(l[2] + min(r[1], r[2]),r[2] + min(l[1], l[2]));
    const int s2 = 1 + min({l[0], l[1], l[2]}) + min({r[0], r[1], r[2]});

    return {s0, s1, s2};
  }
};