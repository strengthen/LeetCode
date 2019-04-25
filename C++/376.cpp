__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        int up[nums.size()];
        int down[nums.size()];
        
        up[0] = down[0] = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                up[i] = max(up[i-1],down[i-1]+1);
                down[i] = down[i-1];
            }
            else if(nums[i]<nums[i-1]){
                down[i]=max(down[i-1],up[i-1]+1);
                up[i] = up[i-1];
            }
            else{
                down[i] = down[i-1];
                up[i] = up[i-1];
            }

        }
        return max(up[nums.size()-1],down[nums.size()-1]);
    }
};
__________________________________________________________________________________________________
sample 8444 kb submission
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // Solution 1: O(n) DP solution.
        int l = nums.size(), down = 1, up = 1; 
        if(l < 2)
            return l;
        for(int i=1; i < l; i++){
            if(nums[i] > nums[i-1]){
                up = down + 1;
            }
            else if(nums[i] < nums[i-1]){
                down = up + 1;
            } // else, up and down remain the same.
        }
        return max(up, down);
    }
};
__________________________________________________________________________________________________
