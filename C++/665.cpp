__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int i;
        for (i=0;i<nums.size()-1;i++) {
            if (nums[i]>nums[i+1]) {
                break;
            }
        }
        if (i>=nums.size()-2) {
            return true;
        }
        if (i==0) {
            i++;
        }
        else if (nums[i-1]<=nums[i+1]) {
            i++;
        }
        else if (nums[i]<=nums[i+2]) {
            i+=2;
        }
        else {
            return false;
        }
        for (i;i<nums.size()-1;i++) {
            if (nums[i]>nums[i+1]) {
                return false;
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
sample 10404 kb submission
static int speedup = [](){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n-1){
            if(nums[i] > nums[i+1]){
                if(i-1 >= 0){
                    if(nums[i+1] >= nums[i-1]){
                        nums[i] = nums[i-1];
                    }else{
                        nums[i+1] = nums[i];
                    }
                }else{
                    nums[i] = nums[i+1];
                }
                break;
            }
            i++;
        }
        
        i = 0;
        while(i < n-1){
            if(nums[i] > nums[i+1]){
                return false;
            }
            i++;
        }
        return true;
    }
};
__________________________________________________________________________________________________
