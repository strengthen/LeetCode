__________________________________________________________________________________________________
sample 144 ms submission
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
static int optimize = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<vector<int>> result;
    void recursion(Node *root, int level) {
        if (root == NULL) return;
        if (result.size() == level)
            result.push_back(vector<int>());
        result[level].push_back(root->val);
        for (auto child: root->children)
            recursion(child, level + 1);
    }
    vector<vector<int>> levelOrder(Node* root) {
        recursion(root, 0);
        return result;
    }
};
__________________________________________________________________________________________________
sample 33472 kb submission
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

static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        helper(root, 0, v);
        return v;
    }
    void helper(Node* root, int level, vector<vector<int>>& v){
        if(!root) return;
        if(v.size() == level) v.push_back(vector<int>());
        v[level].push_back(root->val);
        for(unsigned int i=0; i<root->children.size(); ++i)
            helper(root->children[i], level+1, v);
    }
};
__________________________________________________________________________________________________
