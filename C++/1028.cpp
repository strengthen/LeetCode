__________________________________________________________________________________________________
16ms
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution 
{
    
    int parsenumber(string& s, int& pos)
    {
        int num = 0;
        while(isdigit(s[pos]))
        {
            num = num * 10 + (s[pos] - '0');
            ++pos;
        }
        return num;
    }
    
    int parsedepth(string& s, int& pos)
    {
        int d = 0;
        while(!isdigit(s[pos]))
        {
            ++d;
            ++pos;
        }
        return d;
    }
    
public:
    TreeNode* recoverFromPreorder(string S) 
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(S.size() == 0 || !isdigit(S[0]))
        {
            return nullptr;
        }
        
        int pos = 0;
        TreeNode* root = new TreeNode(parsenumber(S, pos));
        stack<TreeNode*> fathers;
        fathers.push(root);
        
        while(pos != S.size())
        {
            int d = parsedepth(S, pos);
            int num = parsenumber(S,pos);
            
            TreeNode* newnode = new TreeNode(num);
            
            if(d == fathers.size())
            {
                fathers.top()->left = newnode;
            }
            else
            {
                while(d != fathers.size())
                {
                    fathers.pop();
                }
                fathers.top()->right = newnode;
            }
            
            fathers.push(newnode);
        }
        
        return root;
    }
};
__________________________________________________________________________________________________
20ms
class Solution {
 public:
  TreeNode* recoverFromPreorder(string s) {
    vector<TreeNode*> path;
    int i = 0;
    while (i < (int)s.length()) {
      int depth = 0;
      while (s[i] == '-') {
        depth++;
        i++;
      }
      int value = 0;
      while (i < (int)s.length() && isdigit(s[i])) {
        value = value * 10 + s[i] - '0';
        i++;
      }
      while (depth < (int)path.size()) {
        path.pop_back();
      }
      TreeNode* parent = (path.empty() ? nullptr : path.back());
      TreeNode* cur = new TreeNode(value);
      if (parent != nullptr) {
        if (parent->left == nullptr) {
          parent->left = cur;
        } else {
          assert(parent->right == nullptr);
          parent->right = cur;
        }
      }
      path.push_back(cur);
    }

    assert(!path.empty());
    return path[0];
  }
};
__________________________________________________________________________________________________
24ms
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
    TreeNode* recoverFromPreorder(string S) 
    {
        unordered_map<int, TreeNode*> map;
        string rootNode = "";
        int start = 0;
        int n = int(S.size());
        while(start < n && S[start] != '-')
            rootNode += S[start++];
        TreeNode * root = new TreeNode(stoi(rootNode));
        map[0] = root;
        
        while(start < n)
        {
            int depth = 0;
            for(; start < n && S[start] == '-'; start++, depth++);
            string node = "";
            for(; start < n && S[start] != '-'; node += S[start++]);
            if(!map[depth - 1] -> left)
            {
                map[depth - 1] -> left = new TreeNode(stoi(node));
                map[depth] = map[depth - 1] -> left;
            }
            else 
            {
                map[depth - 1] -> right = new TreeNode(stoi(node));
                map[depth] = map[depth - 1] -> right;
            }
        }
        return root;
    }
};
__________________________________________________________________________________________________
28ms
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
    
    vector< pair<int, int> > tree;
    int i = 0;
    
    TreeNode* dfs(int lvl = 0) {
        TreeNode* v = new TreeNode(tree[i].second);
        if (i+1 < tree.size()) {
            if (tree[i+1].first > lvl) {
                i++;
                v->left = dfs(lvl+1);
            } 
        }
        if (i+1 < tree.size()) {
            if (tree[i+1].first > lvl) {
                i++;
                v->right = dfs(lvl+1);
            }
        }
        return v;
    }
    
    TreeNode* recoverFromPreorder(string s) {
        for (int i = 0; i < s.length();) {
            int lvl = 0;
            int val = 0;
            
            while (s[i] == '-') lvl++, i++;
            while (i < s.length() && isdigit(s[i])) val = val*10 + s[i]-'0', i++;
            
            tree.push_back( make_pair(lvl, val) );
        }
        i = 0;
        return dfs();
    }
};
__________________________________________________________________________________________________
32ms
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
    TreeNode* recoverFromPreorder(string S) {
        
        auto s = S.begin();
        auto end = S.end();
        int prevdashes = 0;
        vector<TreeNode*> stack;
        
        while (s != end) {
            int dashes = 0;
            while (*s == '-') {
                s++;
                dashes++;
            }
            
            auto n1 = s;
            while (*s >= '0' && *s <= '9') {
                s++;
            }
            
            auto number = stoi(string(n1, s));
            auto* node = new TreeNode(number);
            
            if (stack.empty()) {
                stack.push_back(node);
                continue;
            }
            
            if (dashes > prevdashes) {
                stack.back()->left = node;
            }
            else if (dashes == prevdashes) {
                stack.pop_back();
                stack.back()->right = node;
            }
            else if (dashes < prevdashes) {
                auto d = prevdashes - dashes;
                while (d--) {
                    stack.pop_back();
                }
                stack.pop_back();
                stack.back()->right = node;
            }
            
            stack.push_back(node);
            prevdashes = dashes;
        }
        
        return stack.front();
    }
};
__________________________________________________________________________________________________