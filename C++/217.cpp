__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        /*unordered_set<int> encountered;
        for (const int n : nums) {
            if (encountered.find(n) != encountered.end()) return true;
            encountered.emplace(n);
        }
        return false;*/
        
        if (nums.empty()) return false;

        auto result = minmax_element(nums.begin(), nums.end());
        size_t range = *result.second - *result.first;
        if (range == 0) range = 1;

        vector<bool> encountered(range, false);
        for (const int n : nums) {
            size_t i = n - *result.first;
            if (encountered[i] == true) return true;
            encountered[i] = true;
        }
        return false;
    }
};
__________________________________________________________________________________________________
sample 11016 kb submission
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        auto size = nums.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[j] == nums[i])
                    return true;
            }
        }
        return false;
    }
};
__________________________________________________________________________________________________
