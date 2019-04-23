__________________________________________________________________________________________________
12ms
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(),postorder.end());
        reverse(inorder.begin(),inorder.end());
        int i = 0, j = 0;
        if (postorder.size() == 0)
            return NULL;
        TreeNode * root = new TreeNode(postorder[0]);
        vector<TreeNode*> kk;
        TreeNode *cur = root;
        TreeNode *tem;
        kk.push_back(root);
        int status = 0;
        while (i != postorder.size())
        {
            if (status == 0)
            {
                if (postorder[i] != inorder[j])
                {
                    tem = new TreeNode(postorder[i]);
                    cur->right = tem;
                    cur = tem;
                    kk.push_back(cur);
                    i++;
                }
                else
                {
                    tem = new TreeNode(postorder[i]);
                    cur->right = tem;
                    cur = tem;
                    j++;
                    i++;
                    status = 1;
                }
            }
            else if (status == 1)
            {
                if (!kk.empty()&&kk.back()->val == inorder[j])
                {
                    cur = kk.back();
                    j++;
                    kk.pop_back();
                }
                else
                {
                    if(postorder[i]!=inorder[j])
                    {
                        tem = new TreeNode(postorder[i]);
                        cur->left = tem;
                        cur = tem;
                        kk.push_back(cur);
                        status = 0;
                        i++;
                    }
                    else
                    {
                        tem = new TreeNode(postorder[i]);
                        cur->left = tem;
                        cur = tem;
                        i++;
                        j++;
                    }                    
                }
            }
        }
        return root->right;
    }
};
__________________________________________________________________________________________________
14136 kb
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) {
            return nullptr;
        } else if (inorder.size() == 1) {
            return new TreeNode(inorder[0]);
        }
        
        vector<StackElem> stk;
        StackElem root(0, 0, inorder.size());
        stk.push_back(root);
        while (!stk.empty()) {
            StackElem elem = stk.back();    stk.pop_back();
            elem.node->val = postorder[elem.start2 + elem.length - 1];
            int len = 0;
            for (; inorder[elem.start1 + len] != elem.node->val; ++len) {}
            if (len > 0) {
                stk.push_back(StackElem(elem.start1, elem.start2, len));
                elem.node->left = stk.back().node;
            }
            if (elem.length - len - 1 > 0) {
                stk.push_back(StackElem(elem.start1 + len + 1, elem.start2 + len, elem.length - len - 1));
                elem.node->right = stk.back().node;
            }
        }
        return root.node;
    }
private:
    struct StackElem {
        int start1, start2, length;
        TreeNode* node; // To avoid memory leakage, 
                        // TreeNode* should be replaced with shared_ptr. 
        StackElem(int s1, int s2, int l, int v=0): start1(s1), start2(s2), length(l), node(new TreeNode(v)) {}
    };
};
__________________________________________________________________________________________________
