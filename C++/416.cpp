__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (auto a : nums) sum += a;
        if (sum%2) return false;
        
        sort(nums.rbegin(), nums.rend());
		return helper(nums, 0, sum/2);
    }
private:
	bool helper(vector<int>& nums, int begin, int target) {//注意 回溯如果可以写成这种简单形式就不要写 for+递归形式了
        if (begin == nums.size()) return false;
		if (!target) return true;
		if (nums[begin] > target) return false;
		
		return helper(nums, begin+1, target - nums[begin]) || helper(nums, begin+1, target);
	}
};
__________________________________________________________________________________________________
sample 8844 kb submission
class Solution {
public:
    bool canPartition1(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2) return false;
        
        sum /= 2;
        
        // 0-1 knapsack with bag size = sum
        int gain[nums.size() + 1][sum + 1];
        
        for (int i = 0; i <= nums.size(); i++) {
            for (int w = 0; w <= sum; w++) {
                if (i == 0 || w == 0) {
                    gain[i][w] = 0;
                } else {
                    gain[i][w] = gain[i-1][w];
                    if (w >= nums[i-1] && gain[i][w] < gain[i-1][w-nums[i-1]] + nums[i-1]) {
                        gain[i][w] = gain[i-1][w-nums[i-1]] + nums[i-1];
                    }
                }
            }
        }
        
        return gain[nums.size()][sum] == sum;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2) return false;
        
        sum /= 2;
        
        // 0-1 knapsack with bag size = sum
        int gain[2][sum + 1];
        int r = 0;
        
        for (int i = 0; i <= nums.size(); i++) {
            for (int w = 0; w <= sum; w++) {
                if (i == 0 || w == 0) {
                    gain[r][w] = 0;
                } else {
                    gain[r][w] = gain[1-r][w];
                    if (w >= nums[i-1] && gain[r][w] < gain[1-r][w-nums[i-1]] + nums[i-1]) {
                        gain[r][w] = gain[1-r][w-nums[i-1]] + nums[i-1];
                    }
                }
            }
            r = 1 - r;
        }
        
        return gain[1-r][sum] == sum;
    }
};
__________________________________________________________________________________________________
