__________________________________________________________________________________________________
sample 8 ms submission
static int x = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = nums[0];
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
__________________________________________________________________________________________________
sample 10944 kb submission
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i;
        int times = 0;
        int candidate = 0;
        for(i = 0;i < nums.size(); i++){
            if(times == 0){
                candidate = nums[i];
                times = 1;
            }
            else{
                if(nums[i] == candidate){
                    times ++;
                }else{
                    times --;
                }
            }
        }
        return candidate;
    }
};
__________________________________________________________________________________________________
