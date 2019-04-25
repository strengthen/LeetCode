__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstring(s, 0, s.size() - 1, k);
    }
    int longestSubstring(const string &s, int left, int right, int k){
        if(left > right || s.empty()) return 0;
        int count[26] = {0};
        for(int i = left; i <= right; i++) count[s[i] - 'a']++;
        
        bool pass = true;
        for(int i = left; i <= right; i++){
            if(count[s[i] - 'a'] < k){
                pass = false;
                break;
            }
        }
        
        if(pass) return right - left + 1;
        
        int res = 0, prev = left, cur = left;
        
        while(cur <= right){
            // find the first element appears more than k times.
            while(cur <= right && count[s[cur] - 'a'] < k) cur++;
            prev = cur;
            // find the last element appears more than k times.
            while(cur <= right && count[s[cur] - 'a'] >= k) cur++;
            // the longest substring T must not contain elements whose counts are less than k.
            // But note: the elements of substrings defined between such elements don't necessarily have a count more than k.
            res = max(res, longestSubstring(s, prev, cur - 1, k));
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 8564 kb submission
class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0, i = 0, n = s.size();
        while (i + k <= n) {
            int m[26] = {0}, mask = 0, max_idx = i;
            for (int j = i; j < n; ++j) {
                int t = s[j] - 'a';
                ++m[t];
                if (m[t] < k) mask |= (1 << t);
                else mask &= (~(1 << t));
                if (mask == 0) {
                    res = max(res, j - i + 1);
                    max_idx = j;
                }
            }
            i = max_idx + 1;
        }
        return res;
    }
};
__________________________________________________________________________________________________
