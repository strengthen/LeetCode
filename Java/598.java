__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    // find minimum i and j from ops, then multiply
    public int maxCount(int m, int n, int[][] ops) {
        int iMin = m;
        int jMin = n;
        for (int[] op : ops) {
            if (op[0] < iMin) iMin = op[0];
            if (op[1] < jMin) jMin = op[1];
        }
        return iMin * jMin;
    }
}
__________________________________________________________________________________________________
sample 35104 kb submission
class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        if (ops == null || ops.length == 0) return m*n;
        Arrays.sort(ops, (o1, o2) -> Integer.compare(o1[0], o2[0]));
        int r = ops[0][0];
        Arrays.sort(ops, (o1, o2) -> Integer.compare(o1[1], o2[1]));
        int c = ops[0][1];
        return r * c;
    }
}
__________________________________________________________________________________________________
