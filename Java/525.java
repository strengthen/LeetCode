__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public int findMaxLength(int[] nums) {
        int n = nums.length;
        int len = 2 * n + 1;
        int[] f = new int[len];
        for(int i=0; i<len; i++) f[i] = -2;
        int s = 0;
        int ret = 0;
        f[n] = -1;
        for(int i=0; i<n; i++) {
            s += (nums[i]==0? -1: 1);
            if(f[s+n]!=-2){
                ret = Math.max(ret, i-f[s+n]);
            }
        
            else f[s+n] = i;
        }
        return ret;
    }
}
__________________________________________________________________________________________________
sample 52188 kb submission
class Solution {
    public int findMaxLength(int[] nums) {
        int sum =0;
        int maxLen=0;
        int endIndex = 0;
        Map<Integer,Integer> m = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0)
                nums[i]=-1;
        }
        for(int i=0;i<nums.length;i++){
            sum =sum + nums[i];
            if(sum==0){
                maxLen = i+1;
                endIndex = i;
            }
            if(m.containsKey(sum)){
                if(maxLen< i-m.get(sum)){
                    maxLen = i - m.get(sum);
                    endIndex =i;
                }
            }else
                m.put(sum,i);
            
        }
        return maxLen;
    }
}
__________________________________________________________________________________________________
