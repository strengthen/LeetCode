__________________________________________________________________________________________________
8ms
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
        vector<vector<int> > levelOrder(TreeNode* pRoot) {
            vector<pair<int,int>> vec;
            vector<vector<int>> ans;
            if(pRoot==nullptr)
                return ans;
            queue<pair<TreeNode*,int>> q;
            q.push(make_pair(pRoot,1));
            while(!q.empty()){
                pair<TreeNode*,int> now=q.front();
                q.pop();
                vec.push_back(make_pair(now.first->val,now.second));
                if(now.first->left)
                    q.push(make_pair(now.first->left,now.second+1));
                if(now.first->right)
                    q.push(make_pair(now.first->right,now.second+1));
            }
            vector<int> v;
            for(int i=0;i<vec.size();i++){
                if(i!=0&&vec[i].second!=vec[i-1].second){
                    ans.push_back(v);
                    v.clear();
                }
                v.push_back(vec[i].first);
            }
            ans.push_back(v);
            return ans;
        }
};
__________________________________________________________________________________________________
13532 kb
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result{1, vector<int>{}};
        queue<TreeNode*> nodes{};
        nodes.push(root);
        nodes.push(nullptr);
        int resultIndex = 0;
        while(!nodes.empty()) {
            auto next = nodes.front();
            nodes.pop();
            if (!next) {
                if (nodes.empty()) break;
                nodes.push(nullptr);
                ++resultIndex;
                result.push_back(vector<int>{});
            } else {
                result[resultIndex].push_back(next->val);
                if (next->left) nodes.push(next->left);
                if (next->right) nodes.push(next->right);
            }
        }
        return result;
    }
};
__________________________________________________________________________________________________
