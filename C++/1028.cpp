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
    TreeNode* recoverFromPreorder(string S) {
        stack<pair<int, TreeNode*>> tree;
        TreeNode * root = NULL;
        
        int number = 0;
        int currlvl = 0;
        
        for(int i = 0; i <= S.size(); ++i){
            if(i < S.size() && S[i] != '-'){
                number = (number * 10) + (S[i] - '0');
            }
            else{
                if(S[i-1] != '-'){
                    //add node
                    TreeNode * n = new TreeNode(number);
                    if(root == NULL){
                        root = n;
                    }else{
                        while(tree.top().first != currlvl - 1){
                            tree.pop();
                        }

                        if(tree.top().second->left == NULL){
                            tree.top().second->left = n;
                        }
                        else{
                            tree.top().second->right = n;
                        }
                    }
                    
                    tree.push(make_pair(currlvl, n));
                    number = currlvl = 0;
                }
                
                ++currlvl;
            }
        }
        
        return root;
    }
};

static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
__________________________________________________________________________________________________
sample 20 ms submission
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
        std::stack<std::pair<TreeNode*, int>> st;
        int i = 0;
        TreeNode* head = nullptr;
        while (i < S.size()) {
            //std::cout << "i = " << i << std::endl;
            auto pr = getNext(S, i);
            //std::cout << pr.first << ", " << pr.second << std::endl;
            while (!st.empty() && st.top().second >= pr.second) {
                st.pop();
            }
            auto curr_p = std::make_pair(new TreeNode(pr.first), pr.second);
            if (head == nullptr) {
                head = curr_p.first;
            }
            if (!st.empty()) {
                if (st.top().first->left == nullptr) {
                    st.top().first->left = curr_p.first;
                } else {
                    st.top().first->right = curr_p.first;
                }
            }
            st.push(curr_p);
        }
        return head;
    }
    
    std::pair<int, int> getNext(string& S, int& i) {
        int level = 0;
        int num = 0;
        while (i < S.size() && S[i] == '-') {
            level++;
            i++;
        }
        int start = i;
        while (i < S.size() && std::isdigit(S[i])) {
            i++;
        }
        num = std::stoi(S.substr(start, i - start));
        return std::make_pair(num, level);
    }
};
__________________________________________________________________________________________________
