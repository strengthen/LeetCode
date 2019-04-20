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
    int idx;
    TreeNode* helper(string S, int level) {
        if(S.empty()) return nullptr;
        auto root = new TreeNode(atoi(S.substr(idx).c_str()));
        int n = S.size();
        // get rid of digits
        while(idx < n && S[idx] != '-') 
            idx++;
        int i, cnt;
        // check left and right child
        for(int k = 0; k < 2; k++){
            i = idx, cnt = 0;
            // count '-'
            for(; i < n; i++){
                if(S[i] != '-')
                    break;
                else
                    cnt++;
            }
            if(cnt == level+1){
                idx = i;
                if(!root->left)
                    root->left = helper(S, level+1);
                else
                    root->right = helper(S, level+1);
            }
        }
        return root;   
    }
    
    TreeNode* recoverFromPreorder(string S) {
        idx = 0;
        return helper(S, 0);
    }
};