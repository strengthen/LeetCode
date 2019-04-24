__________________________________________________________________________________________________
// Time Complexity O(nlgn)
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() <= 2) return;
        for (int i = 2; i < nums.size(); i += 2) {
            swap(nums[i], nums[i - 1]);
        }
    }
};
__________________________________________________________________________________________________
// Time Complexity O(n)
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        if (nums.size() <= 1) return;
        for (int i = 1; i < nums.size(); ++i) {
            if ((i % 2 == 1 && nums[i] < nums[i - 1]) || (i % 2 == 0 && nums[i] > nums[i - 1])) {
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};
__________________________________________________________________________________________________
