__________________________________________________________________________________________________
class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        int cal = 0;
        map<int, int> a;
        for (int i = 0;i < nums.size();i++) {
            a[nums[i]]++;
            if (cal < a[nums[i]]) {
                cal = a[nums[i]];
            }
        }
        if (cal * K <= nums.size()) {
            return true;
        } else {
            return false;
        }
    }
};

__________________________________________________________________________________________________
class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& a, int K) {
        int n = a.size();
        vector<int> p = a;
        vector<int> u(n);
        for (int i = 0; i < n; ++ i)
        {
            a[i] = lower_bound(p.begin(), p.end(), a[i])-p.begin();
            u[a[i]] ++;
        }
        int maxu = 0;
        for (int i = 0; i < n; ++ i)
            maxu = max(maxu, u[i]);
        if (n/maxu < K) return false;
        return true;
    }
};

__________________________________________________________________________________________________
