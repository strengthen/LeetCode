__________________________________________________________________________________________________
sample 52 ms submission
class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int a : arr) {
            map.put(a, Math.max(map.getOrDefault(a - difference, 0) + 1, map.getOrDefault(a, 0)));
        }
        int res = 0;
        for (int val : map.values()) {
            res = Math.max(res, val);
        }
        return res;
    }
}
__________________________________________________________________________________________________
82ms
class Solution {
    public int longestSubsequence(int[] arr, int d) {
        int ans = 0;
        Map<Integer, Integer> count = new HashMap<>();
        for (int a : arr) {
            ans = Math.max(ans, count.compute(a, (k, v) -> Math.max(count.getOrDefault(a, 1), 1 + count.getOrDefault(a - d, 0))));
        }
        return ans;
    }
}
__________________________________________________________________________________________________
