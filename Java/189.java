__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public void rotate(int[] nums, int k) {
        int len = nums.length;
        k %= len;
        if(k == 0) return;
        int[] t = nums.clone();
        
        for(int i = 0; i < nums.length; i++){
            int j = i;
            if(j - k < 0) j += len;
            // System.out.println(t[j-k]);
            nums[i] = t[j-k];
        }
        
        return;
    }
}
__________________________________________________________________________________________________
sample 34544 kb submission
class Solution {
    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        
        this.help(nums, 0, nums.length-k-1);
        this.help(nums, nums.length-k, nums.length-1);
        this.help(nums, 0, nums.length-1);
    }
    
    
    private void help(int[] nums, int h, int t){
        while(h < t){
            nums[h] ^= nums[t];
            nums[t] ^= nums[h];
            nums[h] ^= nums[t];
            h++;
            t--;
        }
    }
}
__________________________________________________________________________________________________
