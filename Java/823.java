__________________________________________________________________________________________________
sample 11 ms submission
class Solution {
    private static final int mod = 1000000007;
    public int numFactoredBinaryTrees(int[] A) {
        Arrays.sort(A);
        long sum = 1;
        long[] dp = new long[A.length];
        for(int i = 0; i < dp.length; i++) dp[i] = 1;
        for(int i = 1; i < A.length; i++) {
            int j = 0, k = i - 1;
            while(j <= k) {
                long prod = A[j] * (long)A[k];
                if(prod > A[i]) k--;
                else if(prod < A[i]) j++;
                else {
                    dp[i] = (dp[i] + dp[j] * dp[k]) % mod;
                    if(j < k) dp[i] = (dp[i] + dp[j] * dp[k]) % mod;
                    j++;
                    k--;
                }
            }
            sum = (sum + dp[i]) % mod;
        }
        return (int)sum;
    }
}
__________________________________________________________________________________________________
sample 39376 kb submission
class Solution {
    public int numFactoredBinaryTrees(int[] A) {
        int MOD = 1000000007;
        
        Arrays.sort(A);
        HashSet<Integer> numHash = new HashSet<Integer>();
        for(int num: A)
            numHash.add(num);
        
        int total = 0;
        HashMap<Integer, Integer> rtHash = new HashMap<Integer, Integer>();
        for(int i = 0; i < A.length; i++){
            int count  = 1;
            int maxNum = (int)Math.pow(A[i], 0.5);
            for(int j = 0; j < i && A[j] <= maxNum; j++){
            //for(int j = 0; j < i; j++){
                if(A[i] % A[j] == 0){
                    int pair = A[i] / A[j];
                    if(numHash.contains(pair)){
                        int dup = (A[j] == pair) ? 1 : 2;
                        long product = ((long)rtHash.get(A[j])) * ((long)rtHash.get(pair)) % MOD;
                        //product = (product * dup) % MOD
                        if(A[j] != pair) product = (product * 2) % MOD;
                        count =  (int)(((long)count + product) % MOD);
                        //count += (product * dup) % MOD;
                        //count += ((long)(rtHash.get(A[j]) * rtHash.get(pair) * dup)) % MOD;
                        //count = count % MOD;
                    }
                }
            }
            rtHash.put(A[i], count);
            //System.out.println(A[i] + ":" + count);
            total += count% MOD;
            total = total % MOD;
        }
        return total;
    }
}
__________________________________________________________________________________________________
