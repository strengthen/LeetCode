__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        int result = 0;
        
        vector<int> cnt(26,0);
        int max_freq = 0, len;
        
        while(right<s.size())
        {       
            len = right-left;
            if(len - max_freq <= k){ // move right
                result = max(result, len);
                cnt[s[right]-'A']++;
                max_freq = max(max_freq, cnt[s[right]-'A']);
                right++;
            }
            else { // move left
                cnt[s[left]-'A']--;
                left++;                
            }            
        }
        len = right-left;        
        if(len-max_freq <= k)
            result = max(result, len);
        return result;
    }
};
__________________________________________________________________________________________________
sample 9248 kb submission
class Solution {
public:
    int characterReplacement(const string& s, int k) {
        int count[26] = {0};
        int res = 0, maxCnt = 0;
        for (int i = 0, j = 0; j < s.length(); j++) {
            maxCnt = max(maxCnt, ++count[s[j] - 'A']);
            while (j - i + 1 - maxCnt > k)
                count[s[i++] - 'A']--;
            res = max(res, j - i + 1);
        }
        return res;
    }
};
__________________________________________________________________________________________________
