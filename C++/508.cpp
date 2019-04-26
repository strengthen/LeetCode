__________________________________________________________________________________________________
sample 16 ms submission
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
	if (root == nullptr) return {};

	vector<int> sums;
	findFrequentTreeSum(root, sums);
	std::sort(sums.begin(), sums.end());
	int max_value = 1;
	int current = 1;
	int prev = sums[0];
	int len = sums.size();
	for (int i = 1; i < len; ++i) {
	  if (prev == sums[i]) {
		++current;
	  } else {
		prev = sums[i];
		max_value = max(max_value, current);
		current = 1;
	  }
	}
	max_value = max(max_value, current);

	prev = sums[0];
	current = 1;
	vector<int> res;
	for (int i = 1; i < len; ++i) {
	  if (prev == sums[i]) {
		++current;
	  } else {
		if (current == max_value) res.push_back(prev);
		prev = sums[i];
		current = 1;
	  }
	}
	if (current == max_value) res.push_back(prev);

	return res;
  }

  int findFrequentTreeSum(TreeNode* root, vector<int>& sums) {
	if (root == nullptr) return 0;
	
	int result = root->val;
	result += findFrequentTreeSum(root->left, sums);
	result += findFrequentTreeSum(root->right, sums);
	sums.push_back(result);

	return result;
  }
};
__________________________________________________________________________________________________
sample 22472 kb submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef pair<int, int> pairint;
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> r;
        if (root == NULL) return r;
        
        int i = 0;
        deque<TreeNode*> d;
        d.push_back(root);
        while(i < d.size()) {            
            TreeNode* p = d[i++];
            if (p->left) d.push_back(p->left);
            if (p->right) d.push_back(p->right);
        }

        unordered_map<int, int> m;    
        for(i = d.size()-1; i >= 0; i--) {
            TreeNode* p = d[i];
            if (p->left) p->val += p->left->val;
            if (p->right) p->val += p->right->val;
            ++m[p->val]; 
        }
        
        int max = 0; i = 0;
        for(auto p: m) {            
            if (p.second >= max) { 
                if (p.second != max) { max = p.second; i = r.size(); }
                r.emplace_back(p.first); 
            }
        }
        
        if (i) r.erase(r.begin(), r.begin()+i);
        return r;
    }        
};
__________________________________________________________________________________________________
