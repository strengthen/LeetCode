__________________________________________________________________________________________________
sample 4 ms submission
/*
 * @lc app=leetcode id=420 lang=cpp
 *
 * [420] Strong Password Checker
 */
class Solution {
public:
    int strongPasswordChecker(string s) {
        int n = s.size();
        int has_u = 0, has_l = 0, has_d = 0;
        for (auto c : s) {
            if (isupper(c)) has_u = 1;
            else if (islower(c)) has_l = 1;
            else if (isdigit(c)) has_d = 1;
        }
        int miss = 3 - has_d - has_l - has_u;
        vector<pair<int,int>> ranges;
        int pre = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == n) {
                if (i - pre >= 3) ranges.emplace_back(pre, i);
                break;
            }
            if (s[i] != s[i-1]) {
                if (i - pre >= 3) ranges.emplace_back(pre, i);
                pre = i;
            }
        }
        sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {
            return 1+((a.second - a.first)%3) < 1+((b.second - b.first)%3);
        });
        if (n < 6) {
            return max(6-n, miss);
        }
        if (n > 20) {
            int del = n - 20;
            int del_to_eli_aaa = 0;
            for (auto r : ranges) {
                del_to_eli_aaa += r.second -r.first - 2;
            }
            if (del >= del_to_eli_aaa) return del + miss;
            int ans = 0, left_del = del, rep = 0;
            for (auto &r : ranges) {
                int d = 1+((r.second - r.first) % 3);
                if (left_del < d) break;
                r.first += d;
                left_del -= d;
            }
            for (auto r : ranges) {
                if (r.second - r.first >= 3) {
                    rep += (r.second - r.first) / 3;
                }
            }
            rep -= left_del / 3;
            left_del %= 3;
            return max(rep, miss) + del;
        }
        int rep = 0;
        for (auto r : ranges) {
            rep += (r.second - r.first) / 3;
        }
        return max(rep, miss);
    }
};
__________________________________________________________________________________________________
sample 8400 kb submission
class Solution {
public:
    int strongPasswordChecker(string s) {
        if (!s.size()) return 6;
        int n(s.size());
        
        auto isdigit = [](char& c) { return c >= '0' && c <= '9'; };
        auto islower = [](char& c) { return c >= 'a' && c <= 'z'; };
        auto isupper = [](char& c) { return c >= 'A' && c <= 'Z'; };
        
        bool hasdigit(0), haslower(0), hasupper(0);
        vector<int> repeats;
        
        for (int i(0), j(0); i < n; i = j) {
            char c = s[j=i];
            if (isdigit(c)) hasdigit = 1;
            if (islower(c)) haslower = 1;
            if (isupper(c)) hasupper = 1;
            
            while (j < n && s[j] == s[i]) ++j;
            if (j-i > 2) repeats.push_back(j-i);
        }
        
        int insert(0), del(0), replace(0);
        int work(0);
        if (n < 6) insert = 6-n;
        else if (n > 20) {
            del = n-20;
            int d(0);
            for (int i : repeats) d += i-2;
            if (del < d) {
                for (int i : repeats) replace += i/3;
                replace = max(replace-del, (d-del+2)/3);
            }
        }
        else {
            for (int i : repeats) replace += i/3;
        }
        
        int missd = 3 - hasdigit - haslower - hasupper;
        
        return insert+del+max(replace, missd-insert);
    }
};
__________________________________________________________________________________________________
