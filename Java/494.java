__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        if(nums.length == 0) return 0;

        int sum = 0;
        for(int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        if(sum < S) return 0; // if I add them like crazy, I still cannot get S
        if( ( sum - S )  % 2 != 0) return 0;

        int target = (sum - S) / 2;

        int[] cache = new int[target+1];
        cache[0] = 1;
        for(int i = 0; i < nums.length; i++) {
            int curNum = nums[i];
            for(int j = cache.length-1; j>=curNum; j--) {
                cache[j] += cache[j-curNum];
            }
        }
        return cache[cache.length-1];
    }
}
__________________________________________________________________________________________________
sample 34532 kb submission
class Solution {
    private int[] nums;
    
	public int findTargetSumWays(int[] nums, int S) {
		int max = IntStream.of(nums).map(Math::abs).sum();
		if (S > max || S < -max) return 0;
		this.nums = nums;
		return findTargetSumWays(S, 0);
	}

	private int findTargetSumWays(int S, int i) {
		if (i == nums.length) return S == 0 ? 1 : 0;
		return findTargetSumWays(S + nums[i], i + 1) +
			findTargetSumWays(S - nums[i], i + 1);
	}
}
__________________________________________________________________________________________________
