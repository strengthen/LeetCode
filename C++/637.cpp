__________________________________________________________________________________________________
sample 20 ms submission
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg;
        if(!root)
            return avg;
        queue<TreeNode*> Q;
        TreeNode* curr = root;
        Q.push(curr);
        
        while(!Q.empty()){
            int L = Q.size();
            long sum = 0;
            for(int i = 0; i < L; i++){
                curr = Q.front();
                Q.pop();
                if(curr->left) Q.push(curr->left);
                if(curr->right) Q.push(curr->right);
                sum +=(curr->val);
            }
            avg.push_back((double)sum/L);
        }
        return avg;
    }
};

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;        
}();
__________________________________________________________________________________________________
sample 21816 kb submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution 
{
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> res;
        vector<TreeNode*> cur, next;
        cur.push_back(root);
        while (not cur.empty())
        {
            long long s = 0;
            for (auto it : cur)
            {
                s += it->val;
                if (it->left) next.push_back(it->left);
                if (it->right) next.push_back(it->right);
            }
            res.push_back(static_cast<double>(s)/cur.size());
            cur.swap(next);
            next.clear();
        }
        return res;
    }
};
__________________________________________________________________________________________________
