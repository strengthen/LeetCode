__________________________________________________________________________________________________
40ms
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                TreeLinkNode* t = q.front();
                q.pop();
                if (i < len - 1) {
                    t->next = q.front();
                }
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
        }
    }
};
__________________________________________________________________________________________________
23556 kb
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {                       //O(1)
        TreeLinkNode* pt = root;
        while (pt) {// while this level is not empty (already connected), we connect the next level
            TreeLinkNode* nextLevel = new TreeLinkNode(0), *nextPt = nextLevel;
            while (pt) {
                if (pt->left) {
                    nextPt->next = pt->left;
                    nextPt = nextPt->next;
                }
                if (pt->right) {
                    nextPt->next = pt->right;
                    nextPt = nextPt->next;
                }
                pt = pt->next;
            }
            pt = nextLevel->next;                      
        }       
    }
};
__________________________________________________________________________________________________
