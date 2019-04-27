__________________________________________________________________________________________________
sample 376 ms submission
class WordFilter {
public:
    struct TreeNode {
        TreeNode *nxt[26];
        vector<int> idx;
    };
    
    TreeNode *preRoot, *sufRoot;
    int n;
    
    WordFilter(vector<string> words) {
        preRoot = new TreeNode();
        sufRoot = new TreeNode();
        
        n = words.size();

        for (int i = 0; i < n; ++i) {
            string cur = words[i];
            int m = cur.length();
            TreeNode *p = preRoot;
            for (int j = 0; j < m; ++j) {
                if (!p->nxt[cur[j]-'a'])
                    p->nxt[cur[j]-'a'] = new TreeNode();
                
                p = p->nxt[cur[j]-'a'];
                p->idx.push_back(i);
            }
            
            p = sufRoot;
            for (int j = m-1; j >= 0; --j) {
                if (!p->nxt[cur[j]-'a'])
                    p->nxt[cur[j]-'a'] = new TreeNode();
                
                p = p->nxt[cur[j]-'a'];
                p->idx.push_back(i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        if (prefix == "" && suffix == "")
            return n-1;
        
        TreeNode *p = preRoot;
        for (int i = 0; i < prefix.length(); ++i) {
            if (!p->nxt[prefix[i]-'a'])
                return -1;
            p = p->nxt[prefix[i]-'a'];
        }
        
        if (suffix.length() == 0) {
            if (p->idx.empty())
                return -1;
            else
                return p->idx.back();
        }
        
        TreeNode *q = sufRoot;
        for (int i = suffix.length()-1; i >= 0; --i) {
            if (!q->nxt[suffix[i]-'a'])
                return -1;
            q = q->nxt[suffix[i]-'a'];
        }
        
        if (prefix.length() == 0) {
            if (q->idx.empty())
                return -1;
            else
                return q->idx.back();
        }
        
        int i = p->idx.size()-1, j = q->idx.size()-1;
        while (i >= 0 && j >= 0) {
            if (p->idx[i] == q->idx[j])
                return p->idx[i];
            else if (p->idx[i] < q->idx[j])
                --j;
            else
                --i;
        }
        
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
__________________________________________________________________________________________________
sample 84108 kb submission
class WordFilter {
public:
    WordFilter(vector<string> words) {
        for(int i = 0; i < words.size(); ++i)
            word2Weight[words[i]] = i;
    }
    
    int f(string prefix, string suffix) {
        auto it = word2Weight.lower_bound(prefix);
        int res = -1;
        while(it != word2Weight.end())
        {
            if(it->first.find(prefix) == 0 
               && it->first.rfind(suffix) == it->first.size() - suffix.size())
                res = max(res, it->second);
            ++it;
        }
        return res;
    }
    map<string, int> word2Weight;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
__________________________________________________________________________________________________
