__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean isSelfCrossing(int[] x) {
        int len = x.length;
        int[] b = new int[8]; // (top, left, bottom, right) x 2
        int[] signs = {1, -1, -1, 1, 1, -1, -1, 1};
        boolean inside = false;
        int j0 = 0, j3 = 3, j4 = 4, j5 = 5, j6 = 6;
        for (int i = 0, v, d; i < len; i++) {
            v = b[j6] + signs[j0] * x[i];
            d = (v - b[j4]) * signs[j0];
            if (inside && d >= 0) return true;
            if (!inside && d <= 0) {
                inside = true;
                if ((v - b[j0]) * signs[j0] >= 0) b[j5] = b[j3];
            }
            b[j0] = v;
            j0 = j0 == 7 ? 0 : j0 + 1;
            j3 = j3 == 7 ? 0 : j3 + 1;
            j4 = j4 == 7 ? 0 : j4 + 1;
            j5 = j5 == 7 ? 0 : j5 + 1;
            j6 = j6 == 7 ? 0 : j6 + 1;
        }
        return false;
    }
}
__________________________________________________________________________________________________
sample 32856 kb submission
class Solution {
    public boolean isSelfCrossing(int[] x) {
        for (int i = 0; i < x.length; ++i) {
            if (i > 2 && x[i] >= x[i -2] && x[i - 1] <= x[i - 3]) {
                return true;
            }
            
            if (i > 3 && x[i - 1] == x[i - 3] && x[i - 2] <= x[i] + x[i - 4]) {
                return true;
            }
            
            if (i > 4 && x[i - 4] + x[i] >= x[i - 2] && x[i - 2] >= x[i - 4] && x[i - 1] + x[i - 5] >= x[i - 3] && x[i - 3] >= x[i- 1]) {
                return true;
            }
        }
        
        return false;
    }
}
__________________________________________________________________________________________________
