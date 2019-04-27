__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        long long max1 = INT_MIN, max2 = INT_MIN;
        int index = 0, temp = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
                index = i;
            }
            else if(nums[i] > max2) {
                max2 = nums[i];
            }
        }
        return max1 >= (2*max2) ? index : -1;
    }
};
__________________________________________________________________________________________________
sample 9596 kb submission
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first = -1;
        int second = -1;
        
        int index = -1;
        
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] > first) {
                second = first;
                first = nums[i];
                index = i;
            } else if (nums[i] <= first && nums[i] > second) {
                second = nums[i];
            }
        }
        
        return first >= 2*second ? index : -1;
    }
};
__________________________________________________________________________________________________
