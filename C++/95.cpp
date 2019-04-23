__________________________________________________________________________________________________
16ms
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
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1) {
            return {};
        }
        return generateTrees(1, n);
    }
    
    vector<TreeNode*> generateTrees(int l, int r) {
        vector<TreeNode*> ret;
        if (l > r) {
            ret.push_back(nullptr);
            return ret;
        }
        string key = to_string(l) + "+" + to_string(r);
        if (map_.count(key) != 0) {
            return map_[key];
        }
        for (int i = l; i <= r; i++) {
            vector<TreeNode*> left = generateTrees(l, i - 1);
            vector<TreeNode*> right = generateTrees(i + 1, r);
            for (TreeNode* left_node : left) {
                for (TreeNode* right_node : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_node;
                    root->right = right_node;
                    ret.push_back(root);
                }
            }
        }
        map_[key] = ret;
        return ret;      
    } 
private:
    unordered_map<string, vector<TreeNode*> > map_;
};
__________________________________________________________________________________________________
11804 kb
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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) {
            return vector<TreeNode*>();
        }
    	vector<vector<vector<TreeNode*>>> dp(n + 2, vector<vector<TreeNode*>>(n + 2, vector<TreeNode*>()));
    	for(int i = 1; i <= n + 1; ++i) {
    		dp[i][i].push_back(new TreeNode(i));
    	    dp[i][i - 1].push_back(NULL);	
    	}
    	for(int l = 2; l <= n; ++l) {                                               // length
    		for(int i = 1; i <= n - l + 1; ++i) {                                   // start
    			for(int j = i; j <= i + l - 1; ++j) {                               // end
    				for(int k = 0; k < dp[j + 1][i + l - 1].size(); ++k) {          // left subtree
    				    for(int m = 0; m < dp[i][j - 1].size(); ++m) {              // right subtree
    				        TreeNode *T = new TreeNode(j);
    				        T->left = dp[i][j - 1][m];
    				        T->right = dp[j + 1][i + l - 1][k];
    			            dp[i][i + l - 1].push_back(T);    
    				    }
    				}
    			}
    		}
    	}
    	return dp[1][n];
    }
};
__________________________________________________________________________________________________
