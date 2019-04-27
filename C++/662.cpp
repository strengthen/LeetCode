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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q; if(root) q.push({root, 1});
        int ret = 1;
        while(!q.empty()) {
            int size = q.size();
            int firstCode = -1; int lastCode = -1;
            for(int round = 0; round < size; round++) {
                auto tmp = q.front(); q.pop();
                TreeNode* curr = tmp.first; 
                //if the size if 1, then we can set the code back to 1
                int code = (size == 1 ? 1 : tmp.second);
                if(firstCode == -1) firstCode = code;
                lastCode = code;
                if(curr->left)q.push({curr->left, code*2+1});
                if(curr->right)q.push({curr->right, code*2+2});
            }
            int len = lastCode-firstCode+1;
            ret = max(ret, len);
        }
        return ret;
    }
};
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
    int widthOfBinaryTree(TreeNode* root) {
        long re=0;
        queue<pair<TreeNode*,long>> q;
        q.push(pair<TreeNode*,long>(root,0));
        while(!q.empty()){
            int size=q.size();
            long l=q.front().second;
            long r=0;
            while(size){
                pair<TreeNode*,long> cur = q.front();
                q.pop();
                if(cur.first->left){
                    q.push(pair<TreeNode*,long>(cur.first->left,(cur.second-l)*2));
                }
                if(cur.first->right){
                    q.push(pair<TreeNode*,long>(cur.first->right,(cur.second-l)*2+1));
                }
                r=max(r,cur.second);
                --size;
            }
            re=max(re,r-l+1);
        }
        return re;
    }
};
__________________________________________________________________________________________________
sample 15784 kb submission
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
int widthOfBinaryTree(TreeNode* root) {
  int ret=0;
  if (root==nullptr)
    return ret;
  queue<pair<TreeNode*, int>> Q;
  Q.push({root,0});
  ret=1;
  while (!Q.empty()) {
    int len=Q.size(), minNum=INT_MAX, maxNum=INT_MIN, first=-1;
    for (int i=0; i<len; i++) {
      auto p=Q.front();
      Q.pop();
      TreeNode* node=p.first;
      if (node->left!=nullptr) {
        int num;
        if (first==-1)
          num=0, first=p.second;
        else
          num=(p.second-first)*2;
        Q.push({node->left, num});
        minNum=min(minNum, num);
        maxNum=max(maxNum, num);
      }
      if (node->right!=nullptr) {
        int num;
        if (first==-1)
          num=1, first=p.second;
        else
          num=(p.second-first)*2+1;
        Q.push({node->right, num});
        minNum=min(minNum, num);
        maxNum=max(maxNum, num);
      }
      //cout << p.second << " " << minNum << " " << maxNum << endl;
    }
    if (!Q.empty())
      ret=max(ret, maxNum-minNum+1);
  }
  return ret;
}
};