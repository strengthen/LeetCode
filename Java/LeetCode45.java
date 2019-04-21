__________________________________________________________________________________________________
1ms
class Solution {
    public int jump(int[] nums) {
        if(nums == null || nums.length <= 1) return 0;
        int curMax = 0;
        int nextMax = 0;
        int step = 0;
        int index = 0;
        while(index <= curMax){
            while(index <= curMax){
                nextMax = Math.max(nextMax, index + nums[index]);
                index ++;
            }
            curMax = nextMax;
            step ++;
            if(curMax >= nums.length - 1) return step;
        }
        return 0;
    }
}
__________________________________________________________________________________________________
1ms
public class Solution {
    public int jump(int[] nums) {
        if (nums.length==1) {
            return 0;
        }
        int max=0;
        int[] steps=new int[nums.length];
        steps[0]=0;
        for (int i = 0; i < nums.length-1; i++) {
            int n=nums[i];
            if (n+i>max) {
                int s=steps[i];
                for (int j = max+1; j <=n+i; j++) {
                    if (j<steps.length) {
                        if (steps[j]==0||steps[j]>s+1) {
                            steps[j]=s+1;
                        }
                    }
                }
                max=n+i;
            }
        }
        return steps[steps.length-1];
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public int jump(int[] nums) {
       int n = nums.length;
       int ans = 0; 
       int cur = 0;
       int next = 0; 
       if (n <= 1) {
           return 0;
       } 
       for(int i=0; i<n; i++) {
          if(cur >= i) {
              next = Math.max(next, nums[i] + i);
              if (next >= n-1) {
                  return ans + 1;
              }
          } else {
              ans++;
              cur = next;
              i--;
          }
       }
       return -1; 
    }
}
__________________________________________________________________________________________________
36144 kb
class Solution {
    public int jump(int[] nums) {
        int len = nums.length;
        int step = 0;
        int stepmax = 0, nextmax = 0;
        int pos = 0;
        
        while(stepmax < len-1){
            while(pos <= stepmax){
                nextmax = Math.max(nextmax, pos+nums[pos]);
                pos ++;
            }
            step ++;
            stepmax = nextmax;
        }
        
        return step;
    }
}
__________________________________________________________________________________________________
36164 kb
class Solution {
    public int jump(int[] nums) {
        
        if(nums.length ==0) return 0;
        
        int steps = 0;
        int maxReach = nums[0];
        int lastReach =0;
        
        for(int i=0; i<nums.length && i<=maxReach; i++) {
            
            if(lastReach < i) {
                steps++;
                lastReach = maxReach;
            }
            
            maxReach = Math.max(maxReach, i+nums[i]);
            
        }
        
        return steps;
    }
}
__________________________________________________________________________________________________