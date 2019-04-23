__________________________________________________________________________________________________
8ms
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
    int depth(TreeNode *root) {
    if (!root) return 0;
    return max(depth(root->left),depth(root->right))+1;
}

void levelOrder(vector<vector<int>> &ans, TreeNode *node, int level) {
    if (!node) return;
    ans[level].push_back(node->val);
    levelOrder(ans,node->left,level-1);
    levelOrder(ans,node->right,level-1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    int d = depth(root);
    vector<vector<int>> ans(d,vector<int> {});
    levelOrder(ans,root,d-1);
    return ans;
}
};
__________________________________________________________________________________________________
13508 kb
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode*> myq;
        myq.push(root);
        int i=-1;
        while(!myq.empty()){
            int t = myq.size();
            i++;
            vector<int> tmp;
            ans.push_back(tmp);
            for (int k=0;k<t;k++){
                TreeNode* kirt = myq.front();
                myq.pop();
                ans[i].push_back(kirt->val);
                if(kirt->left)
                    myq.push(kirt->left);
                if (kirt->right)
                    myq.push(kirt->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
__________________________________________________________________________________________________
