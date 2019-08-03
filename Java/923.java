__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int threeSumMulti(int[] A, int target) {
        int MOD = 1_000_000_007;
        long[] count = new long[101];
        for (int x: A)
            count[x]++;

        long ans = 0;

        // All different
        for (int x = 0; x <= 100; ++x)
            for (int y = x+1; y <= 100; ++y) {
                int z = target - x - y;
                if (y < z && z <= 100) {
                    ans += count[x] * count[y] * count[z];
                    ans %= MOD;
                }
            }

        // x == y != z
        for (int x = 0; x <= 100; ++x) {
            int z = target - 2*x;
            if (x < z && z <= 100) {
                ans += count[x] * (count[x] - 1) / 2 * count[z];
                ans %= MOD;
            }
        }

        // x != y == z
        for (int x = 0; x <= 100; ++x) {
            if (target % 2 == x % 2) {
                int y = (target - x) / 2;
                if (x < y && y <= 100) {
                    ans += count[x] * count[y] * (count[y] - 1) / 2;
                    ans %= MOD;
                }
            }
        }

        // x == y == z
        if (target % 3 == 0) {
            int x = target / 3;
            if (0 <= x && x <= 100) {
                ans += count[x] * (count[x] - 1) * (count[x] - 2) / 6;
                ans %= MOD;
            }
        }

        return (int) ans;
    }
}
__________________________________________________________________________________________________
sample 37732 kb submission
class Solution {
    public int threeSumMulti(int[] A, int target) {
        Map<Integer, Integer> numCounts = new HashMap<>();
        for (int i = 0; i < A.length; i++) {
            numCounts.compute(A[i], (k, v) -> v == null ? 1 : v + 1);
        }

        int[] uniqueA = numCounts.keySet().stream().mapToInt(v -> v).toArray();
        Arrays.sort(uniqueA);

        long result = 0L;

        // 3 different values
        for (int i = 0; i < uniqueA.length - 2; i++) {
            int twoSumTarget = target - uniqueA[i];

            int lo = i + 1;
            int hi = uniqueA.length - 1;
            while (lo < hi) {
                if (uniqueA[lo] + uniqueA[hi] < twoSumTarget) {
                    lo++;
                } else if (uniqueA[lo] + uniqueA[hi] > twoSumTarget) {
                    hi--;
                } else {
                    result += numCounts.get(uniqueA[i]) * numCounts.get(uniqueA[lo]) * numCounts.get(uniqueA[hi]);
                    lo++;
                    hi--;
                }
            }
        }

        // 2 different values
        for (int i = 0; i < uniqueA.length; i++) {
            if (numCounts.get(uniqueA[i]) >= 2) {
                int oneSumTarget = target - uniqueA[i] * 2;
                if (oneSumTarget != uniqueA[i] && Arrays.binarySearch(uniqueA, oneSumTarget) >= 0) {
                    int countTwoSame = numCounts.get(uniqueA[i]);
                    result += countTwoSame * (countTwoSame - 1) / 2 * numCounts.get(oneSumTarget);
                }
            }
        }

        // one value
        if (target % 3 == 0) {
            int theOneNum = target / 3;
            if (Arrays.binarySearch(uniqueA, theOneNum) >= 0) {
                int countTheOneNum = numCounts.get(theOneNum);
                if (countTheOneNum >= 3) {
                    result += (long) countTheOneNum * (countTheOneNum - 1) * (countTheOneNum - 2) / 6;
                }
            }
        }

        return (int) (result % (1000000000 + 7));
    }
}
__________________________________________________________________________________________________
