__________________________________________________________________________________________________
× Close
sample 20 ms submission
#define SHORT(S) short(S[0] - 'A' << 10 | S[1] - 'A' << 5 | S[2] - 'A')

struct Solution final {
    static vector<string> findItinerary(vector<pair<string, string>> tickets) noexcept {
        unordered_map<short, pair<vector<short>, vector<bool>>> edges;
        for (const auto& [from, to] : tickets)
            edges[SHORT(from)].first.push_back(SHORT(to));
        for (auto& [_, p] : edges)
            sort(p.first.begin(), p.first.end()),
            p.second.resize(p.first.size());
        pair<short, short> choices[tickets.size() + 1] = {};
        auto current = choices;
        *current++ = {SHORT("JFK"), -1};
        while (true) {
            if (current - choices == tickets.size() + 1) break;
            auto& [vertex, choice] = *(current - 1);
            auto& [destinations, taken] = edges[vertex];
            if (choice > -1) taken[choice] = false;
            bool backtrack = false;
            do
                if (++choice == taken.size()) {
                    --current;
                    backtrack = true;
                    break;
                }
            while (taken[choice]);
            if (backtrack) continue;
            taken[choice] = true;
            *current++ = {destinations[choice], -1};
        }
        vector<string> itinerary(tickets.size() + 1, "***");
        for(auto i = 0; i < tickets.size() + 1; ++i) {
            short code = choices[i].first;
            itinerary[i][0] = 'A' + (code >> 10);
            itinerary[i][1] = 'A' + (code >> 5 & 0x1F);
            itinerary[i][2] = 'A' + (code & 0x1F);
        }
        return itinerary;
    }
};

static const auto speedup = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
__________________________________________________________________________________________________
sample 15600 kb submission
class Solution
{
public:
    vector<string> findItinerary(const vector<pair<string, string>>& tickets)
    {
        map<string, multiset<string>> data;
        for (const auto& ticket : tickets)
        {
            data[ticket.first].emplace(ticket.second);
        }
        
        constexpr char jfk[] = "JFK";
        vector<string> ret;
        dfs(data, jfk, ret);
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
private:
    void dfs(map<string, multiset<string>>& data, const string& from, vector<string>& result)
    {
        multiset<string>& to = data[from];
        while (!to.empty())
        {
            string newFrom = *to.begin();
            to.erase(to.begin());
            dfs(data, newFrom, result);
        }
        result.emplace_back(from);
    }
};
__________________________________________________________________________________________________
