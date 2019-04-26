__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int m = s1.size(), n = s2.size();
        vector<int> f(n, 0);
        auto next = f;
        for (int i = 0; i < n; ++i) {
            int start = i;
            for (auto c : s1) {
                if (c != s2[start]) continue;
                if (++start == s2.size()) {
                    start = 0;
                    f[i]++;
                };
            }
            next[i] = start;
        }
        unordered_map<int, pair<int,int>> pos2ans;
        int ans = 0;
        int cur = 0;
        bool findloop = false;
        pos2ans[cur] = make_pair(ans, -1);
        for (int i = 0; i < n1; ++i) {
            ans += f[cur];
            cur = next[cur];
            if (!findloop && pos2ans.count(cur)) {
                ans += (ans - pos2ans[cur].first)*((n1-1-i)/(i-pos2ans[cur].second));
                i = n1 -1 - ((n1-1-i)%(i-pos2ans[cur].second));
                findloop = true;
            }
            else if (!findloop) pos2ans[cur] = make_pair(ans, i);
        }
        return ans / n2;
    }
};
__________________________________________________________________________________________________
sample 8616 kb submission
// Basically brute-force, the running time is close to the limit.
#include <string>
using std::string;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int ls1 = s1.size();
        int ls2 = s2.size();
        if (ls1 == 0 || ls2 == 0) {
            return 0;
        }
        if (n1 == 0 || n2 == 0) {
            return 0;
        }
        
        int i, j;
        int c1, c2;
        
        i = j = 0;
        c1 = c2 = 0;
        while (c1 < n1) {
            if (s1[i] == s2[j]) {
                ++j;
            }
            ++i;
            
            if (i == ls1) {
                i = 0;
                ++c1;
            }
            if (j == ls2) {
                j = 0;
                ++c2;
            }
            if (i == 0 && j == 0) {
                // An exact match is found.
                // Like least common multiple, you know.
                break;
            }
        }
        
        // Actually both are the same.
        if (i == 0 && j == 0) {
            return (1LL * n1 * c2 / c1) / n2;
        } else {
            return c2 / n2;
        }
    }
};
__________________________________________________________________________________________________
