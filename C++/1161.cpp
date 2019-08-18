__________________________________________________________________________________________________
Runtime: 216 ms
Memory Usage: 70.4 MB
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> sums;
void dfs(TreeNode* r, int lvl) {
  if (r != nullptr) {
    if (sums.size() < lvl) sums.resize(lvl);
    sums[lvl - 1] += r->val;
    dfs(r->left, lvl + 1);
    dfs(r->right, lvl + 1);
  }
}
int maxLevelSum(TreeNode* r, int res = 0) {
  dfs(r, 1);
  for (auto i = 1; i < sums.size(); ++i) {
    if (sums[i] > sums[res]) res = i;
  }
  return res + 1;
}
};
__________________________________________________________________________________________________
sample 244 ms submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int> sum;
    void dfs(TreeNode* root, int level = 0){
        if(root == NULL){
            return;
        }
        if(level >= sum.size() ){
            sum.push_back(0);
        }
        sum[level] += root->val;
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    int maxLevelSum(TreeNode* root) {
        sum.clear();
        dfs(root);
        int maximum = *max_element(sum.begin(), sum.end());
        for(int i = 0; i < (int)sum.size(); i++){
            if(sum[i] == maximum){
                    return i + 1;
            }
        }
        return (int)sum.size();
    }
};
__________________________________________________________________________________________________
