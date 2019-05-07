__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean canJump(int[] nums) {
        if (nums.length < 2) {
            return true;
        }
       
        for (int curr = nums.length - 2; curr >= 0; curr--) {
            if (nums[curr] == 0) {
                int neededJumps = 1;
                while (neededJumps > nums[curr]) {
                    neededJumps++;
                    curr--;
                    if (curr < 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 36332 kb submission
class Solution {
    public boolean canJump(int[] nums) {
        for(int i = 0; i < nums.length-1; i++) {
            if(nums[i]!= 0 ) continue;
            int zeroPos = i;
            int j = 0;
            for(j = zeroPos-1; j >= 0; j--) {
                if((j + nums[j]) > zeroPos || ((j + nums[j]) >= nums.length-1)) {
                    break;
                }
            }
            
            if(j == -1)
            return false;
        }
        return true;
    }
}
__________________________________________________________________________________________________
