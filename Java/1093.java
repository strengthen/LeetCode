__________________________________________________________________________________________________
class Solution {
    public double[] sampleStats(int[] count) {
        int total = 0, mode = 0;
        double median = 0, min = -1, max = 0, avg = 0, sum = 0;
        for (int i = 0; i < 256; ++i) {
            if (count[i] > 0) {
                total += count[i];
                if (min < 0) min = i;
                max = i;
                sum += i * count[i];
                if (count[i] > count[mode]) mode = i;
            }
        }
        avg = sum / total;
        if (total == 1) median = sum; // single element.
        int m1 = total / 2 + total % 2, m2 = total / 2 + 1; // m1-th and m2-th items are medians.
        for (int i = 0, cnt = 0; total > 1 && i < 256; ++i) { // more than 1 elements.
            if (cnt < m1 && cnt + count[i] >= m1) // find m1-th item.
                median += i / 2.0d; // add its half.
            if (cnt < m2 && cnt + count[i] >= m2) // find m2-th item.
                median += i / 2.0d; // add its half.
            cnt += count[i];
        }
        return new double[]{min, max, avg, median, mode};
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
