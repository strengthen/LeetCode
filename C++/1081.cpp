__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    string smallestSubsequence(string text) {
        int cnt[26] = {0}, used[26] = {0};
        string ans = "";
        for (auto ch : text)
            cnt[ch - 'a'] ++;
        for (auto ch : text){
            cnt[ch - 'a'] --;
            if (used[ch - 'a'] > 0) continue;
            used[ch - 'a'] ++;
            while (!ans.empty() && ans.back() > ch && cnt[ans.back() - 'a'] > 0){
                used[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back (ch);
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string smallestSubsequence(string text) {
        vector<int> count(26, 0);
        // for now and each letter, how many left
        for(auto c: text) count[c-'a']++;
        vector<bool> used(26, false);
        string ans = "";
        for(auto c: text){
            count[c-'a']--;
            if(used[c-'a']) continue;
            while(ans.size() && count[ans.back()-'a'] && c < ans.back()){
                used[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans.push_back(c);
            used[c-'a'] = true;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    string smallestSubsequence(string text) {
        vector<int> order(26,0);
        int i = 0;
        for(auto c:text)
            order[c-'a']++;
        set<char> visited;
        vector<char> rst;
        int st = 0;
        for(auto c:text)
        {
            if(visited.count(c)==0)
            {
                for(int i = rst.size()-1; i>=st; i--)
                {
                    if(rst[i]!='#'&&rst[i]>c)
                    {
                        if(order[rst[i]-'a']>0)
                        {   
                            visited.erase(rst[i]);
                            rst[i]='#';
                        }
                        else
                            st = i;
                    }
                }
                visited.insert(c);
                rst.push_back(c);
                
            }
            order[c-'a']--;
        }
        string r;
        for(char c:rst) if(c!='#')r+=c;
        return r;
    }
};