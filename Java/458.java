__________________________________________________________________________________________________
0ms
import static java.lang.Math.ceil;
import static java.lang.Math.log;
class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return (int) ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
    }
}
__________________________________________________________________________________________________
sample 31548 kb submission
class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int ntests = minutesToTest / minutesToDie;
        int dpcur[] = new int[buckets];
        int dppre[] = new int[buckets];
        int coeff[] = new int[buckets];
        for (int j = 0; j < buckets; j++) {
            dppre[j] = 1;
        }
        for (int i = 0; i < ntests; i++) {
            dpcur[0] = 1;
            for (int j = 1; dpcur[j-1] < buckets; j++) {
                int prev = coeff[0] = 1;
                for (int k = 1; k < j; k++) {
                    int cur = coeff[k];
                    coeff[k] = prev + cur;
                    prev = cur;
                }
                coeff[j] = 1;
                int tested = 0;
                for (int k = 0; k <= j; k++) {
                    tested += dppre[k] * coeff[k];
                }
                dpcur[j] = tested;
            }
            int t[] = dpcur;
            dpcur = dppre;
            dppre = t;
        }
        for (int j = 0; j < buckets; j++) {
            if (dppre[j] >= buckets) {
                return j;
            }
        }
        return -1;
    }
}
__________________________________________________________________________________________________
