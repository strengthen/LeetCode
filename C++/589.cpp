__________________________________________________________________________________________________
sample 124 ms submission
#pragma GCC optimize("Ofast")

__attribute__((constructor)) void _() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);
}

class Solution {
public:
  static vector<int> preorder(Node* root) {
    vector<int> res;
    if (root) preorder(root, res);
    return res;
  }
    
  static void preorder(Node* n, vector<int>& v) {
    v.push_back(n->val);
    for (const auto& n : n->children) {
      preorder(n, v);
    }
  }
};
__________________________________________________________________________________________________
sample 32512 kb submission
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void preorderec(Node* root,vector<int>* ans){
        if(root !=  NULL){
            cout<<root->val;
            ans->push_back(root->val);
            for(int i = 0; i<root->children.size(); i++){
                preorderec(root->children[i], ans);
            }
        }
    }
        
    vector<int> preorder(Node* root) {
        vector<int> ans;
        preorderec(root,&ans);
        return ans;
    }
};
__________________________________________________________________________________________________
