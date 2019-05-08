__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    Map<Integer, Integer> map = new HashMap();
    public int climbStairs(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (map.get(n) == null)
            map.put(n, climbStairs(n-1) + climbStairs(n-2));

        return map.get(n);
    }
}
__________________________________________________________________________________________________
sample 36024 kb submission
class Solution {
    public int climbStairs(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else {
            return climbStairs(n - 1) + climbStairs(n - 2);
        }
    }
}
__________________________________________________________________________________________________
