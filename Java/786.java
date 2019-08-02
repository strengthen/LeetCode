__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int[] kthSmallestPrimeFraction(int[] primes, int K) {
        double lo = 0, hi = 1;
        int[] ans = new int[]{0, 1};

        while (hi - lo > 1e-9) {
            double mi = lo + (hi - lo) / 2.0;
            int[] res = under(mi, primes);
            if (res[0] < K) {
                lo = mi;
            } else {
                ans[0] = res[1];
                ans[1] = res[2];
                hi = mi;
            }
            if (res[0] == K) return ans;
        }
        return ans;
    }

    public int[] under(double x, int[] primes) {
        // Returns {count, numerator, denominator}
        int numer = 0, denom = 1, count = 0, i = -1;
        for (int j = 1; j < primes.length; ++j) {
            // For each j, find the largest i so that primes[i] / primes[j] < x
            // It has to be at least as big as the previous i, so reuse it ("two pointer")
            while (primes[i+1] < primes[j] * x) ++i;

            // There are i+1 fractions: (primes[0], primes[j]),
            // (primes[1], primes[j]), ..., (primes[i], primes[j])
            count += i+1;
            if (i >= 0 && numer * primes[j] < denom * primes[i]) {
                numer = primes[i];
                denom = primes[j];
            }
        }
        return new int[]{count, numer, denom};
    }
}
__________________________________________________________________________________________________
sample 36112 kb submission
class Solution {
    public int[] kthSmallestPrimeFraction(int[] A, int K) {
        int n = A.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> {
            Double s1 = 1.0d * A[o1[0]] / A[o1[1]];
            Double s2 = 1.0d * A[o2[0]] / A[o2[1]];
            return s1.compareTo(s2);
        } );
        
        for (int i = 0; i < n-1; i++ ) {
            pq.add(new int[]{i, n-1});
        }
        
         for (int i = 0; i < K-1; i++) {
            int[] pop = pq.remove();
             if (pop[1] - 1 > pop[0]) {
                pop[1]--;
                pq.add(pop);
            }
        }

        int[] peek = pq.peek();
        return new int[]{A[peek[0]], A[peek[1]]};
    }
}
__________________________________________________________________________________________________
