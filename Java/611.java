__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int triangleNumber(int[] nums) {
        int count = 0;
        
        if(nums == null || nums.length < 3)
            return count;
        
        Arrays.sort(nums);
        int n = nums.length;
        
        for(int i=n-1; i>=2; i--)
        {
            int l=0, r=i-1;
            
            while(l<r)
            {
                if(nums[l] + nums[r] > nums[i])
                {
                    count += r-l;
                    r--;
                }
                else
                    l++;
            }
        }
        
        return count;
    }
}
__________________________________________________________________________________________________
sample 36896 kb submission
class Solution {
    public int triangleNumber(int[] nums) {
        int count;
        
        count = 0;
        
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            if (nums[i] == 0) {
                continue;
            }
            
            for (int j = i + 1, k = j + 1; j < nums.length - 1; j++) {
                while (k < nums.length && nums[i] + nums[j] > nums[k]) {
                    k++;
                }
                
                count += (k - j - 1);
            }
        }
        
        return (count);
    }
}
__________________________________________________________________________________________________
