__________________________________________________________________________________________________
× Close
sample 16 ms submission
static int _ = [](){ ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

vector<int> countAlphaBets(const string & str) {
    vector<int> r(26, 0);
    for (char ch : str) {
        r[ch - 'a'] += 1;
    }
    return r;
}

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        if (target.empty())
            return 0;
        
        auto targetAlphas = countAlphaBets(target);
        
        vector<uint32_t> alphaMasks(26);
        uint32_t m = 1;
        for (int i = 0; i < targetAlphas.size(); ++i) {
            alphaMasks[i] = (m << targetAlphas[i]) - m;
            m <<= targetAlphas[i];
        }
        uint32_t targetMask = m - 1;
        
        vector<vector<pair<uint32_t, uint32_t>>> transformers(stickers.size());
        for (int si = 0; si < stickers.size(); ++si) {
            auto alphas = countAlphaBets(stickers[si]);
            
            while (true) {
                uint32_t shift = 0;
                uint32_t set = 0;
                for (int i = 0; i < alphas.size(); ++i) {
                    if (alphas[i] == 0 || alphaMasks[i] == 0)
                        continue;
                    alphas[i] -= 1;
                    shift |= alphaMasks[i] & (alphaMasks[i] >> 1);
                    set |= ((alphaMasks[i] ^ (alphaMasks[i] - 1)) + 1) >> 1;
                }
                if (set != 0) {
                    transformers[si].emplace_back(shift, set);
                } else {
                    break;
                }
            }
        }
        
        vector<int> steps(targetMask + 1, -1);
        steps[0] = 0;
        
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            
            for (int i = 0; i < transformers.size(); ++i) {
                int y = applyTrans(x, transformers[i]);
                if (steps[y] == -1) {
                    steps[y] = steps[x] + 1;
                    q.push(y);
                }
            }
            
            if (steps[targetMask] != -1)
                break;
        }

        return steps[targetMask];
    }
    
    int applyTrans(int x, vector<pair<uint32_t, uint32_t>> & trans) {
        for (auto & t : trans) {
            int y = x | ((x & t.first) << 1) | t.second;
            if (y == x)
                return x;
            x = y;
        }
        return x;
    }
};
__________________________________________________________________________________________________
sample 10148 kb submission
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size(), m = 1 << n; // if target has n chars, there will be m=2^n subset of characters in target
        vector<uint> dp(m, -1); // use index 0 - 2^n as bitmaps to represent each subset of all chars of target
        dp[0] = 0; // first thing we know is : dp[empty set] requires 0 stickers,
        for (int i = 0; i < m; i++) { // for every subset i, start from 00000...(emptyset) to 111111...(the target)
            if (dp[i] == -1) continue;
            for (string& s : stickers) { // try use each sticker as an char provider to populate a super-set of i,
                int sup = i;
                for (char c : s) { // to do that, for each char in the sticker, 
                    for (int r = 0; r < n; r++) {
                        if (target[r] == c && !((sup >> r) & 1)) { // try apply it on a missing char in the subset of target
                            sup |= 1 << r;
                            break;
                        }
                    }
                }
               // after you apply all possible chars in a sticker, you get an superset that take 1 extra sticker than subset
               // would take, so you can try to update the superset's minsticker number with dp[sub]+1;
                dp[sup] = min(dp[sup], dp[i] + 1); 
            }
        }
        return dp[m - 1]; // and the ultimate result
    }
};
__________________________________________________________________________________________________
