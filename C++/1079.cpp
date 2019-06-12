__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char,int> cnts;
        int ans = 0;
        for(auto c : tiles) cnts[c]++;
        function<void()> dfs = [&]()
        {
            ans++;
            for(auto& c : cnts)
            {
                if(c.second)
                {
                    c.second--;
                    dfs();
                    c.second++;
                }
            }
        };
        dfs();
        return ans-1;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
private:
    const int fact[8] = {1, 1, 2, 6, 24, 120, 720, 5040};
    
    map<vector<int>, int> res;
    
    void calc(const vector<int>& cnt) {
        if (res.find(cnt) != res.end()) {
            return;
        }
        
        int tot = 0, den = 1;
        for (int v:cnt) {
            tot += v;
            den *= fact[v];
        }
        
        if (tot == 0) return;
        
        res[cnt] = fact[tot] / den;
        
        for (int i = 0; i < cnt.size(); ++i) {
            if (cnt[i] > 0) {
                auto vec = cnt;
                vec[i]--;
                calc(vec);
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> cnt(26, 0);
        for (char c:tiles) {
            cnt[c - 'A']++;
        }
        
        calc(cnt);
        
        int ans = 0;
        for (const auto& p:res) {
            ans += p.second;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int res = 0;
    int numTilePossibilities(string tiles) {
        unordered_map<char,int> mymap;
        
        for(auto ch : tiles)
            mymap[ch]++;
        
        dfs(tiles, 0, mymap);
        return res-1;
    }
    
    void dfs(string tiles, int len, unordered_map<char,int> &mymap){
        if(len > tiles.size())
            return;
        
        res++;
        
        for(auto &map : mymap){
            if(map.second>0){
                map.second--;
                dfs(tiles, len+1, mymap);
                map.second++;
            }
        }        
    }
};