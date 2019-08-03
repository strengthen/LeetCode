__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int atMostNGivenDigitSet(String[] D, int N) {
        if (D == null)
        	return 0;
        int n = D.length;
        if (n == 0)
        	return 0;
        boolean[] dig = new boolean[10];
        int i, j, k, m;
        for (i = 0; i < n; i++) {
        	int c = (int)(D[i].charAt(0)) - (int)'0';
        	dig[c] = true;
        }
        m = 0;
        for (i = 1; i < 10; i++)
        	if (dig[i])
        		m++;
        int[] dp1 = new int[12];
        dp1[0] = 1;
        for (i = 1; i < 12; i++)
        	dp1[i] = dp1[i-1] * m;
        int[] ndig = new int[20];
        int res1 = 0, res2;
        k = 1;
        while (N != 0) {
        	if (N >= 10)
        		res1 += dp1[k];
        	ndig[k] = N % 10;
        	N /= 10;
        	k++;
        }
        res2 = res1;
        while (--k >= 1) {
        	int c = 1;
        	while (c < ndig[k]) {
        		if (dig[c]) {
        			res2 += dp1[k-1];
        		}
        		c++;
        	}
        	if (!dig[ndig[k]])
        		break;
        	if ((k == 1) && (dig[c]))
        		res2 += dp1[0];
        }
        return res2;        
    }
}
__________________________________________________________________________________________________
sample 35456 kb submission
class Solution {
    public int atMostNGivenDigitSet(String[] D, int N) {
        List<Integer> digits = new ArrayList<>();
        for (int n = N; n > 0; n /= 10) {
            digits.add(0, n % 10);
        }
        int prefix = 0, ans = 0, num = 0, p = 0;
        boolean can = true;
        for (int cur : digits) {
            if (p > 0) {
                ans += p;
                p *= D.length;
            } else p = D.length;
            
            int next = prefix * 10 + cur;
            num *= D.length;
            boolean can2 = false;
            if (can)
            for (String d : D) {
                if (prefix * 10 + Integer.valueOf(d) < next) num++;
                if (Integer.valueOf(d) == cur) can2 = true;
            }
            if (!can2) can = false;
            prefix = next;
            // System.out.println(prefix);
        }
        // System.out.println(ans);
        if (can) ans++;
        return ans + num;
    }
}
__________________________________________________________________________________________________
