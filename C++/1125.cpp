__________________________________________________________________________________________________
const int INF = 1e9 + 5;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int s = req_skills.size();
        int n = people.size();
        vector<int> masks(n, 0);

        for (int i = 0; i < n; i++)
            for (string skill : people[i]) {
                int index = -1;

                for (int j = 0; j < s; j++)
                    if (skill == req_skills[j])
                        index = j;

                if (index >= 0)
                    masks[i] |= 1 << index;
            }

        vector<vector<int>> dp(n + 1, vector<int>(1 << s, INF));
        dp[0][0] = 0;

        for (int i = 0; i < n; i++)
            for (int mask = 0; mask < 1 << s; mask++) {
                dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][mask]);
                dp[i + 1][mask | masks[i]] = min(dp[i + 1][mask | masks[i]], dp[i][mask] + 1);
            }

        int current = (1 << s) - 1;
        assert(dp[n][current] < INF);
        vector<int> team;

        for (int i = n - 1; i >= 0; i--) {
            int next_mask = -1;

            for (int m = 0; m < 1 << s; m++)
                if ((current | m) == current && (m | masks[i]) == current && dp[i][m] + 1 == dp[i + 1][current]) {
                    next_mask = m;
                    break;
                }

            if (next_mask >= 0) {
                team.push_back(i);
                current = next_mask;
            }
        }

        reverse(team.begin(), team.end());
        return team;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    pair<int, long long> dp[62][1 << 16];
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        vector<int> v;
        for (int i = 0; i < people.size(); ++i) {
            int mask = 0;
            for (int j = 0; j < req_skills.size(); ++j) {
                for (int t = 0; t < people[i].size(); ++t) {
                    if (req_skills[j] == people[i][t])
                        mask |= 1 << j;
                }
            }
            v.push_back(mask);
        }
        
        int n = v.size(), k = req_skills.size();
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < (1 << k); ++j) {
                dp[i][j] = make_pair(n, (1LL << n) - 1);
            }
        }
        
        dp[0][0] = make_pair(0, 0LL);
        for (int i = 0; i < n; ++i) {
            for (int mask = 0; mask < (1 << k); ++mask) {
                dp[i + 1][mask] = dp[i][mask];
            }
            for (int mask = 0; mask < (1 << k); ++mask) {
                int nMask = mask | v[i];
                if (dp[i + 1][nMask].first > dp[i][mask].first + 1) {
                    dp[i + 1][nMask] = make_pair(dp[i][mask].first + 1, dp[i][mask].second | (1LL << i));
                }
            }
        }
        
        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            if (dp[n][(1 << k) - 1].second & (1LL << i))
                ret.push_back(i);
        }
        //cout << dp[n][(1 << k) - 1].first << endl;
        return ret;
    }
};
__________________________________________________________________________________________________
