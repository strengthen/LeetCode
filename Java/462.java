__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    //用quickselect可以在O(n)时间内找到第k个元素
    public int minMoves2(int[] nums) {
        int sum = 0;
        int median = quickSelect(nums, nums.length /2 + 1, 0, nums.length - 1);
        
        for(int num : nums){
            sum += Math.abs(num - median);
        }
        
        return sum;
    }
    
    public int quickSelect(int[] nums, int k, int start, int end){
        int l = start;
        int r = end;
        int pivot = nums[(l+r) / 2];
        while(l <= r){
            while(nums[l] < pivot) l++;
            while(nums[r] > pivot) r--;
            
            if(l >= r) break;
            swap(nums, l++ , r--);
        }
        //分三种情况，一个是往前，一个正好，一个往后找
        if(l - start + 1 > k) return quickSelect(nums, k, start, l -1);
        if(l - start + 1 == k && l == r)
            return nums[l];
        return quickSelect(nums, k - r - 1 + start, r + 1, end);
    }
    
    public void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        int num=nums[nums.length/2];
        int result=0;
        for(int i=0;i<nums.length;i++) {
        	result+=Math.abs(nums[i]-num);
        }
        return result;
    }
}
__________________________________________________________________________________________________
sample 39808 kb submission
class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        int mid = nums.length / 2;
        int ans = 0;
        for(int i = 0; i < nums.length; i++) {
            ans += Math.abs(nums[i] - nums[mid]);
        }
        return ans;
    }
}