__________________________________________________________________________________________________
sample 16 ms submission
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
    int height(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        return max(height(root->left), height(root->right)) + 1;
    }
    
    void helper(TreeNode* node, int level, vector<int>& res) {
        if(node == NULL)
            return;
        
        if(node->val > res[level])
            res[level] = node->val;
        
        helper(node->left, level + 1, res);
        helper(node->right, level + 1, res);
    }
    
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL)
            return {};
        
        int h = height(root);
        
        vector<int> res(h, INT_MIN);
        helper(root, 0, res);
        
        return res;
    }
};

static auto s = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;   
}();
__________________________________________________________________________________________________
sample 20880 kb submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// DFS
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> max;
        int level = 0;
        dfs(root, max, level);
        return max;
    }
    
    void dfs(TreeNode* root, vector<int>& max, int level){
        if(!root) return;
        
        if(max.size() < level + 1){
            max.push_back(root->val);
        }else{
            if(root->val > max[level]){
                max[level] = root->val;
            }
        }
        
        dfs(root->left, max, level + 1);
        dfs(root->right, max, level + 1);
        
    }
};

// Fast I/O
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
__________________________________________________________________________________________________
