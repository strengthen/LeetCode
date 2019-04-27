__________________________________________________________________________________________________
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int res = INT_MAX, left = 0, right = k + 1, n = flowers.size();
        vector<int> days(n, 0);
        for (int i = 0; i < n; ++i) days[flowers[i] - 1] = i + 1;
        for (int i = 0; right < n; ++i) {
            if (days[i] < days[left] || days[i] <= days[right]) {
                if (i == right) res = min(res, max(days[left], days[right]));
                left = i; 
                right = k + 1 + i;
            }
        }
        return (res == INT_MAX) ? -1 : res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> s;
        for (int i = 0; i < flowers.size(); ++i) {
            int cur = flowers[i];
            auto it = s.upper_bound(cur);
            if (it != s.end() && *it - cur == k + 1) {
                return i + 1;
            }
            it = s.lower_bound(cur);
            if (it != s.begin() && cur - *(--it) == k + 1) {
                return i + 1;
            }
            s.insert(cur);
        }
        return -1;
    }
};
__________________________________________________________________________________________________
