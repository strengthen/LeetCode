__________________________________________________________________________________________________
sample 1 ms submission

public final class Solution {
	public static int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
		int points = 0;
		int sum = 0;
		for (int i = 0; i < k; i++)
			sum += calories[i];
		if (sum < lower)
			points--;
		else if (sum > upper)
			points++;
		for (int i = k; i < calories.length; i++) {
			sum = sum + calories[i] - calories[i - k];
			if (sum < lower)
				points--;
			else if (sum > upper)
				points++;
		}
		return points;
	}

}
__________________________________________________________________________________________________
sample 2 ms submission

public final class Solution {
	public static int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
		int sum = 0;
		int points = 0;
        for(int i=0; i<calories.length;i++) {
        	sum += calories[i];
        	if(i >= k)
        		sum -= calories[i-k];
        	if(i >= k-1) {
        		if(sum < lower) points--;
        		else if(sum > upper) points ++;
        	}
        }
        return points;
    }
}
__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
	public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
int len = calories.length;
		int[] prefixSum = new int[len];
		int res = 0;
		for (int i = 0; i < len; ++i) {
			prefixSum[i] += calories[i] + (i > 0 ? prefixSum[i - 1] : 0);
			if (i - k + 1 >= 0) {
				int pre = i >= k ? prefixSum[i - k] : 0;
				int T = prefixSum[i] - pre;
				if (T < lower) {
					--res;
				}
				if (T > upper) {
					++res;
				}

			}
		}
		return res;
	}
}
