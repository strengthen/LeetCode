__________________________________________________________________________________________________
sample 16 ms submission
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
    string tree2str(TreeNode* t) {
        ostringstream s;
        rec(t, s);
        return s.str();
    }
    void rec(TreeNode *t, ostringstream &s) {
        if (!t) return;
        s << t->val;
        if (!t->left && !t->right) return;
        s << '(';
        rec(t->left, s);
        s << ')';
        if (t->right) {
            s << '(';
            rec(t->right, s);
            s << ')';
        }
    }
};

static int _ = []{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
__________________________________________________________________________________________________
sample 20868 kb submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const static int _FAST_IO = [](){ios::sync_with_stdio(0); std::cin.tie(0); return 0;}();

class Solution {
public:
    std::string tree2str(const TreeNode *t) const {
        std::ostringstream stream;
        dfs(stream, t);
        return stream.str();
    }

    void dfs(ostringstream &stream, const TreeNode *t) const {
        if (!t) return;

        stream << t->val;

        if (t->left || t->right) {
            stream << "("; dfs(stream, t->left); stream << ")";
        }

        if (t->right) {
            stream << "("; dfs(stream, t->right); stream << ")";
        }
    }
};
__________________________________________________________________________________________________
