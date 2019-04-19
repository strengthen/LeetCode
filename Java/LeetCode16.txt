__________________________________________________________________________________________________
2ms
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int cp, lp, rp, mp;
        int minDiff = nums[0] + nums[1] + nums[nums.length - 1] - target;
        int lmDiff = minDiff, rmDiff = minDiff, diff = minDiff;
        int indicator = 0;

        Arrays.sort(nums);

        for (cp = 0; cp < nums.length && minDiff != 0; cp++) {
            // narrow the range of (lp, rp) bi-directionly
            lp = cp + 1;
            rp = nums.length - 1;
            mp = (lp + rp) / 2;
            while (lp < rp - 1) {

                lmDiff = nums[lp] + nums[mp] + nums[cp] - target;
                rmDiff = nums[rp] + nums[mp] + nums[cp] - target;

                if (lmDiff == 0 || rmDiff == 0) {
                    return target;
                }
                else if (lmDiff > 0) {
                    rp = mp;
                    mp = (lp + rp) / 2;
                    indicator = 1;
                }
                else if (rmDiff < 0) {
                    lp = mp;
                    mp = (lp + rp) / 2;
                    indicator = -1;
                }
                else if (lmDiff < 0 && rmDiff > 0) {
                    indicator = 0;
                    break;
                }
            }

            if (indicator == 0) {
                while (lp < rp) {
                    diff = nums[lp] + nums[rp] + nums[cp] - target;
                    if (diff == 0) {
                        return target;
                    }
                    else if (diff > 0) {
                        if (Math.abs(minDiff) > diff)
                            minDiff = diff;
                        rp--;
                    }
                    else if (diff < 0) {
                        if (Math.abs(minDiff) > -diff)
                            minDiff = diff;
                        lp++;
                    }
                }
            }
            else if (rp > lp) {
                diff = nums[cp] + nums[lp] + nums[rp] - target;
                if (diff > 0) {
                    if (Math.abs(minDiff) > diff)
                        minDiff = diff;
                }
                if (diff < 0) {
                    if (Math.abs(minDiff) > -diff)
                        minDiff = diff;
                }
            }
        }
        return minDiff + target;
    }
}
__________________________________________________________________________________________________
2ms
public class Solution {
    int ans=Integer.MIN_VALUE;
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);  
        int length=nums.length;  
        for (int i = 0; i < length-2; i++) {  
            if (i==0||nums[i]!=nums[i-1]) {  
                f(nums,i,i+1,length-1,target);
                if (ans==0) {
                    return target;
                }
            }  
        }  
        return target+ans;  
    }
    public void f(int[] nums,int s,int m,int e,int target){  
        while (m<e) {  
            int res=nums[s]+nums[m]+nums[e]-target;  
            if (res==0) {  
                ans=0;
                break;
            }else if(res<0) {
                m++;  
            }else {
                e--;  
            }
            if (ans/res!=0) {
                ans=res;
            }
        }  
    };  
}
__________________________________________________________________________________________________
3ms
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int ans = Integer.MAX_VALUE;
        int ret = ans;
        for(int i = 0; i <= nums.length - 3; i++)
        {
            int left = i + 1, right = nums.length - 1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = sum > target ? sum - target : target - sum;
                if(diff < ans)
                {
                    ans = diff;
                    ret = sum;
                }
                
                if(sum < target)
                {
                    left++;
                }else if(sum > target)
                {
                    right--;
                }else {
                    return sum;
                }
            }
        }
        
        return ret;
    }
}
__________________________________________________________________________________________________
34936 kb
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        if(nums==null || nums.length<3) return 0;
        Arrays.sort(nums);
        int len = nums.length;
        int result = nums[0]+nums[1]+nums[len-1];
        for(int i=0; i<len-2; i++){
            int val1 = nums[i];
            int j=i+1;
            int k=len-1;
            while(j<k){
                int sum = val1+nums[j]+nums[k];
                if(sum >target){
                    k--;
                }else
                    j++;
                if(Math.abs(target-result) > Math.abs(target-sum)){
                    result = sum;
                }
                
            }
            
        }
        return result;
    }
}
__________________________________________________________________________________________________
34980 kb
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int sum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.length-2;i++){
            int j=i+1,k=nums.length-1;
            while(j<k){
                int temp=nums[i]+nums[j]+nums[k];
                if(temp==target){
                    return target;
                }else if(temp>target){
                    k--;
                    if(Math.abs(temp-target)<Math.abs(sum-target))
                        sum=temp;
                }else{
                    j++;
                    if(Math.abs(temp-target)<Math.abs(sum-target))
                        sum=temp;
                }
            }
        }
        return sum;
    }
}
__________________________________________________________________________________________________
