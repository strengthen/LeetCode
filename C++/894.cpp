__________________________________________________________________________________________________
sample 92 ms submission
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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (!(n & 1)) return {};
        static vector<vector<TreeNode*>> dp(20);
        if (dp[0].empty()) dp[0].emplace_back(new TreeNode(0));
        for (static int i = 3; i <= n; i += 2) {
            cout << dp.size() << endl;
            for (int l = 1; l < i; l += 2) {
                for (const auto &node_l : dp[l / 2]) {
                    for (const auto &node_r : dp[(i - l - 1) / 2]) {
                        TreeNode *cur = new TreeNode(0);
                        cur->left = node_l, cur->right = node_r;                        
                        dp[i / 2].emplace_back(cur);
                    }
                }
            }
        }
        return dp[n / 2];
    }
};
__________________________________________________________________________________________________
sample 20836 kb submission
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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N % 2 == 0)
            return {};
        vector<vector<TreeNode*>> dp(N+1);
        dp[1] = {new TreeNode(0)};
        for(int i = 3; i <= N; i += 2){
            for(int j = 1; j < i; j += 2){
                int k = i - j - 1;
                for(auto l : dp[j]){
                    for(auto r : dp[k]){
                        auto root = new TreeNode(0);
                        root->left = l;
                        root->right = r;
                        dp[i].push_back(root);
                    }
                }
            }
        }
        return dp[N];
    }
};
__________________________________________________________________________________________________
