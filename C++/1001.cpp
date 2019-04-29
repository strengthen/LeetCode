__________________________________________________________________________________________________
sample 332 ms submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

namespace std
{
    template <>
    struct hash<pair<int, int>>
    {
        size_t operator()(const pair<int, int> &p) const __attribute__((no_sanitize("shift")))
        {
            return hash<long>()(((long) p.first << 32) | ((long) p.second));
        }
    };
}

class Solution {
public:
    int get_line(vector<int> &lamp) {
        return lamp[0];
    }
    
    int get_column(vector<int> &lamp) {
        return lamp[1];
    }
    
    int get_st_diag(vector<int> &lamp, int &n) {
        int in = min(lamp[0], lamp[1]);
        pair<int, int> p = {lamp[0] - in, lamp[1] - in};
        
        if (p.first == 0)
            return p.second;
        
        return p.first + n - 1;
    }
    
    int get_nd_diag(vector<int> &lamp, int &n) {
        int in = min(lamp[0], n - lamp[1] - 1);
        pair<int, int> p = {lamp[0] - in, lamp[1] + in};
        
        if (p.first == 0)
            return p.second;
        
        return p.first + n - 1;
    }
    
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries) {
        unordered_set<pair<int, int>> us(lamps.size());
        unordered_map<int, int> lines;
        unordered_map<int, int> columns;
        unordered_map<int, int> st_diag;
        unordered_map<int, int> nd_diag;
        
        for (auto &e : lamps) {
            pair<int, int> p = {e[0], e[1]};
            
            us.emplace(p);
            ++lines[get_line(e)];
            ++columns[get_column(e)];
            ++st_diag[get_st_diag(e, n)];
            ++nd_diag[get_nd_diag(e, n)];
        }
        
        int index = 0;
        vector<int> result(queries.size());
        for (auto &e : queries) {
            pair<int, int> q = {e[0], e[1]};
            bool b = (lines.find(get_line(e)) != lines.end())
                  || (columns.find(get_column(e)) != columns.end())
                  || (st_diag.find(get_st_diag(e, n)) != st_diag.end())
                  || (nd_diag.find(get_nd_diag(e, n)) != nd_diag.end());
            
            if (!b)
                result[index] = 0;
            else {
                result[index] = 1;
                
                for (auto &offset : {make_pair(-1, -1), make_pair(-1, 0), make_pair(-1, 1), make_pair(0, -1), make_pair(0, 0), make_pair(0, 1), make_pair(1, -1), make_pair(1, 0), make_pair(1, 1)}) {
                    pair<int, int> p = {e[0] + offset.first, e[1] + offset.second};
                    auto it = us.find(p);
                    if (it != us.end()) {
                        us.erase(it);
                        
                        vector<int> v = {p.first, p.second};
                        
                        auto it1 = lines.find(get_line(v));
                        if (!--it1->second)
                            lines.erase(it1);
                        
                        auto it2 = columns.find(get_column(v));
                        if (!--it2->second)
                            columns.erase(it2);
                        
                        auto it3 = st_diag.find(get_st_diag(v, n));
                        if (!--it3->second)
                            st_diag.erase(it3);
                        
                        auto it4 = nd_diag.find(get_nd_diag(v, n));
                        if (!--it4->second)
                            nd_diag.erase(it4);
                    }
                }
            }
            ++index;
        }
        
        return result;
    }
};
__________________________________________________________________________________________________
sample 360 ms submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair_key) const
    {
        auto h1 = std::hash<T1>{}(pair_key.first);
        auto h2 = std::hash<T2>{}(pair_key.second);
        return h1 ^ h2;
    }
};

class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector <int> ans;
        unordered_set <pair <int, int>, pair_hash> lamp_set;
        unordered_map <int, int> count_x, count_y, count_x_plus_y, count_x_minus_y;
        for(const auto& lamp : lamps)
        {
            int x = lamp[0], y = lamp[1];
            count_x[x]++;
            count_y[y]++;
            count_x_plus_y[x + y]++;
            count_x_minus_y[x - y]++;
            lamp_set.insert({x, y});
        }
        for(const auto& query : queries)
        {
            int x = query[0], y = query[1];
            if(count_x.count(x) || count_y.count(y) || count_x_plus_y.count(x + y) || count_x_minus_y.count(x - y))
                ans.push_back(1);
            else
                ans.push_back(0);
            for(int dx = -1; dx <= 1; dx++)
            {
                for(int dy = -1; dy <= 1; dy++)
                {
                    int X = x + dx, Y = y + dy;
                    if(lamp_set.count({X, Y}))
                    {
                        lamp_set.erase({X, Y});
                        count_x[X]--;
                        if(count_x[X] == 0)
                            count_x.erase(X);
                        count_y[Y]--;
                        if(count_y[Y] == 0)
                            count_y.erase(Y);
                        count_x_plus_y[X + Y]--;
                        if(count_x_plus_y[X + Y] == 0)
                            count_x_plus_y.erase(X + Y);
                        count_x_minus_y[X - Y]--;
                        if(count_x_minus_y[X - Y] == 0)
                            count_x_minus_y.erase(X - Y);
                    }
                }
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
