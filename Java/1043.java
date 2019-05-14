__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int maxSumAfterPartitioning(int[] A, int K) {        
        int[] maxtable = new int[A.length];
        maxtable[0] = A[0];
        for(int i = 1; i < maxtable.length; ++i) {
            maxtable[i] = Math.max(maxtable[i-1], A[i]);
        }
        
        int[] dp = new int[A.length];
        Arrays.fill(dp, -1);
        
        return find(A, maxtable, A.length-1, K, dp);
    }
    
    
    int find(int[] A, int[] maxtable, int j, int k, int[] dp) {
        if(dp[j] != -1) return dp[j];
        
        int max = 0;
        if(j-k >= 0) {
            
            //for(int t = j-k; t <= j-1; ++t) {
            int maxitem = A[j];
            for(int t = j-1; t >= j-k; --t) {
                int prev = find(A, maxtable, t, k, dp);

                max = Math.max(max, prev + (j-t) * maxitem);
                maxitem = Math.max(maxitem, A[t]);
            }
        }
        else {
            max = (j+1) * maxtable[j];
        }
        
        dp[j] = max;
        return dp[j];
    }
}
__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    // Let k be 2
    // Focus on "growth" of the pattern
    // Define A' to be a partition over A that gives max sum
    
    // #0
    // A = {1}
    // A'= {1} => 1
    
    // #1
    // A = {1, 2}
    // A'= {1}{2} => 1 + 2 => 3 X
    // A'= {1, 2} => {2, 2} => 4 AC
        
    // #2
    // A = {1, 2, 9}
    // A'= {1, 2}{9} => {2, 2}{9} => 4 + 9 => 13 X
    // A'= {1}{2, 9} => {1}{9, 9} => 1 + 18 => 19 AC
    
    // #3
    // A = {1, 2, 9, 30}
    // A'= {1}{2, 9}{30} => {1}{9, 9}{30} => 19 + 30 => 49 X
    // A'= {1, 2}{9, 30} => {2, 2}{30, 30} => 4 + 60 => 64 AC
    
    // Now, label each instance. Use F1() to represent how A is partitioned and use F2() to represent
    // the AC value of that partition. F2() is the dp relation we are looking for.
    
    // #4
    // A = {1, 2, 9, 30, 5}
    // A'= F1(#3){5} => F2(#3) + 5 => 69 X
    // A'= F1(#2){30, 5} => F2(#2) + 30 + 30 => 79 AC
    // => F2(#4) = 79
    
    public int maxSumAfterPartitioning1(int[] A, int K) {
        int N = A.length, dp[] = new int[N];
        for (int i = 0; i < N; ++i) {
            int curMax = 0;
            for (int k = 1; k <= K && i - k + 1 >= 0; ++k) {
                curMax = Math.max(curMax, A[i - k + 1]);
                dp[i] = Math.max(dp[i], (i >= k ? dp[i - k] : 0) + curMax * k);
            }
        }
        return dp[N - 1];
    }
    
    
    // MORE INTUITIVE CODE
    public int maxSumAfterPartitioning(int[] A, int K) {
         int[] dp = new int[A.length];
         int max = 0;
        // FOR THE FIRST K ELEMENTS, OPTIMAL SOLUTION IS TO PARTITION K ELEMENTS TOGETHER TO
        // MAXIMIZE THE SUM (AS MAXIMUM NUMBER IS REPLICATED TO ALL K POSITIONS)
         for(int i=0;i<K;i++){
             max = Math.max(max, A[i]);
             dp[i] = max * (i+1);
         }
         
        // FOR THE REST OF THE ELEMENTS WE CAN TRY PARTITIONS OF SIZE 1...K FROM THEH RIGHT
         max = 0;
         for(int i=K; i<A.length; i++){
             max = A[i];
             for(int j=i;j>i-K;j--){
                 max = Math.max(max, A[j]);
                 dp[i] = Math.max(max*(i-j+1)+dp[j-1], dp[i]);
             }
         }
        
         return dp[A.length-1];
    }
}
__________________________________________________________________________________________________
× Close
sample 4 ms submission
class Solution {
    
    int memo[];
    public int maxSumAfterPartitioning(int[] A, int K) {
        memo = new int[A.length];
        Arrays.fill(memo, -1);
        return helper(A, K, 0);
    }
    
    
    
    int helper(int[] A, int K, int pos) {
        if(pos == A.length) {
            return 0;
        }
        if(memo[pos] != -1) {
            return memo[pos];
        }
        
        int max = 0;
        int res = 0;
        for (int i=pos, j=1; i<pos + K && i < A.length; i++, j++) {
            max = Math.max(A[i], max);
            res = Math.max(res, max * j + helper(A, K, i + 1));
        }
        
        memo[pos] = res;
        return res;
    }
}