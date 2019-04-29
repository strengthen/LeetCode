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
    
    int res=0;
    int recur(TreeNode* node)
    {
        // return 0 if it is leave
        // return 1 if we decide to put camera on this node
        // return 2 if the node is covered
        // we start from bottom, once we placed the camera, we remove the 
        // covered nodes and figure out the new leaves (using 0)
        if(!node)
            return 2;
        int l = recur(node->left), r = recur(node->right);
        if(l==0||r==0)
        {
            //if any of child is leaf node
            res++;
            return 1;
        }
        else if(l==2 && r==2)
        {
            //if both childs are covered cut the tree here
            return 0;
        }
        
        return 2;
    }
    
    int minCameraCover(TreeNode* root) {
        
        return recur(root)==0?res+1:res;
    }
};
__________________________________________________________________________________________________
sample 19032 kb submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
class Solution {
private:
    struct result {
        int x1;
        int x2;
        int y;
        result(int x1=1, int x2=1, int y=0): x1(x1), x2(x2), y(y) {}
    };
    result helper(TreeNode* node) {
        if(!node->left && !node->right) {
            return result();
        }
        if(!node->left || !node->right) {
            result ret = node->left ? helper(node->left) : helper(node->right);
            return result(min(min(ret.x1, ret.x2), ret.y) + 1, ret.x1, ret.x2);
        }
        result left = helper(node->left);
        result right = helper(node->right);
        result ret;
        ret.x1 = min(min(left.x1, left.x2), left.y) + min(min(right.x1, right.x2), right.y) + 1;
        ret.x2 = min(left.x1 + min(right.x1, right.x2), right.x1 + min(left.x1, left.x2));
        ret.y = min(left.x1, left.x2) + min(right.x1, right.x2);
        return ret;
    }
public:
    int minCameraCover(TreeNode* root) {
        if(!root) return 0;
        result ret = helper(root);
        return min(ret.x1, ret.x2);
    }
};
__________________________________________________________________________________________________
