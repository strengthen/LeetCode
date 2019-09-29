__________________________________________________________________________________________________
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        int l = 0, r = -1, curCost = 0;
        for (int i = 0; i < s.size(); ++i) {
            ++r;
            curCost += abs(s[r] - t[r]);
            
            while (curCost > maxCost && l <= r) {
                curCost -= abs(s[l] - t[l]);
                ++l;
            }
            
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
