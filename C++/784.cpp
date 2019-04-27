__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    //迭代解法
    vector<string> letterCasePermutation(string S) {
        int prior_size;
        vector<string> result;
        result.push_back(S);
        for(int i = 0; i < S.size(); i++)
        {
            char changed=0;
            if (S[i] >= 'a' && S[i] <= 'z')
            {
                changed=S[i] + ('A'-'a');
            }else if (S[i] >= 'A' && S[i] <= 'Z'){
                changed=S[i] - ('A'-'a');
            }
            if(!changed)
                continue;
            prior_size = result.size();
            for(int j = 0; j < prior_size; j++)
            {
                result.emplace_back(result[j]);
                result[j][i] = changed;
            }
        }
        return result;
    }
};
__________________________________________________________________________________________________
sample 11252 kb submission
class Solution {
public:
    inline bool isDigit(char x) {
        return x >= '0' && x <= '9';
    }
    
    string exchange(const string &s, int x) {
        int l = s.length() - 1;
        int count = 1;
        string ans = s;
        
        for (int i = x; i > 0; i = i & (i - 1)) {
            int move = i & (-i);
            while (count < move || isDigit(s[l])) {
                if (!isDigit(s[l]))
                    count <<= 1;
                l--;
            }
            
            if (ans[l] >= 'A' && ans[l] <= 'Z')
                ans[l] += 'a' - 'A';
            else
                ans[l] += 'A' - 'a';
        }
        
        return ans;
    }
    
    vector<string> letterCasePermutation(string S) {
        int l = S.length(), characters = 0;
        for (int i = 0; i < l; i++)
            if (!isDigit(S[i]))
                characters++;
        
        int enumerate = 1 << characters;
        vector<string> ans(enumerate);
        for (int e = 0; e < enumerate; e++)
            ans[e] = exchange(S, e);
        
        return ans;
    }
};
__________________________________________________________________________________________________
