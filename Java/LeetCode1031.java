__________________________________________________________________________________________________
1ms
class Solution {
    public int maxSumTwoNoOverlap(int[] A, int L, int M) {
        int n = A.length;
        int[] l = get(A, L), m = get(A, M);
        int[] maxAfterL = get(l), maxAfterM = get(m);
        int re = 0;
        for(int i = 0; i < l.length; i++) {
            if(i + L >= maxAfterM.length) break;
            re = Math.max(l[i] + maxAfterM[i+L], re);
        }
        for(int i = 0; i < m.length; i++) {
            if(i + M >= maxAfterL.length) break;
            re = Math.max(m[i] + maxAfterL[i+M], re);
        }
        return re;
    }
    int[] get(int[] A, int l) {
        int[] re = new int[A.length - l + 1];
        int sum = 0;
        for(int i = 0; i < l; i++) sum += A[i];
        re[0] = sum;
        for(int i = l; i < A.length; i++) {
            sum += (A[i] - A[i-l]);
            re[i-l+1] = sum;
        }
        return re;
    }
    int[] get(int[] l) {
        int[] re = new int[l.length];
        int max = re[re.length - 1];
        for(int i = re.length - 1; i >= 0; i--) {
            max = Math.max(l[i], max);
            re[i] = max;
        }
        return re;
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public int maxSumTwoNoOverlap(int[] A, int L, int M) {
        int res = 0, Lsum = 0, Lmax = 0, Msum = 0, Mmax = 0;
        for (int i = 0; i < A.length; ++i) {
            Msum += A[i];
            if (i - M >= 0) Msum -= A[i - M];
            if (i - M >= 0) Lsum += A[i - M];
            if (i - M - L >= 0) Lsum -= A[i - L - M];
            Lmax = Math.max(Lmax, Lsum);
            res = Math.max(res, Lmax + Msum);
        }
        Lsum = Lmax = Msum = Mmax = 0;
        for (int i = 0; i < A.length; ++i) {
            Lsum += A[i];
            if (i - L >= 0) Lsum -= A[i - L];
            if (i - L >= 0) Msum += A[i - L];
            if (i - M - L >= 0) Msum -= A[i - L - M];
            Mmax = Math.max(Mmax, Msum);
            res = Math.max(res, Mmax + Lsum);
        }
        return res;
    }
}
__________________________________________________________________________________________________
3ms
class Solution {
    public int maxSumTwoNoOverlap(int[] A, int L, int M) {
        int acc = 0, n = A.length;
        int [] accs = new int [n + 1];
        for(int i = 0; i < n; ++i) {
            acc += A[i];
            accs[i + 1] = acc;
        }
        n = accs.length;
        int ans = Integer.MIN_VALUE;
        for(int i = L; i < n; ++i) {
            int lacc = accs[i] - accs[i - L];
            int macc = Integer.MIN_VALUE;
            for(int j = M; j <= i - L; ++j) {
                macc = Math.max(macc, accs[j] - accs[j - M]);
            }
            for(int j = i; j + M < n; ++j) {
                macc = Math.max(macc, accs[j + M] - accs[j]);
            }
            ans = Math.max(ans, lacc + macc);
        }
        return ans;
    }    
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________

__________________________________________________________________________________________________