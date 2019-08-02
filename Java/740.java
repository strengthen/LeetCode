__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int deleteAndEarn(int[] nums) {
        int[] count = new int[10001];
        for (int x: nums) count[x]++;
        int avoid = 0, using = 0, prev = -1;

        for (int k = 0; k <= 10000; ++k) if (count[k] > 0) {
            int m = Math.max(avoid, using);
            if (k - 1 != prev) {
                using = k * count[k] + m;
                avoid = m;
            } else {
                using = k * count[k] + avoid;
                avoid = m;
            }
            prev = k;
        }
        return Math.max(avoid, using);
    }
}
__________________________________________________________________________________________________
sample 34680 kb submission
class Solution {
public int deleteAndEarn(int[] nums) {
        Map<Integer, Integer> numToSum = new HashMap<>();
        for (int num : nums) {
            numToSum.put(num, numToSum.getOrDefault(num, 0) + num);
        }
        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(numToSum.entrySet());
        list.sort((e1, e2) -> e2.getKey() - e1.getKey());
        int[] dp = new int[list.size()];
        return helper(list, 0, dp);

    }

    private int helper(List<Map.Entry<Integer, Integer>> list, int idx, int[] dp) {
        if (idx == list.size() - 1) {
            // this is the end of the list and it's valid to take it based on our logic
            return list.get(idx).getValue();
        }
        if (idx >= list.size()) {
            return 0;
        }
        if (dp[idx] != 0) {
            return dp[idx];
        }
        Map.Entry<Integer, Integer> cur = list.get(idx);
        // option 1: take it
        int sum1;
        Map.Entry<Integer, Integer> next = list.get(idx + 1);
        if (cur.getKey() == next.getKey() + 1) {
            // we cannot take the next one
            sum1 = cur.getValue() + helper(list, idx + 2, dp);
        } else {
            // we can take next because it will not be deleted
            sum1 = cur.getValue() + helper(list, idx + 1, dp);
        }
        // option 2: not taking it
        int sum2 = helper(list, idx + 1, dp);
        int max = Math.max(sum1, sum2);
        dp[idx] = max;
        return max;
    }
}
__________________________________________________________________________________________________
