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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if (!root) return new TreeNode(v);
        if (1 == d) {
            auto t = new TreeNode(v);
            t->left = root;
            return t;
        }
        
        auto add = [](vector<TreeNode*> l, int v) {
            for (auto &c: l) {
                auto old = c->left;
                c->left = new TreeNode(v);
                c->left->left = old;
                
                old = c->right;
                c->right = new TreeNode(v);
                c->right->right = old;
            }
        };
        
        vector<TreeNode*> level{root};
        vector<TreeNode*> last_level;
        vector<TreeNode*> temp;
        int cnt = 1;
        while (!level.empty()) {
            temp.clear();
            cnt++;
            
            for (auto &c: level) {
                if (c->left) temp.push_back(c->left);
                if (c->right) temp.push_back(c->right);
            }
            
            if (d == cnt) add(level, v);
            if (temp.size()) last_level = temp;
            level.swap(temp);
        }
        
        return root;
    }
};
__________________________________________________________________________________________________
× Close
sample 20580 kb submission
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(root == nullptr) return root;
        if(d == 1) {
            TreeNode* ans = new TreeNode(v);
            ans->left = root;
            return ans;
        }
        
        vector<TreeNode*> curr{root},next;
        while(!curr.empty()) {
            if (--d == 0) return root;
            for(TreeNode* Node:curr) {
                if(d == 1) {
                    TreeNode *left = Node->left;
                    TreeNode *right = Node->right;
                    Node->left = new TreeNode(v);
                    Node->right = new TreeNode(v);
                    Node->left->left = left;
                    Node->right->right = right;
                }
                else {
                    if(Node->left) next.push_back(Node->left);
                    if(Node->right) next.push_back(Node->right);  
                }
           
            }
            curr.swap(next);
            next.clear();
        }
        return root;
        
    }
};
__________________________________________________________________________________________________
