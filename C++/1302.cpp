__________________________________________________________________________________________________
sample 20 ms submission
static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL; }();

class Solution {
    unordered_map<int,int> deepSum;
    int deepest{-1};
public:    
    int deepestLeavesSum(TreeNode* root) {
        if( !dfs_update(root,0) ) return 0;

        return deepSum[deepest];
    }
    
    bool dfs_update(TreeNode* node, int lvl){
        if (node == nullptr) return false;
        
        if (lvl>=deepest){
            deepest = lvl;
            deepSum[lvl] += node->val;
        }                 

        dfs_update(node->left,lvl+1);
        dfs_update(node->right,lvl+1);
        
        return true;
    }
};
__________________________________________________________________________________________________
sample 24 ms submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static const int _IO_SPEED_UP_ = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        return deepestLeavesSumAndDepth(root).first;
    }
    
private:
    typedef std::pair<int, int> DepthResult; // sum and depth
    
    DepthResult deepestLeavesSumAndDepth(TreeNode* root) {
        if(root == nullptr) {
            return DepthResult(0, -1);
        }
        
        
        if (root->left == nullptr && root->right == nullptr) {
            return DepthResult(root->val, 0);
        }
        
        DepthResult leftResult = deepestLeavesSumAndDepth(root->left),
                    rightResult = deepestLeavesSumAndDepth(root->right);
        
        auto result =   leftResult.second > rightResult.second ? leftResult :
                        rightResult.second > leftResult.second ? rightResult :
                        DepthResult(leftResult.first + rightResult.first, leftResult.second);
        
        ++result.second;
        
        return result;
    }
};
__________________________________________________________________________________________________
