__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int mirrorReflection(int p, int q) {
        int d = q;
        while (true) {
            if (d % p == 0) {
                int count = d / q;
                if (count % 2 == 0) {
                    if ((d / p) % 2 == 0) {
                        continue;
                    } else {
                        return 2;
                    }
                } else {
                    if ((d / p) % 2 == 0) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
            d += q;
        }
    }
}
__________________________________________________________________________________________________
sample 31664 kb submission
class Solution {
    public int mirrorReflection(int p, int q) {
        while (p % 2 == 0 && q % 2 == 0) {
            p = p / 2;
            q = q / 2;
        }
        if (p % 2 == 0) {
            return 2;
        } else if (q % 2 == 0) {
            return 0;
        } else {
            return 1;
        }
    }
}
__________________________________________________________________________________________________
