__________________________________________________________________________________________________
sample 156 ms submission
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int>v;
        vector<int>ans;
        for (int i = 0; i < (1 << n); i++) {
            v.push_back((i ^ (i >> 1)));
        }
        int inx, flag = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == start) { flag = 1; inx = i; }
            if (flag == 1)ans.push_back(v[i]);
        }
        for (int i = 0; i < inx; i++) {
            ans.push_back(v[i]);
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 164 ms submission
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;
        int x = 0;
        while ((x ^ (x >> 1)) != start) ++x;
        for (int i = 0; i < (1 << n); ++i) {
            ans.push_back(x ^ (x >> 1));
            x = (x + 1) & ((1 << n) - 1);
        }
        return ans;
    }
};
__________________________________________________________________________________________________
