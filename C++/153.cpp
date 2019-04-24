__________________________________________________________________________________________________
4ms
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        
        while ( l < r ) {
            if ( nums[l] <= nums[r] )
                return nums[l];
            
            int m = l + (r-l)/2;
            
            if ( nums[m] > nums[r] )
                l = m+1;
            else
                r = m;
        }
        
        return nums[l];
    }
};
__________________________________________________________________________________________________
8512 kb
class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i - 1]){
                return nums[i];
            }
        }
        return nums[0];
    }
};
__________________________________________________________________________________________________
