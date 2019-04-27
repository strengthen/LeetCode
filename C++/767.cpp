__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string reorganizeString(string S) {
        vector<int> count(26, 0);
        for (auto c : S) {
            count[c-'a'] += 1;
            if (count[c-'a'] > (S.size() + 1) / 2) {
                return "";
            }
        }
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                pq.push({count[i], i+'a'});
            }
        }
        string res;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            res += p.second;
            if (!pq.empty()) {
                auto p2 = pq.top();
                pq.pop();
                res += p2.second;
                p2.first -= 1;
                if (p2.first != 0) {
                    pq.push(p2);
                }
            }
            p.first -= 1;
            if (p.first != 0) {
                pq.push(p);
            }
        }
        return res;
    }
};

__________________________________________________________________________________________________
sample 8696 kb submission
class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        vector<pair<int, int>> cnt(26);
        for (char& c : S) cnt[c-'a'].first++;
        for (int i = 0; i < 26; i++) {
            cnt[i].second = i;
            if (cnt[i].first > (n + 1) / 2) {
                return "";
            }
        }
        sort(cnt.begin(), cnt.end(), greater<pair<int, int>>());
        
        string ans(n, 'a');
        int j = 0;
        for (int i = 0; i < n; i+= 2) {
            if (cnt[j].first == 0) {
                j++;
            }
            ans[i] = cnt[j].second + 'a';
            cnt[j].first--;
        }
        for (int i = 1; i < n; i+= 2) {
            if (cnt[j].first == 0) {
                j++;
            }
            ans[i] = cnt[j].second + 'a';
            cnt[j].first--;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
