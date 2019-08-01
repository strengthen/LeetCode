__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int findLongestChain(int[][] pairs) {
        if (pairs == null)
            return 0;
        int len = pairs.length;
        if (len < 2)
            return len;
        qsort(pairs, 0, len - 1);
        int sum = 1;
        int end = pairs[0][1];
        for (int i = 1; i < len; i++) {
            if (pairs[i][0] > end) {
                sum++;
                end = pairs[i][1];
            }
        }
        return sum;
    }

    private void qsort(int[][] pairs, int begin, int end) {
        if (begin >= end)
            return;
        int key = pairs[begin][1];
        int[] keyPair = pairs[begin];
        int i = begin, j = end;
        while(i < j) {
            while(i < j && key <= pairs[j][1])
                --j;
            pairs[i] = pairs[j];
            while(i < j && key >= pairs[i][1])
                ++i;
            pairs[j] = pairs[i];
        }
        pairs[i] = keyPair;
        qsort(pairs, begin, i - 1);
        qsort(pairs, i + 1, end);
    }
}
__________________________________________________________________________________________________
sample 37340 kb submission
class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (a, b) -> a[0] - b[0]);
        int N = pairs.length;
        int[] dp = new int[N];
        Arrays.fill(dp, 1);

        for (int j = 1; j < N; ++j) {
            for (int i = 0; i < j; ++i) {
                if (pairs[i][1] < pairs[j][0])
                    dp[j] = Math.max(dp[j], dp[i] + 1);
            }
        }

        int ans = 0;
        for (int x: dp) if (x > ans) ans = x;
        return ans;
    }
}
__________________________________________________________________________________________________
