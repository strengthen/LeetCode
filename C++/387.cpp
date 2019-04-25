__________________________________________________________________________________________________
sample 12 ms submission
static const int _x_ = [] () { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; } ();

class Solution {
public:
    int firstUniqChar(string s) {
        array<pair<int, bool>, 256> met;
        met.fill(make_pair(-1, false));

        for (int i = 0; i < s.size(); ++i) {
            if (met[s[i]].first < 0) {
                met[s[i]].first = i;
            }
            else {
                met[s[i]].second = true;
            }
        }

        int min_i = s.size();
        for (auto m : met) {
            if (m.first >= 0 && !m.second) {
                min_i = min(min_i, m.first);
            }
        }

        return (min_i == s.size() ? -1 : min_i);
    }
};
__________________________________________________________________________________________________
× Close
sample 11956 kb submission
static const auto speedup = []() { 
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    return 0; 
}();

class Solution {
public:
    int firstUniqChar(string_view s) {
        const auto size = s.size();
        switch (size) {
            case 0:
                return -1;
            case 1:
                return 0;
            default:
                auto letter_frequencies = array<size_t, 256>(); 
                for (auto i = string::size_type(0); i < size; i++) {
                    letter_frequencies[s[i]]++;
                }
                for (auto i = string::size_type(0); i < size; i++) {
                    if (letter_frequencies[s[i]] == 1) {
                        return i;
                    }
                }
                return -1;
        }
    }
};
__________________________________________________________________________________________________
