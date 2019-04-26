__________________________________________________________________________________________________
sample 4 ms submission
struct Solution final {
    static bool checkInclusion(const string& s1, const string& s2) noexcept {
        if (s2.size() < s1.size()) return {};
        if (s1.size() == 1)
            return s2.find(s1.front()) != string::npos;

        char target_xor = 0;
        array<int, 26> target_chars {};

        for (char c : s1)
            target_xor ^= c, ++target_chars[c - 'a'];

        char rolling_xor = 0;
        array<int, 26> rolling_chars {};

        for (int i = 0; i < s1.size(); ++i)
            rolling_xor ^= s2[i], ++rolling_chars[s2[i] - 'a'];

        if (rolling_xor == target_xor &&
            rolling_chars == target_chars) return true;

        for (int i = 1; i < s2.size() - s1.size() + 1; ++i) {
            rolling_xor ^= s2[i - 1];
            rolling_xor ^= s2[i + s1.size() - 1];
            --rolling_chars[s2[i - 1] - 'a'];
            ++rolling_chars[s2[i + s1.size() - 1] - 'a'];

            if (rolling_xor == target_xor &&
                rolling_chars == target_chars) return true;
        }

        return false;
    }
};

static const auto speedup = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
__________________________________________________________________________________________________
sample 9772 kb submission
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 > len2) return false;
        
        vector<int> map1(26), map2(26);
        
        for (int i=0; i<len1; ++i) {
            map1[s1[i] - 'a']++;
            map2[s2[i] - 'a']++;
        }
        if (map1 == map2) return true;
        for (int i=0; i+len1<len2; ++i) {
            map2[s2[i] - 'a']--;
            map2[s2[i+len1] - 'a'] ++;
            if (map1 == map2)
                return true;
        }
        return false;
    }
};
__________________________________________________________________________________________________
