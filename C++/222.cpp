__________________________________________________________________________________________________
sample 32 ms submission
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
    int countNodes(TreeNode* root) {
        static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
        if(root == NULL) return 0;
        
        int dep = 0;
        TreeNode *cur = root;
        
        while(cur->left != NULL){
            ++dep;
            cur = cur->left;
        }
        
        if(dep == 0) return 1;
        // cout << "dep: " << dep << endl;
        
        int lo = 0, hi = (1 << dep)-1;
        
        while(lo < hi){
            int mid = (lo+hi+1)/2;
            int mask = (1 << (dep-1));
            cur = root;
            int cnt = 0;
            
            while(cur != NULL){
                ++cnt;
                if(mid & mask){
                    cur = cur->right;
                }else{
                    cur = cur->left;
                }
                mask >>= 1;
            }
            
            if(cnt == dep+1) lo = mid;
            else hi = mid-1;
        }
        
        // cout << "lo: " << lo << endl;
        
        int mask = (1 << (dep-1));
        int lef = 0;
        int result = 0;
        int cur_lev = 1;
        while(mask){
            result += cur_lev;
            cur_lev *= 2;
            lef *= 2;
            if(lo & mask){
                lef += 1;
            }
            mask >>= 1;
        }
        
        // cout << "left: " << left << endl;
        // cout << "result: " << result << endl;
        result += (lef+1);
        return result;   
    }
};
__________________________________________________________________________________________________
sample 28568 kb submission
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return 1+ countNodes(root->left) + countNodes(root->right);
    }
};
__________________________________________________________________________________________________
