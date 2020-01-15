__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26> > valid = {bitset<26>()};
        int max_length = 0;
        
        for (string &s : arr) {
            bitset<26> cur;
            for (char c : s) {
                cur.set(c - 'a');
            }
            
            if (cur.count() < s.length()) continue;
            
            for (int i = 0; i < valid.size(); i++) {
                bitset<26> prev = valid[i];
                if ((prev & cur).any()) continue;
                
                bitset<26> next = prev | cur;
                valid.push_back(next);
                max_length = max((int)next.count(), max_length);
            }
        }
        
        return max_length;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
        for (auto& s : arr) {
            bitset<26> tmp;
            for (auto& c : s) tmp.set(c - 'a');
            // if duplicate chars, skip
            if (tmp.count() < s.size()) continue;
            
            for (int i = dp.size() - 1; i >= 0; --i) {
                if ((dp[i] & tmp).any()) continue;
                dp.push_back(dp[i] | tmp);
                res = max(res, (int)dp.back().count());
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
