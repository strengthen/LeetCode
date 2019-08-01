__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
	public int totalHammingDistance(int[] nums) {
		if (nums == null || nums.length <= 0) return 0;
		int total = 0;
		for (int i = 0; i < 32; i++) {
			int ones = numOnes(nums, i);
			total += (ones * (nums.length-ones));
		}
		return total;
	}
	
	private int numOnes(int[] nums, int pos) {
		int mask = 1 << pos;
		int numOnes = 0;
		for (int n : nums) {
			if ((mask & n) > 0) numOnes++;
 		}
		return numOnes;
	}
}
__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int totalHammingDistance(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int total = 0;
        for (int i = 0; i < 32; i++) {
            total += TotalOneBitDistance(nums, i);
        }
        return total;
    }
    
    public int TotalOneBitDistance(int[] nums, int i) {
        int zeros = 0;
        for (int n : nums) {
            if ((n >> i & 1) == 0) zeros++;
        }
        return zeros * (nums.length - zeros);
    }
}
__________________________________________________________________________________________________
sample 37676 kb submission
class Solution {
    // dist between nums, n*n*32
    // by bits, 32 * n, group dists
    public int totalHammingDistance(int[] nums) {
        int res = 0;
        if (nums == null || nums.length == 0) {
            return res;
        }
        int maxValue = Arrays.stream(nums).max().getAsInt();
        for (int i = 0; i < 32; i++) {
            if ((1 << i) > maxValue) {
                break;
            }
            int zs = 0;
            for (int num : nums) {
                if (((1 << i) & num) == 0) {
                    zs += 1;
                }
            }
            res += zs * (nums.length - zs);
        }
        return res;
    }
}