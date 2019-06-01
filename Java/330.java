__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    
    public int minPatches(int[] nums, int n) {
        long curend=0;
        int ans=0;
        for (int i:nums){
            while (curend<i-1&&curend<n){
                curend=curend*2+1;
                ++ans;
            }
            curend+=i;
            if (curend>=n) break;
        }
        while (curend<n){
            curend=curend*2+1;
            ++ans;
        }
        return ans;
    }
}
__________________________________________________________________________________________________
sample 35376 kb submission
class Solution {
    public int minPatches(int[] nums, int n) {
        int count = 0, i = 0;
        long priorSum = 0;
        while(priorSum<n) {
            if(i>=nums.length || nums[i]>priorSum+1) {
                ++count;
                priorSum = (priorSum<<1) + 1;
            }
            else priorSum += nums[i++];
        }
        return count;
    }
}
__________________________________________________________________________________________________
