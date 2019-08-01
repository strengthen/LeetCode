__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int findMinMoves(int[] machines) {
        if (machines == null || machines.length <= 1) {
            return 0;
        }
        int sum = 0;
        for (int machine : machines) {
            sum += machine;
        }
        if (sum % machines.length != 0) {
            return -1;
        }
        int target = sum / machines.length;
        int cur = 0, max = 0;
        for (int machine : machines) {
            cur += machine - target; //load-avg is "gain/lose"
            max = Math.max(Math.max(max, Math.abs(cur)), machine - target);
        }
        return max;
    }
}
__________________________________________________________________________________________________
sample 34876 kb submission
class Solution {
    public int findMinMoves(int[] machines) {
        int sum = Arrays.stream(machines).sum(), n = machines.length;

		if (sum % n != 0)
			return -1;

		int avg = sum / n, cn = 0, ans = 0;

		for (int m : machines) {
			cn += m - avg;
			ans = Math.max(ans, Math.max(Math.abs(cn), m - avg));
		}

		return ans;
    }
}
__________________________________________________________________________________________________
