__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        
		int head = 0;
		int tail = nums.length-1;
		int flag = 0;
		for(int i = 0 ; i < nums.length ; ++ i)
			if(nums[i] < nums[head])
			{
				while(head >= 0 && nums[i] < nums[head])
					head --;
				if(head < 0)
					break;
				flag = 1;
			}
			else if(flag == 0)
				head = i;
		
		flag = 0;
		for(int i = nums.length-1 ; i >= 0 ; -- i)
			if(nums[i] > nums[tail])
			{
				while(tail < nums.length && nums[i] > nums[tail])
					tail ++;
				if(tail == nums.length)
					break;
				flag = 1;
			}
			else if(flag == 0)
				tail = i;
		return Math.max(tail - head - 1 , 0 );
    }
}
__________________________________________________________________________________________________
sample 38936 kb submission
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        if(nums == null || nums.length == 0){
            return -1;
        }

        int start = 0, end = 0;
        int min = nums[nums.length - 1];
        int max = nums[0];

        for(int i = 1; i < nums.length; i++){
            if(nums[i] < max){
                end = i;
            }
            max = Math.max(max, nums[i]);
        }

        for(int i = nums.length - 1; i >= 0; i--){
            if(nums[i] > min){
                start = i;
            }
            min = Math.min(min, nums[i]);
        }
        return start != end ? end - start + 1 : 0;
    }
}
__________________________________________________________________________________________________
