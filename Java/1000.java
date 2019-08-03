__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int mergeStones(final int[] stones, final int K) {
        final int N = stones.length;
        
        if ((N - 1) % (K - 1) + 1 != 1) {
            return -1;
        }
        
        final int[] partialSums = new int[N+1];
        for (int end = 1; end <= N; ++end) {
            partialSums[end] = partialSums[end-1] + stones[end-1];
        }
        
        final int[][] memopad = new int[N+1][];
        // memopad[length][start] will be the minimum cost to merge the piles
        // from stones[start] through stones[start+length-1] into the minimum
        // possible number of piles, namely (length - 1) % (K - 1) + 1.
        
        memopad[1] = new int[N];
        // memopad[1][start] == 0 for any possible start
        
        for (int length = 2; length <= N; ++length) {
            final boolean needToMerge = ((length - 1) % (K - 1) + 1 == 1);
            memopad[length] = new int[N - length + 1];
            for (int start = 0, end = length; end <= N; ++start, ++end) {
                int result = memopad[length-1][start+1];
                for (int mid = start + K; mid < end; mid += K - 1) {
                    result = Math.min(result, memopad[mid-start][start] + memopad[end-mid][mid]);
                }
                memopad[length][start] =
                    result + (needToMerge ? partialSums[end] - partialSums[start] : 0);
            }
        }
        
        return memopad[N][0];
    }
}
__________________________________________________________________________________________________
sample 35624 kb submission
class Solution {
    public int mergeStones(int[] stones, int K) {
        int n = stones.length;
        if((n-1) % (K-1) >0){
            return -1;
        }
        int[] ss = new int[n+1];
        for(int i = 1;i<=n;i++){
            ss[i] = ss[i-1] + stones[i-1];
        }
        
        int[][] f = new int[n][n];
        for(int len=K;len<=n;len++ ){
            for(int i = 0;i<= n-len;i++){
                // len = j-i+1
                int j = i+len-1;
                f[i][j] = Integer.MAX_VALUE;
                for(int mid = i; mid <j;mid +=K-1){
                    f[i][j] = Math.min(f[i][j], f[i][mid] + f[mid+1][j]);
                }
                if((j-i)%(K-1) ==0){
                    f[i][j] += ss[j+1]-ss[i];
                }
                
            }
        }
        return f[0][n-1];
    }
}
__________________________________________________________________________________________________
