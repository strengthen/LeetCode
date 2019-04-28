__________________________________________________________________________________________________
sample 44 ms submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int L = difficulty.size();
        vector <pair <int, int>> jobs;
        for(int i = 0; i < L; i++)
            jobs.push_back({difficulty[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int index = 0, max_profit = 0, ans = 0;
        for(const auto& ability : worker)
        {
            while(index < L && jobs[index].first <= ability)
            {
                max_profit = max(jobs[index].second, max_profit);
                index++;
            }
            ans += max_profit;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 11780 kb submission
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans = 0;
        for(auto w:worker) {
            int p = 0;
            for(auto i=0ull; i<difficulty.size();++i) {
                p = max(p, difficulty[i]>w?0:profit[i]);
            }
            ans += p;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
