__________________________________________________________________________________________________
sample 4 ms submission
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
    vector<string> v;
    void findTreePaths(TreeNode *root, string path) {
        path+=to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            v.push_back(path);
            return;
        } 
        if (root->left) findTreePaths(root->left, path + "->");
        if (root->right) findTreePaths(root->right, path + "->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return v;
        findTreePaths(root, "");
        return v;
    }
};
__________________________________________________________________________________________________
sample 11060 kb submission
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
    vector<int> visited;
    vector<string> res;
    void addpath(vector<pair<TreeNode*,char> > &path)
    {
        string ans = "";
        for(int i=0 ; i<path.size()-1 ; i++)
        {
            ans += to_string(path[i].first->val);
            ans +="->";
            
        }
        ans += to_string(path.back().first->val);
        res.push_back(ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return res;
        vector<pair<TreeNode*,char> > st;
        st.push_back(make_pair(root,0));
        while(!st.empty())
        {
            
            root = st.back().first;
            char is_expand = st.back().second;
            //cout << root->val << " " << int(is)
            if(is_expand == 2)
            {
                st.pop_back();
                if(!st.empty())
                {
                    if(root == st.back().first->right)
                        st.back().second = 2;
                    else
                        st.back().second = 1;
                }
                continue;
            }
            else if(is_expand == 1)
            {
                if(root->right == NULL)
                    st.back().second = 2;
                else
                    st.push_back(make_pair(root->right, 0));
            }
            else
            {
                if(root->right == NULL && root->left == NULL)
                {
                     addpath(st);
                     st.back().second = 2 ;
                }
                else if (root->left == NULL)
                    st.back().second = 1 ;
                else
                    st.push_back(make_pair(root->left,0));
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
