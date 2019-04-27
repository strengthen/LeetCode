__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    bool helper(vector<int>& nums, int k, int target, int start, int curSum, vector<bool>& visited) {
        if (k == 1) return true;
        if (curSum > target) return false;
        if (curSum == target) return helper(nums, k - 1, target, 0, 0, visited);
        for (int i = start; i < nums.size(); ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            if (helper(nums, k, target, i + 1, curSum + nums[i], visited)) return true;
            visited[i] = false;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<bool> visited(nums.size(), false);
        return helper(nums, k, sum / k, 0, 0, visited);
    }
};
__________________________________________________________________________________________________
sample 8928 kb submission
class Solution {
public:
     bool canPartitionKSubsetsRec(const vector<int>& nums,
                                  int currentIdx,
                                  vector<int>& sums,
                                  const int k,
                                  const int targetSum)
    {
        if (currentIdx >= nums.size())
            return true;
         
        for (int i = 0; i < k; ++i)
        {
            if (sums[i] + nums[currentIdx] <= targetSum)
            {
                sums[i] += nums[currentIdx];
                
                if (canPartitionKSubsetsRec(nums, currentIdx + 1, sums, k, targetSum))
                    return true;
                
                sums[i] -= nums[currentIdx];
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int sum = 0;        
        for (int i : nums)
            sum += i;        
        if (sum % k != 0)
            return false;        
        int targetSum = sum / k;        
        vector<int> sums(k, 0);        
        return canPartitionKSubsetsRec(nums, 0, sums, k, targetSum);
    }
};
__________________________________________________________________________________________________
