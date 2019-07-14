__________________________________________________________________________________________________
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
    map<TreeNode *, int> depth;
    map<TreeNode *, TreeNode *> parent;
    int deepest;

    void dfs(TreeNode *node, TreeNode *par) {
        if (node == nullptr)
            return;

        parent[node] = par;
        depth[node] = par == nullptr ? 0 : depth[par] + 1;
        deepest = max(deepest, depth[node]);
        dfs(node->left, node);
        dfs(node->right, node);
    }

    TreeNode *lca(TreeNode *a, TreeNode *b) {
        while (a != b) {
            if (depth[a] < depth[b])
                swap(a, b);

            a = parent[a];
        }

        return a;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth.clear();
        parent.clear();
        deepest = 0;
        dfs(root, nullptr);
        vector<TreeNode *> leaves;

        for (pair<TreeNode *, int> p : depth)
            if (p.second == deepest)
                leaves.push_back(p.first);

        TreeNode *answer = leaves[0];

        for (int i = 1; i < (int) leaves.size(); i++)
            answer = lca(answer, leaves[i]);

        return answer;
    }
};
__________________________________________________________________________________________________
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
    
    int dfs(TreeNode* root) {
        int ans = 0;
        if (root->left != NULL) ans = max(ans, 1 + dfs(root->left));
        if (root->right != NULL) ans = max(ans, 1 + dfs(root->right));
        return ans;
    }
    
    int DP;
    
    pair<TreeNode*, bool> dfs2(TreeNode* root, int dp) {
        pair<TreeNode*, bool> p1, p2;
        if (root->left != NULL) p1 = dfs2(root->left, dp + 1);
        if (root->right != NULL) p2 = dfs2(root->right, dp + 1);
        
        if (p1.second) {
            if (p2.second) return make_pair(root, true);
            else return p1;
        } else {
            if (p2.second) return p2;
            else {
                if (dp == DP) return make_pair(root, true);
                else return make_pair(root, false);
            }
        }
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        DP = dfs(root);
        return dfs2(root, 0).first;
    }
};

__________________________________________________________________________________________________
