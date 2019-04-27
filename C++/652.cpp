__________________________________________________________________________________________________
sample 28 ms submission
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
      vector<TreeNode*> ans;
      unordered_map<long,pair<int,int>>m;
      helper(root, m, ans);
      return ans;
    }
  
    int helper(TreeNode* node, unordered_map<long,pair<int,int>>& m, vector<TreeNode*>& ans){
      if(!node) return 0;
      int l=helper(node->left, m, ans);
      int r=helper(node->right, m, ans);
      // weird logic. but it works. l and r are the length of the map.size() (used a key)
        
      long key = static_cast<unsigned long>(node->val)<<32 | l<<16 | r;
      //cout<<l<<" "<<r<<" "<<key<<endl;
      auto it = m.find(key);
      if(it==m.end()){
        int id=m.size()+1;
        it = m.insert({key,{id,0}}).first;
      }
      
      if(++it->second.second==2) ans.push_back(node);
      // Pass the map.size() to be used as depth.
      return it->second.first;    
    }
};
__________________________________________________________________________________________________
sample 23036 kb submission
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
private:
    void findAllNode (TreeNode *root, vector<TreeNode*> &nodes) {
        if (root != nullptr) {
            nodes.push_back (root);
            findAllNode (root->left, nodes);
            findAllNode (root->right, nodes);
        }
    }
    bool decideDuplicateTree (TreeNode *tr1, TreeNode *tr2) {
        if (tr1 == nullptr && tr2 == nullptr) {
            return true;
        }
        else if (tr1 != nullptr && tr2 != nullptr) {
            if (tr1->val == tr2->val) {
                bool dleft = decideDuplicateTree (tr1->left, tr2->left);
                bool dright= decideDuplicateTree (tr1->right,tr2->right);
                return (dleft==true)&&(dright==true);
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> nodes;
        findAllNode (root, nodes);
        vector<TreeNode*> ret;
        bool *checked = new bool[nodes.size()];
        for (auto ii=0;ii<nodes.size();ii++) {
            checked[ii] = false;
        }
        for (auto ii=0;ii<nodes.size();ii++) {
            if (checked[ii] == false) {
                // checked[ii] = true;
                for (auto jj=ii+1;jj<nodes.size();jj++) {
                    bool decided = decideDuplicateTree (nodes[ii], nodes[jj]);
                    if (decided) {
                        checked[jj] = true;
                        if (checked[ii] == false) {
                            ret.push_back(nodes[ii]);
                            checked[ii] = true;
                        }
                    }
                }
            }
        }
        delete [] checked;
        return ret;
    }
};
__________________________________________________________________________________________________
