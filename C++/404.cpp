__________________________________________________________________________________________________
sample 8 ms submission

class Solution {
public:
    int leftsum(TreeNode* node, int flag)
    {
        if(node==NULL) return 0;
        if(node->left==NULL && node->right==NULL){
            if(flag==0){
                return node->val;
            }else{
                return 0;
            }
        }else{
            return leftsum(node->left,0) + leftsum(node->right,1);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if (root==NULL) return 0;
        return leftsum(root->left,0) + leftsum(root->right,1);
        
    }
};

__________________________________________________________________________________________________
sample 13532 kb submission
auto fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool left = false) {
        if (!root) return 0;
        else if (!root->left && !root->right) return left ? root->val : 0;
        else {
            return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right);
        }
    }
};
__________________________________________________________________________________________________
