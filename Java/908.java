__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int smallestRangeI(int[] A, int K) {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for (int num : A) {
            if (num > max) {
                max = num;
            }
            if (num < min) {
                min = num;
            }
        }
        return Math.max(0, max - min - 2 * K);
    }
}
__________________________________________________________________________________________________
sample 37188 kb submission
class Solution {
    public int smallestRangeI(int[] A, int K) {
        int aMax = Arrays.stream(A).max().getAsInt();
        int aMin = Arrays.stream(A).min().getAsInt();

        if (aMax - aMin <= 2 * K) {
            return 0;
        } else {
            return aMax - aMin - 2 * K;
        }
    }
}
__________________________________________________________________________________________________
