__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    
    bool helper(int sum, vector<int>& nums){
        if(sum == 0) return true;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] > sum) return false;
            if(nums[i] > 0 && nums[i] <= sum){
                nums[i] = -nums[i];
                if(helper(sum - abs(nums[i]), nums) == true) return true;
                nums[i] = abs(nums[i]); // backtracking
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        } 
        if(sum % 4 || nums.size() < 4) return false;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < 3; i++) // if three sticks are equal to sum / 4, 4th   
            if(helper(sum / 4, nums) == false)//one is automatically equals sum/4
                return false;                   
        
        return true;
    }
};
__________________________________________________________________________________________________
sample 9120 kb submission
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4)
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 4)
            return false;
        int target = sum / 4;
        vector<int> sums(4, 0);
        return helper(nums, 0, sums, target);
    }
    
    bool helper(vector<int>& nums, int cur, vector<int>& sums, int target){
        if(cur == nums.size()){
            return sums[0] == target && sums[1] == target && sums[2] == target;
        }
        for(int i = 0; i < 4; i++){
            if(sums[i] + nums[cur] > target)
                continue;
            sums[i] += nums[cur];
            if(helper(nums, cur+1, sums, target))
                return true;
            sums[i] -= nums[cur];
        }
        return false;
    }
    
};
__________________________________________________________________________________________________
