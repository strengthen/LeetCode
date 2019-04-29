__________________________________________________________________________________________________
sample 8 ms submission
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
    struct Location{
        int X;
        int Y;
        int val;
        Location(int x, int y, int v): X(x), Y(y), val(v){}
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        vector<Location> l;
        dfs(root, 0, 0, l);
        auto compare = [](Location &a, Location &b)->bool{
            return (a.X<b.X || (a.X == b.X && a.Y<b.Y) || (a.X == b.X && a.Y==b.Y && a.val<b.val));
        };
        sort(l.begin(), l.end(), compare);
        int prev=INT_MIN;
        for(auto v: l){
            if (prev != v.X){
                result.push_back({v.val});
                prev=v.X;
            }else {
                result.back().push_back(v.val);
            }
        }
        return result;
    }
    
    
    void dfs(TreeNode *root, int X, int Y, vector<Location> &l ){
        if (root){
            l.push_back(Location(X, Y, root->val));
            dfs(root->left, X-1,Y+1,l);
            dfs(root->right, X+1,Y+1,l);
        }
    }
};
__________________________________________________________________________________________________
sample 13400 kb submission
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;  
        vector<unordered_set<int>> hs;
        if(!root) return res;
        map<int,vector<pair<int,int>>> m;
        int l=0, h=0;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.emplace(root,make_pair(l,h));
        while(!q.empty()){
            root = q.front().first;
            l = q.front().second.first;
            h = q.front().second.second;            
            q.pop();
            //int pr = m[l].empty() ? -1:m[l].back().second;
            m[l].emplace_back(h,root->val);
            // if(h==pr){
            //     int n = m[l].size();
            //     cout<<m[l][n-1].first<<" "<<m[l][n-2].first<<endl;           
            //     if(m[l][n-1].first<m[l][n-2].first) swap(m[l][n-1],m[l][n-2]);
            // }
            if(root->left) q.emplace(root->left,make_pair(l-1,h+1));
            if(root->right) q.emplace(root->right,make_pair(l+1,h+1)); 
        }
        for(auto v:m) {
            res.push_back({});
            sort(v.second.begin(),v.second.end());
            for(auto p:v.second) res.back().push_back(p.second);                
        }
        return res;
    }
};
__________________________________________________________________________________________________
