__________________________________________________________________________________________________
sample 140 ms submission
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

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> postorder;
        recursivedfs(root, postorder);
        return postorder;
    }
    
    void recursivedfs(Node* root, vector<int>& postorder) {
        if (!root) return;
        for (int i = 0; i < (root -> children).size(); i++) {
            recursivedfs((root -> children)[i], postorder);
        }
        postorder.push_back(root -> val);
    }
};
__________________________________________________________________________________________________
sample 32544 kb submission
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
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
    void postorder(Node* node, vector<int>& res) {
        if (!node) return ;
        for (auto n: node->children) {
            postorder(n, res);
        }
        res.push_back(node->val);
    }
};
__________________________________________________________________________________________________
