__________________________________________________________________________________________________
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res, nums(length + 1, 0);
        for (int i = 0; i < updates.size(); ++i) {
            nums[updates[i][0]] += updates[i][2];
            nums[updates[i][1] + 1] -= updates[i][2];
        }
        int sum = 0;
        for (int i = 0; i < length; ++i) {
            sum += nums[i];
            res.push_back(sum);
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length + 1);
        for (auto a : updates) {
            res[a[0]] += a[2];
            res[a[1] + 1] -= a[2];
        }
        for (int i = 1; i < res.size(); ++i) {
            res[i] += res[i - 1];
        }
        res.pop_back();
        return res;
    }
}
__________________________________________________________________________________________________
