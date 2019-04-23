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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> out;
        vector<int> path;
        vector<TreeNode*> nodes;
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        TreeNode* current = NULL;
        int c_sum = 0;
        int inf = INT_MAX;
        int cur_val = 0;
        if(root == NULL)
            return out;
        
        nodes.push_back(root);
        while(nodes.size() != 0)
        {
            current = nodes.back();
            cur_val = current->val;
            if(cur_val != inf)
            {
                path.push_back(cur_val);
                c_sum +=cur_val;
            } 
            left = current->left;
            right = current->right;
            if(left != NULL)
            {
                current->left = NULL;
                nodes.push_back(left);
                current->val = inf;
            }
            else if(right != NULL)
            {
                current->right = NULL;
                nodes.push_back(right);
                current->val = inf;
            }
            else
            {
                if(c_sum == sum && cur_val != inf)
                    out.push_back(path);
                c_sum -= path.back();
                path.pop_back();
                nodes.pop_back();
            }
        }
        return out;
        
    }
};
__________________________________________________________________________________________________
18688 kb
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
std::vector<int> path;

void foo(TreeNode *tree, std::vector<std::vector<int>> &results, int target) {
    path.clear();
    TreeNode *current = tree;
    int sum = 0;
    while(current != nullptr) {
        if(current->left == nullptr) {
            path.push_back(current->val);
            sum += current->val;
            if(current->right == nullptr) {
                if(sum == target)
                    results.push_back(path);
            }
            current = current->right;
        }
        else {
            TreeNode *pred = current->left;
            int gap = 1;
            for(;;) {
                if(pred->right == nullptr) {
                    pred->right = current;
                    path.push_back(current->val);
                    sum += current->val;
                    current = current->left;
                    break;
                }
                if(pred->right == current) {
                    if(sum == target && pred->left == nullptr)
                        results.push_back(path);
                    pred->right = nullptr;
                    current = current->right;
                    while(gap > 0) {
                        sum -= path.back();
                        path.pop_back();
                        --gap;
                    }
                    break;
                }
                ++gap;
                pred = pred->right;
            }
        }
    }
}
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int>> results;
        if(nullptr == root)
            goto final;
        /*if(nullptr == root->left && nullptr == root->right) {
            if(root->val == sum) {
                path.clear();
                path.push_back(sum);
                results.push_back(path);
                goto final;
            }
        }*/
        foo(root, results, sum);
        final:
        return results;
    }
};
__________________________________________________________________________________________________
