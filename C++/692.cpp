__________________________________________________________________________________________________
sample 12 ms submission
struct Solution final {
    static vector<string> topKFrequent(vector<string>& words, int k) noexcept {
        unordered_map<string, int> tally(words.size());
        auto it = words.begin();
        for (auto& w : words) if (!tally[w]--) swap(*it++, w);
        words.resize(tally.size());
        const auto compare = [&tally](const string& a, const string& b) __attribute__((always_inline)) noexcept {
            return tie(tally[a], a) < tie(tally[b], b);
        };
        if (k == 1) {
            iter_swap(words.begin(), min_element(words.begin(), words.end(), compare));
            words.resize(1);
            return words;
        }
        nth_element(words.begin(), words.begin() + (k - 1), words.end(), compare);
        words.resize(k);
        sort(words.begin(), words.end(), compare);
        return words;
    }
};

static const auto speedup = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
__________________________________________________________________________________________________
× Close
sample 11568 kb submission
static int fast = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        auto cmp = [&](const pair<string,int> &lhs, const pair<string,int> &rhs){
            return lhs.second == rhs.second ? lhs.first > rhs.first : lhs.second < rhs.second;
        };

        typedef priority_queue<pair<string,int>,vector<pair<string,int>>, decltype(cmp)> PQ;

        PQ pq(cmp);
        map<string,int> m;
        vector<string> res;

        for(auto &word: words)
            ++m[word];

        for(auto &pair: m)
            pq.push(pair);

        while(k--){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
__________________________________________________________________________________________________
