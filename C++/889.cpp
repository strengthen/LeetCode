__________________________________________________________________________________________________
sample 8 ms submission
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        vector<TreeNode*> st{new TreeNode(pre[0])};
        for (int i = 1, j = 0; i < n; ++i) {
            int v = pre[i];
            auto tn = new TreeNode(v);
            while (st.back()->val == post[j]) {
                st.pop_back();
                ++j;
            }
            if (!st.back()->left) st.back()->left = tn;
            else st.back()->right = tn;
            st.push_back(tn);
        }
        return st[0];
    }
};
__________________________________________________________________________________________________
sample 11100 kb submission
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
         vector<TreeNode*> nodes;
        nodes.push_back(new TreeNode(pre[0]));
        for(int i=1, j=0; i<pre.size(); ++i)
        {
            TreeNode* node = new TreeNode(pre[i]);
            while(nodes.back()->val == post[j])
            {
                nodes.pop_back();
                j++;
            }
            if(nodes.back()->left == NULL) {nodes.back()->left = node;}
            else {nodes.back()->right = node;}
            nodes.push_back(node);
        }
        return nodes[0];
        
    }
    
};
__________________________________________________________________________________________________
