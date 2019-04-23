__________________________________________________________________________________________________
12ms
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
    bool hasPathSum(TreeNode* root, int sum) {
        using node_t = std::tuple<TreeNode *, int>;
        std::vector<node_t> queue;
        
        if (root) {queue.emplace_back(root, root->val);}
        while (queue.size()) {
            const auto node = std::get<0>(queue.back());
            const auto path_sum = std::get<1>(queue.back());
            queue.pop_back();
            if (node->left == nullptr && node->right == nullptr) {
                if (path_sum == sum) {return true;}
                continue;
            }
            if (node->left) {
                queue.emplace_back(node->left, node->left->val + path_sum);
            }
            if (node->right) {
                queue.emplace_back(node->right, node->right->val + path_sum);
            }
        }
        return false;
    }
};

static string s=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return "";
}();
__________________________________________________________________________________________________
19556 kb
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
    bool hasPathSumHelper(TreeNode* root, int sum)
    {
        bool left = false;
        bool right = false;
        sum = sum - root->val;
        if((root->left == NULL) && (root->right == NULL) )
        {
            return (sum == 0);
        }       
        
        if (root->left != NULL) left = hasPathSumHelper(root->left, sum );//- root->val);
        if (root->right != NULL) right = hasPathSumHelper(root->right, sum); // - root->val);
        
        return (left || right);        
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        bool left = false;
        bool right = false;
        if(root == NULL)
        {
            return false;
        }
        
        sum = sum - root->val;
        if((root->left == NULL) && (root->right == NULL) )
        {
            return (sum == 0);
        }       
        
        left = hasPathSum(root->left, sum );
        right = hasPathSum(root->right, sum); 
        
        return (left || right); 
    }
};
__________________________________________________________________________________________________
